#include <stdio.h>
#include <stdlib.h>

// Структура для представления узла дерева
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Функция для создания нового узла дерева
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Функция для построения дерева из скобочного выражения
struct Node* buildTree(char expr[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    struct Node* root = NULL;
    int index = -1;

    // Поиск положения корня
    if (expr[start] >= 'A' && expr[start] <= 'Z') {
        root = newNode(expr[start]);
        index = start + 1;
    }
    else {
        return NULL;
    }

    // Поиск точки разделения подвыражений
    int bracketCount = 0;
    for (int i = start + 1; i <= end; i++) {
        if (expr[i] == '(') {
            bracketCount++;
        }
        else if (expr[i] == ')') {
            bracketCount--;
        }

        if (bracketCount == 0) {
            index = i + 1;
            break;
        }
    }

    // Построение левого поддерева
    root->left = buildTree(expr, start + 2, index - 3);

    // Построение правого поддерева
    root->right = buildTree(expr, index + 2, end - 1);

    return root;
}

// Функция для печати дерева в файл
void printTreeToFile(struct Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    fprintf(file, "%c\n", root->data);

    if (root->left != NULL || root->right != NULL) {
        fprintf(file, "/");
    }

    if (root->left != NULL) {
        fprintf(file, " ");
        printTreeToFile(root->left, file);
    }

    if (root->right != NULL) {
        fprintf(file, "| ");
        printTreeToFile(root->right, file);
    }
}

int main(int argc, char* argv[]) {
    char expr[100];
    FILE* inputFile;
    FILE* outputFile;

    if (argc < 3) {
        printf("Usage: %s input_filename output_filename\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    int numExpressions = 0;
    while (fgets(expr, sizeof(expr), inputFile)) {
        numExpressions++;
        printf("Expression %d: %s", numExpressions, expr);
        struct Node* root = buildTree(expr, 0, strlen(expr) - 1);

        char outputFilename[100];
        sprintf(outputFilename, "%s%d.txt", argv[2], numExpressions);
        outputFile = fopen(outputFilename, "w");
        if (outputFile == NULL) {
            printf("Error opening output file\n");
            return 1;
        }

        printTreeToFile(root, outputFile);
        fclose(outputFile);
        printf("Tree written to %s\n", outputFilename);
    }

    fclose(inputFile);
    return 0;
}