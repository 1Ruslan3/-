#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

char char_numbers[11] = "0123456789";

char char_letters[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

char char_general[64] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";

char prefix[5] = "out_";

char* ach, * argv_file;

FILE* file_, * file_out_;

char c; int i, count = 0;


int main(int argc, char* argv[]) 
{

    if ((file_ = fopen(argv[2], "r")) == NULL) 
    {
        printf("Invalid reading file");
        return 1;
    }

    argv_file = strchr(argv[1], 'n');
    // ищет указатель на элемент 'n' (если его нет, то мы конкетезируем строки out_ и argv[2], а в ином случае файл является argv[3]).

    if (argv_file == NULL) 
    {
        if (argc != 3) 
        {
            printf("Invalid count element( enter value 2 elements (argument and file))");
            return 2;
        }
        file_out_ = fopen(strcat(prefix, argv[2]), "w");

    }
    else 
    {
        if (argc != 4) 
        {
            printf("Invalid count element( enter value 3 elements (argument and file and file-out))");
            return 3;
        }
        file_out_ = fopen(argv[3], "w");
    }

    if (file_out_ == NULL) 
    {
        printf("Invalid writing file");
        return 4;
    }

    if ((strcmp(argv[1], "-nd") == 0) || (strcmp(argv[1], "/nd") == 0) || (strcmp(argv[1], "-d") == 0) || (strcmp(argv[1], "/d") == 0))
    {
        while ((c = getc(file_)) != EOF) 
        {
            ach = strchr(char_numbers, c);
            if (ach == NULL)
                fputc(c, file_out_);
            else
                continue;
        }
        fclose(file_);
    }
    if ((strcmp(argv[1], "-ni") == 0) || (strcmp(argv[1], "/ni") == 0) || (strcmp(argv[1], "-i") == 0) || (strcmp(argv[1], "/i") == 0))
    {
        while ((c = getc(file_)) != EOF) 
        {
            count = 0;
            while (c != '\n') 
            {
                ach = strchr(char_letters, c);
                if (ach != NULL)
                {
                    ++count;
                }
                c = getc(file_);
            }
            fprintf(file_out_, "%d\n", count);
        }
    }
    if ((strcmp(argv[1], "-ns") == 0) || (strcmp(argv[1], "/ns") == 0) || (strcmp(argv[1], "-s") == 0) || (strcmp(argv[1], "/s") == 0))
    {
        while ((c = getc(file_)) != EOF)
        {
            count = 0;
            while (c != '\n') 
            {
                ach = strchr(char_general, c);
                if (ach == NULL) 
                {
                    ++count;
                }
                c = getc(file_);
            }
            fprintf(file_out_, "%d\n", count);
        }
    }
    if ((strcmp(argv[1], "-na") == 0) || (strcmp(argv[1], "/na") == 0) || (strcmp(argv[1], "-a") == 0) || (strcmp(argv[1], "/a") == 0))
    {
        while ((c = getc(file_)) != EOF) 
        {
            ach = strchr(char_numbers, c);
            if (ach == NULL)
            {
                fprintf(file_out_, "%d", c);
            }
        }
    }
    if ((strcmp(argv[1], "-nf") == 0) || (strcmp(argv[1], "/nf") == 0) || (strcmp(argv[1], "-f") == 0) || (strcmp(argv[1], "/f") == 0)) 
    {
        count = 1;
        while ((c = getc(file_)) != EOF) 
        {
            while (c != '\n') {
                if (count % 2 == 0) 
                {
                    if (isalpha(c)) 
                    {
                        c = tolower(c);
                    }
                }
                if (count % 5 == 0) 
                {
                    fprintf(file_out_, "%d", c);
                }
                else {
                    fprintf(file_out_, "%c", c);
                }
                c = getc(file_);
            }
            fprintf(file_out_, "\n");
            ++count;
        }
    }
}