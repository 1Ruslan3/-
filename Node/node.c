#include <stdio.h>
#include <stdlib.h>

// Структура для элемента списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Функция для добавления элемента в конец списка
void append(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    }
    else {
        Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
}

// Функция для удаления элемента из списка
void delete(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Функция для печати списка
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Функция для добавления элемента в любое место в списке
void insertNode( Node** head, int newData, int position) {
     Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = newData;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
         Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range\n");
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Поиск элемента списка по его значению 
int searchElement(Node* head, int value) {
    Node* current = head;
    int index = 0;

    while (current != NULL) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

// Пример использования
int main() {
    Node* head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 7);
    append(&head, 5);
    insertNode(&head, 6, 6);
    


    printf("Initial list: \n");
    printList(head);
    printf("%d\n", searchElement(head, 7));

    delete(&head, 1);

    printList(head);

    return 0;
}
