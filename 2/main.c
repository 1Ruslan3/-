#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int root_equation(char* arg1, char* arg2, char* arg3);

char strArray1[7], strArray2[7];

int value, a, b, c;

float x1, x2;


int main(int argc, char* argv[]) 
{
    if (argc == 1) 
    {
        printf("Invalid arguments count!");
        return 1;
    }
    if ((strcmp(argv[1], "-q") == 0) || (strcmp(argv[1], "/q") == 0)) 
    {
        if (argc != 5) 
        {
            printf("Invalid arguments count!");
            return 2;
        }
        // нет решений флаг принимает 0
        // есть 1 решение флаг принимает 1
        // флаг больше не принимает значений, поэтому если 2, то 2 решения

        int flag_root = root_equation(argv[2], argv[3], argv[4]);
        if (flag_root == 0) 
        {
            printf("No solutions");
        }
        else if (flag_root == 1) 
        {
            printf("%f\n", x1);
        }
        else 
        {
            printf("%f %f\n", x1, x2);
        }
    }

    if ((strcmp(argv[1], "-m") == 0) || (strcmp(argv[1], "/m") == 0)) 
    {
        if (argc != 4) 
        {
            printf("Invalid arguments count!");
            return 3;
        }
        if ((atoi(argv[2]) == 0) || (atoi(argv[3]) == 0)) 
        {
            printf("Zero Error: arguments cannot be zero!");
            return 4;
        }
        if (atoi(argv[2]) % atoi(argv[3]) == 0) 
        {
            printf("the number is a multiple");
        }
        else 
        {
            printf("the number is not a multiple");
        }
    }

    if ((strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "/t") == 0)) 
    {
        if (argc != 5) 
        {
            printf("Invalid arguments count!");
            return 5;
        }
        if ((atoi(argv[2]) == 0) || (atoi(argv[3]) == 0) || (atoi(argv[4]) == 0)) 
        {
            printf("Zero Error: arguments cannot be zero!");
            return 6;
        }
        sprintf(strArray2, "%s %s %s", argv[2], argv[3], argv[4]);
        if (sscanf(strArray2, "%d %d %d", &a, &b, &c) != 3) 
        {
            printf("Invalid arguments count!");
            return 7;
        }

        if (((a + b) > c) && ((c + b) > a) && ((a + c) > b)) 
        {
            if (a > b && a > c) {
                double Alpfa;
                Alpfa = (float)(b * b + c * c - a * a) / (2 * b * c);
                printf(acos(0) == acos(Alpfa) ? "right triangle exists" : "right triangle doesn't exist");
            }
            else if (b > a && b > c) 
            {
                double Alpfa;
                Alpfa = (float)(a * a + c * c - b * b) / (2 * a * c);
                printf(acos(0) == acos(Alpfa) ? "right triangle exists" : "right triangle doesn't exist");
            }
            else 
            {
                double Alpfa;
                Alpfa = (float)(b * b + a * a - c * c) / (2 * b * a);
                printf(acos(0) == acos(Alpfa) ? "right triangle exists" : "right triangle doesn't exist");
            }
        }
        else 
        {
            printf("right triangle doesn't exist");
        }
    }

}


int root_equation(char* arg1, char* arg2, char* arg3) 
{

    float D;
    sprintf(strArray1, "%s %s %s", arg1, arg2, arg3);
    if (sscanf(strArray1, "%d %d %d", &a, &b, &c) != 3) 
    {
        printf("Invalid arguments count!");
        return 8;
    }
    int flag = 0;
    if (a == 0) 
    {
        printf("This is not a quadratic equation!");
        return 9;
    }
    else if (b == 0) 
    {
        if (c == 0) 
        {
            x1 = 0;
            flag = 1;
        }
        else 
        {
            if ((c > 0 && a < 0) || (c < 0 && a>0)) 
            {
                x1 = sqrt(-c / a);
                x2 = -sqrt(-c / a);
                flag = 2;
            }
            else 
            {
                flag = 0;
            }
        }
    }
    else if (c == 0) 
    {
        x1 = 0;
        x2 = (float)(- b) / a;
        flag = 2;
    }
    else 
    {
        // a*x*x + b*x + c = 0
        D = b * b - 4 * a * c;
        if (D > 0) {
            x1 = (sqrt(D) - b) / (2 * a);
            x2 = ((-1) * (sqrt(D) + b)) / (2 * a);
            flag = 2;
        }
        if (D == 0)
        {
            x1 = (-b) / (2 * a);
            flag = 1;
        }
        if (D < 0) 
        {
            flag = 0;
        }
    }

    return flag;

}