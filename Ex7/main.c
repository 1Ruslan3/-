#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

enum StatusCode {
    OK = 0,
    MEMORY_ERROR = -1,
    INVALID_COUNT_ERROR = 1

};

enum StatusCode appendNumber(int syst, char** number1, const char* number2);
enum StatusCode sumNumbers(char** result, int syst, int count, ...);

int main(int argc, const char* argv[]) {
    char* result = NULL;
    switch (sumNumbers(&result, 16, 3, "9A4", "444", "1B2D")) {
    case OK:
        printf("%s\n", result);
        free(result);
        return 2;
    case MEMORY_ERROR:
        return -2;
        break;
    case INVALID_COUNT_ERROR:
        return 3;
        break;

    }


    return 0;
}

enum StatusCode sumNumbers(char** result, int syst, int count, ...) {
    if (count == 0) {
        return INVALID_COUNT_ERROR;
    }

    va_list ap;
    va_start(ap, count);

    *result = strdup(va_arg(ap, char*)); // dublicate string

    if (*result == NULL) {
        return MEMORY_ERROR;
    }

    for (int i = 1; i < count; i++)
    {
        if (appendNumber(syst, result, va_arg(ap, char*)) != OK) {
            va_end(ap);
            return MEMORY_ERROR;
        }
    }

    va_end(ap);
    return OK;
}

enum StatusCode appendNumber(int syst, char** number1, const char* number2) {

    size_t len1 = strlen(*number1), len2 = strlen(number2);
    size_t currentLen = (len1 >= len2 ? len1 : len2) + 2;

    const char* n1Ptr = *number1 + len1 - 1;
    const char* n2Ptr = number2 + len2 - 1;

    char* result = (char*)calloc(currentLen, sizeof(char));

    if (result == NULL) {
        return MEMORY_ERROR;
    }

    char* resultPtr = result + currentLen - 1;

    int stepsMemory = 0;

    while (n1Ptr != (*number1) - 1 || n2Ptr != number2 - 1) {

        int n1Val = (n1Ptr != (*number1) - 1) ? ((*n1Ptr >= 'A') ? toupper(*n1Ptr) - 'A' + 10 : *n1Ptr - '0') : 0;

        int n2Val = (n2Ptr != number2 - 1) ? ((*n2Ptr >= 'A') ? toupper(*n2Ptr) - 'A' + 10 : *n2Ptr - '0') : 0;

        if (n1Ptr != (*number1) - 1) { n1Ptr--; }
        if (n2Ptr != number2 - 1) { n2Ptr--; }


        int currVal = n1Val + n2Val + stepsMemory;
        stepsMemory = currVal / syst;
        currVal %= syst;
        if (currVal < 10) {
            *resultPtr-- = (char)currVal + '0';
        }
        else {
            *resultPtr-- = (char)currVal - 10 + 'A';
        }

    }

    if (stepsMemory != 0)

        if (stepsMemory < 10) {
            *resultPtr-- = (char)stepsMemory + '0';
        }
        else {
            *resultPtr-- = (char)stepsMemory - 10 + 'A';
        }

    free(*number1);
    *number1 = strdup(resultPtr + 1);
    if (!*number1) {
        free(result);
        return MEMORY_ERROR;
    }

    free(result);
    return OK;
}