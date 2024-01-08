#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long factorial(unsigned long long n);

int value, accumulator, count, primelity_flag;

unsigned long long i;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Invalid arguments count!");
        return 1;
    }
    if (sscanf(argv[2], "%d", &value) != 1) {
        printf("Invalid value of second parameter!");
        return 2;
    }
    if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "/h") == 0)) {
        if (value == 0) {
            printf("Zero Error: Invalid value of second parameter!");
            return 3;
        }
        accumulator = value;
            for (i = 0; i <= 100; i += accumulator) {
                if (i == 0) {
                    continue;
                }
                if (i % value == 0) {
                    printf("%d ", i);
                    ++count;
                }
            }
        if (count == 0) {
            printf("Not krat");
        }
    }
    if ((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "/p") == 0)) {
        if (value == 0) {
            printf("Zero Error: Invalid value of second parameter!");
            return 4;
        }
        if (value == 1) {
            printf("Nor prime neither composite\n");
        }
        else {
            primelity_flag = 1;
            for (i = 2; i <= (int)sqrt(value); i++) {
                if (value % i == 0) {
                    primelity_flag = 0;
                    break;
                }
            }
        }

        if (value > 1) {
            if (primelity_flag == 0) {
                printf("Composite");
            }
            else {
                printf("Prime");
            }
        }
    }
    if ((strcmp(argv[1], "-s") == 0) || (strcmp(argv[1], "/s") == 0)) {
        printf("your number is in the spaces:\n");
        for (i = 0; i < strlen(argv[2]); i++) {
            printf("%c ", argv[2][i]);
            ++count;
        }
    }
    if ((strcmp(argv[1], "-e") == 0) || (strcmp(argv[1], "/e") == 0)) {
        if ((atoi(argv[2]) > 10) || (atoi(argv[2]) < 1)) {
            printf("Error: Not more 10 and not less than 1!");
            return 5;
        }

        int e; unsigned long long result;
        e = atoi(argv[2]);
        for (i = 1; i <= 10; i++) {
            int count = 1;
            result = i;
            printf("%llu ", result);
            while (count < e) {
                result *= i;
                printf("%llu ", result);
                ++count;
            }
            printf("\n");
        }

    }
    if ((strcmp(argv[1], "-a") == 0) || (strcmp(argv[1], "/a") == 0)) {
        unsigned long long sum_arithmetic_progression;
        sum_arithmetic_progression = ((1 + atoi(argv[2])) * atoi(argv[2])) / 2;
        printf("%llu ", sum_arithmetic_progression);
    }
    if ((strcmp(argv[1], "-f") == 0) || (strcmp(argv[1], "/f") == 0)) {
        unsigned long long fact;
        if (atoi(argv[2]) < 0) {
            printf("Error: Unfortunately, the program cannot calculate the factorial of negative numbers for you.");
            return 6;
        }
        if (atoi(argv[2]) > 20) {
            printf("Error: the number is too high ( crash type unsigned long long )");
            return 7;
        }
        fact = factorial(atoi(argv[2]));
        printf("factorial = %llu", fact);
    }
    return 0;
}
unsigned long long factorial(unsigned long long n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return factorial(n - 1) * n;
}