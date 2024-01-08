#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <ctype.h>

enum StatusCode
{
    INVALID_COUNT_ARGUMENTS,
    MEMORY_ERROR
};

int fuct_strcmp(const char*, const char*);

int fuct_strlen(const char*);

char* fuct_reversed(const char*);

char* fuct_noeven_toupper(const char*);

char* fuct_sort(const char*);


int main(int argc, char* argv[])
{
    char* result;



    if (fuct_strcmp(argv[1], "-l") == 0) 
    {
        if (argc != 3) 
        {
            printf("Invalid count parameters");
            return INVALID_COUNT_ARGUMENTS;
        }
        printf("%d", fuct_strlen(argv[2]));
    }
    else if (fuct_strcmp(argv[1], "-r") == 0) 
    {

        if (fuct_reversed(argv[2]) == NULL) 
        {
            perror("Unfortunately, a memory non-allocation error occurred");
            return MEMORY_ERROR;
        }

        printf("%s", fuct_reversed(argv[2]));
    }
    else if (fuct_strcmp(argv[1], "-u") == 0) 
    {

        if (fuct_noeven_toupper(argv[2]) == NULL) 
        {
            perror("Unfortunately, a memory non-allocation error occurred");
            return MEMORY_ERROR;
        }

        printf("%s", fuct_noeven_toupper(argv[2]));
    }
    else if (fuct_strcmp(argv[1], "-n") == 0) 
    {
        if (fuct_sort(argv[2]) == NULL)
        {
            perror("Unfortunately, a memory non-allocation error occurred");
            return MEMORY_ERROR;
        }
        printf("%s", fuct_sort(argv[2]));
    }
    else 
    {
        printf("Unknown flag: %s\n", argv[1]);
        return 4;
    }
    return 0;

}

int fuct_strcmp(const char* argv, const char* flag) 
{
    int index = 0;
    bool check_flag = true;
    if (sizeof(argv) != sizeof(flag)) 
    {
        return 1;
    }
    while (argv[index++] != '\0') 
    {
        if (argv[index] != flag[index]) 
        {
            check_flag = false;
        }
    }
    return check_flag ? 0 : 1;
}

void func_strcpy(char* destination, const char* sourse)
{
    while (*sourse)
    {
        *destination = *sourse;
        destination++;
        sourse++;
    }
    *destination = '\0';
}


int fuct_strlen(const char* string)
{
    int i, count_char = 0;
    while (string[count_char] != '\0') 
    {
        count_char++;
    }
    return count_char;
}

char* fuct_reversed(const char* string) 
{
    int i, new_count = 0;
    int len = fuct_strlen(string);

    char* array_string = (char*)malloc((len + 1) * sizeof(char));
    if (array_string == NULL) 
    {
        return NULL;
    }

    for (i = (len - 1); i >= 0; i--) 
    {
        array_string[new_count++] = string[i];
    }

    array_string[new_count] = '\0';
    return array_string;
}

char* fuct_noeven_toupper(const char* string)
{
    int i, new_count = 0;
    char* array_string = (char*)malloc((fuct_strlen(string) + 1) * sizeof(char));
    if (array_string == NULL) 
    {
        return NULL;
    }

    for (i = 0; i < fuct_strlen(string); i++) 
    {
        array_string[i] = string[i];
        if (i % 2 == 1) 
        {
            array_string[i] = toupper(string[i]);
        }

    }

    array_string[i] = '\0';

    return array_string;
}

char* fuct_sort(const char* string) 
{
    int i, strlen = (fuct_strlen(string) + 1);
    char* array_string = (char*)malloc(strlen * sizeof(char));
    if (array_string == NULL) 
    {
        return NULL;
    }
    int count = 0;

    for (i = 0; i < strlen - 1; i++) 
    {
        if (isdigit(string[i]))
        {
            array_string[count++] = string[i];
        }
    }

    for (i = 0; i < strlen - 1; i++) 
    {
        if (isalpha(string[i])) 
        {
            array_string[count++] = string[i];
        }
    }

    for (i = 0; i < strlen - 1; i++)
    {
        if (!(isalpha(string[i])) && !(isdigit(string[i]))) 
        {
            array_string[count++] = string[i];
        }
    }

    array_string[count] = '\0';

    return array_string;
}
