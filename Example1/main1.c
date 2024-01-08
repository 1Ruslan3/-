#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <limits.h>
#include <math.h>

enum StatusCode
{
    OK = 0,
    BASE_OF_NUMBER_SYSTEM_RANGE_ERROR = 1,
    ALLOCATION_MEMORY_ERROR = 2
};



int bitwise_convertion_number_system(int, int, char**);
int add_remainder_array(int*, int, char**);
void reverse_string(char*);

int main()
{
    int number = 13;
    int r = 4; // 2^r
    char* p;
    switch (bitwise_convertion_number_system(number, r, &p))
    {
    case 0:
        printf(p);
        free(p);
        break;
    case 1:
        return 4;
        break;
    case 2:
        return 5;
        break;
    }

    return 0;
}

int bitwise_convertion_number_system(int number_system, int radix, char** arrayPtr)
{


    if (radix < 1 && radix > 5)
    {
        return BASE_OF_NUMBER_SYSTEM_RANGE_ERROR;
    }

    int base = (1 << radix) - 1;



    char* array = (char*)malloc(sizeof(char));

    if (array == NULL)
    {
        return ALLOCATION_MEMORY_ERROR;
    }

    int count = 0;
    do
    {

        if (add_remainder_array(&count, number_system & base, &array))
        {
            return 3;
        }
        number_system >>= radix;

    } while (number_system != 0);

    array[count] = '\0';
    reverse_string(array);
    *arrayPtr = array;

    return OK;
}

int add_remainder_array(int* count_array, int number_element, char** array_elements)
{
    // ASCII-CODE
    char c = (number_element > 9) ? (number_element + 'A' - 10) : (number_element + '0');

    char* tempPtr = (char*)realloc(*array_elements, ((*count_array + 2) * sizeof(char)));
    if (tempPtr == NULL)
    {
        free(*array_elements);
        return ALLOCATION_MEMORY_ERROR;
    }
    *array_elements = tempPtr;
    (*array_elements)[(*count_array)++] = c;

    return OK;
}
void reverse_string(char* str)
{
    int length = strlen(str);
    char temp;
    for (int i = 0; i < length / 2; i++)
    {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}