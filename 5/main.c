#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_WIDTH_SIZE_STRING 256

int i;
char c;

char MAX_WIDTH_STRING[MAX_WIDTH_SIZE_STRING + 1];

FILE* file_, * file_for_r, * file_for_w;

int main(int argc, char* argv[]) 
{
    if ((file_for_w = fopen("file_out.txt", "w")) == NULL) 
    {
        printf("Invalid writing file");
        return 4;
    }
    if (argc == 1)
    {
        printf("Not files and flags");
        return -1;
    }
    if (strcmp(argv[1], "-fi") == 0 || strcmp(argv[1], "/fi") == 0)
    {
        if (argc == 2) 
        {
            printf("Not files");
            return -2;
        }
        else if (argc == 3)
        {

            if ((file_ = fopen(argv[2], "r")) == NULL) 
            {
                printf("Invalid reading file");
                return -3;
            }
            int count = 0;
            while (fgets(MAX_WIDTH_STRING, sizeof(MAX_WIDTH_STRING), file_) != NULL) 
            {
                MAX_WIDTH_STRING[strcspn(MAX_WIDTH_STRING, "\n")] = 0;
                if ((file_for_r = fopen(MAX_WIDTH_STRING, "r")) == NULL)
                {
                    printf("Invalid reading file");
                    return -3;
                }

                while ((c = getc(file_for_r)) != EOF) 
                {
                    fputc(c, file_for_w);
                }

            }
            fclose(file_);
            fclose(file_for_r);
            fclose(file_for_w);

        }
        else
        {
            printf("Invalid count value files");
            return -5;
        }

    }
    if (strcmp(argv[1], "-fi") == 0 || strcmp(argv[1], "/fi") == 0)
    {
        if (argc == 2) {
            printf("Not files");
            return -2;
        }
        else if (argc == 3) {

            if ((file_ = fopen(argv[2], "r")) == NULL)
            {
                printf("Invalid reading file");
                return -3;
            }
            int count = 0;
            while (fgets(MAX_WIDTH_STRING, sizeof(MAX_WIDTH_STRING), file_) != NULL)
            {
                MAX_WIDTH_STRING[strcspn(MAX_WIDTH_STRING, "\n")] = 0;
                if ((file_for_r = fopen(MAX_WIDTH_STRING, "r")) == NULL)
                {
                    printf("Invalid reading file");
                    return -3;
                }

                while ((c = getc(file_for_r)) != EOF)
                {
                    fputc(c, file_for_w);
                }

            }
            fclose(file_);
            fclose(file_for_r);
            fclose(file_for_w);

        }
        else 
        {
            printf("Invalid count value files");
            return -5;
        }

    }
    if (strcmp(argv[1], "-cin") == 0 || strcmp(argv[1], "/cin") == 0) 
    {
        if (argc != 2) {
            printf("Sorry, you're enter don't a one arguments");
            return -2;
        }
        char string_file[MAX_WIDTH_SIZE_STRING + 1];
        printf("enter the files (if you have entered everything, then enter -1) : ");
        scanf("%s", string_file);
        while (strcmp(string_file, "-1") != 0) 
        {
            if ((file_for_r = fopen(string_file, "r")) == NULL) 
            {
                printf("Invalid reading file");
                return -3;
            }

            while ((c = getc(file_for_r)) != EOF)
            {
                fputc(c, file_for_w);
            }
            printf("enter the files (if you have entered everything, then enter -1) : ");
            scanf("%s", &string_file);


        }
        fclose(file_for_r);
        fclose(file_for_w);

    }
    if (strcmp(argv[1], "-arg") == 0 || strcmp(argv[1], "/arg") == 0) 
    {
        if (argc == 2) 
        {
            printf("Not files");
            return 2;
        }
        file_for_w = fopen("file_out.txt", "w");
        if (file_for_w == NULL) 
        {
            printf("Invalid writing file");
            return 4;
        }
        for (i = 2; i < argc; i++) {
            if ((file_for_r = fopen(argv[i], "r")) == NULL) 
            {
                printf("Invalid reading file");
                return 3;
            }

            while ((c = getc(file_for_r)) != EOF) 
            {
                fputc(c, file_for_w);
            }
            fclose(file_for_r);
        }
        fclose(file_for_w);
    }



}