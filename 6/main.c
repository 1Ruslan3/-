#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char char_alv[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char number_system_string[200], new_number_system_string[200], figure[2];

FILE* file_, * file_out_;

char c;

int main(void)
{
    if ((file_ = fopen("file_.txt", "r")) == NULL) 
    {
        printf("Error: Invalid reading file");
        return -1;
    }
    if ((file_out_ = fopen("output.txt", "w")) == NULL) 
    {
        printf("Error: Invalid writing file");
        return -2;
    }
    int count = 0, i; bool flag = false; int max, conversion;
    while ((c = fgetc(file_)) != EOF)
    {

        if (isdigit(c) || isalpha(c)) 
        {
            number_system_string[count++] = c;
            flag = true;
        }
        else if (flag) 
        {
            number_system_string[count] = '\0';
            max = -32000;
            for (i = 0; i < sizeof(number_system_string) / sizeof(char); i++)
            {
                printf("%c", number_system_string[i]);

                if (isdigit(number_system_string[i]) || isalpha(number_system_string[i]))
                {
                    switch (number_system_string[i])
                    {
                    case 'A':
                        conversion = 10;
                        strcat(new_number_system_string, "10");
                        break;
                    case 'B':
                        conversion = 11;
                        strcat(new_number_system_string, "11");
                        break;
                    case 'C':
                        conversion = 12;
                        strcat(new_number_system_string, "12");
                        break;
                    case 'D':
                        conversion = 13;
                        strcat(new_number_system_string, "13");
                        break;
                    case 'E':
                        conversion = 14;
                        strcat(new_number_system_string, "14");
                        break;
                    case 'F':
                        conversion = 15;
                        strcat(new_number_system_string, "15");
                        break;
                    default:
                        conversion = number_system_string[i] - '0';
                        sprintf(figure, "%c", number_system_string[i]);
                        strcat(new_number_system_string, figure);
                        break;
                    }
                    if (conversion >= max)
                    {
                        max = conversion;
                    }
                }


            }
            printf("\nMinimal Number System: %d\n", max + 1);
            printf("Figure Value: %s\n\n", new_number_system_string);
            memset(new_number_system_string, 0, sizeof(new_number_system_string));
            memset(number_system_string, 0, sizeof(number_system_string));
            count = 0;
            flag = false;
        }
    }

    return 0;

}