#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int i, j, n1, m1, n2, m2, c;

int** MatrixGenerate(int, int);

int determinant(int**, int, int);

int main()
{
    srand(time(NULL));

    printf("Enter count rows for matrix1: ");
    scanf("%d", &n1);
    printf("Enter count columns for matrix1: ");
    scanf("%d", &m1);
    printf("Enter count rows for matrix2: ");
    scanf("%d", &n2);
    printf("Enter count columns for matrix2: ");
    scanf("%d", &m2);

    int** matrix1 = MatrixGenerate(n1, m1);
    int** matrix2 = MatrixGenerate(n2, m2);

    if (n1 != m2) 
    {
        printf("Error: matrix multiplication is not possible");
        return 1;
    }

    int** resultMatrix = MatrixGenerate(n1, m2);

    // умножение
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            resultMatrix[i][j] = 0;
            for (int c = 0; c < m1; c++) 
            {
                resultMatrix[i][j] += matrix1[i][c] * matrix2[c][j];
            }
        }
    }
    // вывод первой матрицы
    printf("One matrix:\n");
    for (i = 0; i < n1; i++)  // цикл по строкам
    {
        printf("[ ");
        for (j = 0; j < m1; j++)  // цикл по столбцам
        {
            printf("%4d ", matrix1[i][j]); // 5 знакомест под элемент массива
        }
        printf("]\n");
    }
    printf("\n");

    // вывод второй матрицы
    printf("Two matrix:\n");
    for (i = 0; i < n2; i++)  // цикл по строкам
    {
        printf("[ ");
        for (j = 0; j < m2; j++)  // цикл по столбцам
        {
            printf("%4d ", matrix2[i][j]); // 5 знакомест под элемент массива
        }
        printf("]\n");
    }
    printf("\n");
    // вывод третьей матрицы
    printf("Multiplication matrix:\n");
    for (i = 0; i < n1; i++)  // цикл по строкам
    {
        printf("[ ");
        for (j = 0; j < m2; j++)  // цикл по столбцам
        {
            printf("%4d ", resultMatrix[i][j]); // 5 знакомест под элемент массива
        }
        printf("]\n");
    }
    printf("\n");

    //вывод детерминантов
    printf("Det matrix number one: %d\n", determinant(matrix1, n1, m1));
    printf("Det matrix number two: %d\n", determinant(matrix2, n2, m2));
    printf("Det matrix number three: %d", determinant(resultMatrix, n1, m2));

    for (int i = 0; i < m1; i++) 
    {
        free(matrix1[i]);
    }
    free(matrix1);
    for (int i = 0; i < m2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);
    for (int i = 0; i < n1; i++)
    {
        free(resultMatrix[i]);
    }
    free(resultMatrix);

    return 0;
}
int** MatrixGenerate(int n, int m)
{
    //выделяем память для хранение указателей на строки
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = (int*)malloc(m * sizeof(int));
    }
    // заполнение элементов первой матрицы рандомными числами
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 201 + (-100);
        }
    }
    return matrix;

}
int determinant(int** matrix, int n, int m)
{
    int det = 0;

    if (n == 1) 
    {
        return matrix[0][0];
    }

    if (n == 2) 
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    for (int i = 0; i < n; i++)
    {
        int** sub_matrix = (int**)malloc((n - 1) * sizeof(int*));
        for (int j = 0; j < n - 1; j++) 
        {
            sub_matrix[j] = (int*)malloc((m - 1) * sizeof(int));
        }

        int c = 0;
        for (int j = 1; j < n; j++) 
        {
            int t = 0;
            for (int k = 0; k < m; k++) 
            {
                if (k != i)
                {
                    sub_matrix[j - 1][t] = matrix[j][k];
                    t++;
                }
            }
        }

        int sign = (i % 2 == 0) ? 1 : -1;
        det += sign * matrix[0][i] * determinant(sub_matrix, n - 1, m - 1);

        for (int j = 0; j < n - 1; j++) 
        {
            free(sub_matrix[j]);
        }
        free(sub_matrix);
    }

    return det;
}