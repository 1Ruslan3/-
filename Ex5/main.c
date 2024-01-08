#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>


typedef enum Errors {
    ZERO_DEGREED = 1,
    INCORRECT_PARAMETERS = 2,
    SUCCESS = 0,
    OVERFUNC_ERROR = -1,
    CANT_ALLOCATE_MEMORY = -2,
    CANT_OPEN_FILE = -3
} Errors;

typedef enum Flags_Errors {
    FLAGS_SUCCESS = 0,
    FLAGS_STRINGISNULL = -1,
    FLAGS_CANT_ALLOCATE_MEMORY = -2,
    FLAGS_INCORRECT_ARGUMENTS = 1
} Flags_Errors;


//vsprintf - решает ...


int overfunc(char*, const char*, va_list ap);
int oversprintf(char*, const char*, int, ...);
int overfprintf(FILE*, const char*, int, ...);
Flags_Errors dFlag(char** str, int num);
Flags_Errors roFlag(char** str, int num);
Flags_Errors zrFlag(char** str, int num);
Flags_Errors CvFlag(char** writeStr, int num, int syst);
Flags_Errors CVFlag(char** writeStr, int num, int syst);
Flags_Errors TOFlag(char** writeStr, char* num, int syst);
Flags_Errors ToFlag(char** writeStr, char* num, int syst);
Flags_Errors toSystem_From10(int const mode, int number, char** result, int syst);
Flags_Errors fromSystem_To10(int mode, char** writeStr, char* data, int syst);
Flags_Errors MuFlag(char** result, unsigned int value);
Flags_Errors MiFlag(char** result, int value);
Flags_Errors MdFlag(char** result, double value);
Flags_Errors MfFlag(char** result, float value);
Flags_Errors FDDump(char** result, double number, int type);
Flags_Errors dFlag_Write(char** writeStr, int num);


int main(int argc, const char* argv[]) {

    FILE* outputFile = NULL;
    char* outputFilePath = "example.txt";
    int writed;

    char* example = malloc(BUFSIZ);
    if (example == NULL)
    {
        printf("Error allocate memory\n");
        return CANT_ALLOCATE_MEMORY;
    }

    writed = oversprintf(example,
        "Rimsk numbers: %Ro\nCekefendor: %Zr\nInt 19 in 16's system: %Cv and %CV\nString in 16's system to 10's system: %To and %TO\nUInt dump: %Mi\nInt dump: %Mu\nDouble dump: %Md\nFloat dump: %Mf\n",
        14,                      //COUNT
        15,                     //Ro
        100,                    //Zr
        26, 16,                 //Cv
        26, 16,                  //CV
        "1a", 10,                //to
        "1A", 10,                //TO
        127,                    //Mi
        -127,                   //Mu
        -4.25,                  //Md
        -4.25                   //Mf
    );
    printf("%s\n", example);
    if (example != NULL) free(example);




    if (!(outputFile = fopen(outputFilePath, "w"))) {
        printf("Output file not opened\n");
        return CANT_OPEN_FILE;
    }
    overfprintf(outputFile,
        "Rimsk numbers: %Ro\nCekefendor: %Zr\nInt 19 in 16's system: %Cv and %CV\nString in 16's system to 10's system: %To and %TO\nUInt dump: %Mi\nInt dump: %Mu\nDouble dump: %Md\nFloat dump: %Mf\n",
        14,
        15,
        100,
        26, 16,
        26, 16,
        "1a", 10,
        "1A", 10,
        127,
        -127,
        -4.25,
        -4.25
    );

    fclose(outputFile);
    return SUCCESS;
}

int oversprintf(char* result, const char* data, int count, ...)
{
    int writed;
    va_list ap;
    va_start(ap, count);
    writed = overfunc(result, data, ap);
    va_end(ap);
    return writed;
}



int overfprintf(FILE* outputFile, const char* data, int count, ...)
{
    int writed;
    char* example, * examplePtr;
    example = malloc(BUFSIZ);
    if (example == NULL)
    {
        return OVERFUNC_ERROR;
    }
    examplePtr = example - 1;

    va_list ap;
    va_start(ap, count);

    writed = overfunc(example, data, ap);

    while (*++examplePtr)
    {
        putc(*examplePtr, outputFile);
    }

    if (example != NULL) free(example);
    va_end(ap);
    return writed;
}

int overfunc(char* result, const char* data, va_list ap)
{
    const char* dataPtr = data - 1;
    char* resultPtr, * flag, * flagPtr;
    int writed = 0;

    if (result == NULL) return writed;
    resultPtr = result;
    flag = malloc(sizeof(char) * 2);
    if (flag == NULL) return writed;
    flagPtr = flag;





    do
    {
        flagPtr = flag;

        while (*++dataPtr && *dataPtr != '%')
        {
            *resultPtr++ = *dataPtr;
        }
        if (!*dataPtr) break;


        if (*++dataPtr && *dataPtr != '%')
        {
            *flagPtr++ = *dataPtr;
            if (*++dataPtr != '\0' && *dataPtr != '%')
                *flagPtr++ = *dataPtr;
        }
        else break;
        *flagPtr = '\0';





        switch (strlen(flag))
        {
        case 0:
            if (flag != NULL) free(flag);
            return writed;
        case 2:  case 1:
            if (flag[0] == 'R' && flag[1] == 'o')
            {
                if (roFlag(&resultPtr, va_arg(ap, int)) == FLAGS_SUCCESS) ++writed;
                continue;
            }

            if (flag[0] == 'Z' && flag[1] == 'r')
            {
                if (zrFlag(&resultPtr, va_arg(ap, int)) == FLAGS_SUCCESS) ++writed;
                continue;
            }

            if (flag[0] == 'C' && flag[1] == 'v')
            {
                if (CvFlag(&resultPtr, va_arg(ap, int), va_arg(ap, int)) == FLAGS_SUCCESS) ++writed;
                continue;
            }

            if (flag[0] == 'C' && flag[1] == 'V')
            {
                if (CVFlag(&resultPtr, va_arg(ap, int), va_arg(ap, int)) == FLAGS_SUCCESS) ++writed;
                continue;
            }

            if (flag[0] == 'T' && flag[1] == 'o')
            {

                if (ToFlag(&resultPtr, va_arg(ap, char*), va_arg(ap, int)) == FLAGS_SUCCESS) ++writed;
                continue;
            }

            if (flag[0] == 'T' && flag[1] == 'O')
            {
                if (TOFlag(&resultPtr, va_arg(ap, char*), va_arg(ap, int)) == FLAGS_SUCCESS) ++writed;
                continue;
            }

            if (flag[0] == 'M' && flag[1] == 'u')
            {
                if (MuFlag(&resultPtr, va_arg(ap, unsigned int)) == FLAGS_SUCCESS) ++writed;
                continue;
            }

            if (flag[0] == 'M' && flag[1] == 'i')
            {
                if (MiFlag(&resultPtr, va_arg(ap, int)) == FLAGS_SUCCESS) ++writed;
                continue;
            }

            if (flag[0] == 'M' && flag[1] == 'd')
            {
                if (MdFlag(&resultPtr, va_arg(ap, double)) == FLAGS_SUCCESS) ++writed;
                continue;
            }

            if (flag[0] == 'M' && flag[1] == 'f')
            {
                if (MdFlag(&resultPtr, va_arg(ap, double)) == FLAGS_SUCCESS) ++writed;     //va_arg принудительно повышает float до double
                continue;                                                               //float указать нельзя - "непредвиденный результат"
                // printf("\n%f\n",va_arg(ap, float));
            }

            dataPtr--;
            switch (flag[0])
            {
            case 'd':
                if (dFlag(&resultPtr, va_arg(ap, int)) == FLAGS_SUCCESS) ++writed;
                continue;
            }


        default: return writed;    // при несовпадении флага оригинал тоже останавливает выполнение
        }



    } while (*dataPtr != '\0');

    *resultPtr = '\0';

    if (flag != NULL) free(flag);
    return writed;
}



Flags_Errors dFlag(char** writeStr, int num)
{

    if (num < 0)
    {
        num = abs(num);
        **writeStr = '-';
        ++*writeStr;
    }

    return dFlag_Write(writeStr, num);
}

Flags_Errors dFlag_Write(char** writeStr, int num)
{
    if (num > 0)
    {
        dFlag_Write(writeStr, num / 10.0);
        **writeStr = (num % 10) + '0';
        ++*writeStr;
    }

    return FLAGS_SUCCESS;
}

Flags_Errors roFlag(char** writeStr, int num)
{
    static int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    static char* symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    for (int i = 0; i < 13; ++i) {
        while (num >= values[i]) {
            num -= values[i];
            strcat(*writeStr, symbols[i]);
            ++*writeStr;
        }
    }

    return FLAGS_SUCCESS;
}

Flags_Errors zrFlag(char** writeStr, int num)
{

    int ptrDet = 0;
    char* buffNum;
    int* numbers, * numbersPtr, size;
    if (num < 1) return FLAGS_INCORRECT_ARGUMENTS;

    size = (int)(log(num) / log(1.617) + 1.0);  //+1 для значения "1"
    numbers = (int*)malloc(sizeof(int) * size);
    if (numbers == NULL) return FLAGS_CANT_ALLOCATE_MEMORY;
    numbersPtr = numbers - 1;

    *++numbersPtr = 1;
    *++numbersPtr = 2;
    while (++numbersPtr - numbers < size)
    {
        *numbersPtr = *(numbersPtr - 1) + *(numbersPtr - 2);
    }


    buffNum = malloc(BUFSIZ);
    if (buffNum == NULL)
    {
        if (numbers != NULL) free(numbers);
        return FLAGS_CANT_ALLOCATE_MEMORY;
    }

    while (--numbersPtr >= numbers)
    {
        if (num >= *numbersPtr)
        {
            sprintf(buffNum, "%d+", *numbersPtr);
            ptrDet += strlen(buffNum);
            strcat(*writeStr, buffNum);
            num -= *numbersPtr;
        }
    }


    if (buffNum != NULL) free(buffNum);
    if (numbers != NULL) free(numbers);
    *writeStr += ptrDet - 1;
    return FLAGS_SUCCESS;

}


Flags_Errors CvFlag(char** writeStr, int num, int syst)
{
    toSystem_From10(0, num, writeStr, syst);
    return FLAGS_SUCCESS;
}

Flags_Errors CVFlag(char** writeStr, int num, int syst)
{
    toSystem_From10(1, num, writeStr, syst);
    return FLAGS_SUCCESS;
}


Flags_Errors toSystem_From10(int const mode, int number, char** result, int syst)
{


    char* resultPtr, * appendPtr;
    int currValue, size;
    if (syst < 2 || syst>36) syst = 10;


    size = (floor(log(abs(number)) / log(syst)) + 1 + 1 + 1 + 1);  //последний остаток, округление log, для минуса, для \0
    resultPtr = *result + size - 2;
    if (number < 0)
    {
        number = abs(number);
        **result = '-';
    }
    else
    {
        resultPtr--;
    }
    appendPtr = resultPtr;


    *resultPtr = '\0';
    while (resultPtr != *result && number != 0)
    {
        currValue = number % syst;
        *--resultPtr = currValue < 10 ? currValue + '0' : currValue + (mode == 1 ? 'A' : 'a') - 10;
        number /= syst;
    }


    *result = appendPtr;
    return FLAGS_SUCCESS;
}





Flags_Errors TOFlag(char** writeStr, char* num, int syst)
{

    return fromSystem_To10(1, writeStr, num, syst);
}


Flags_Errors ToFlag(char** writeStr, char* num, int syst)
{
    return fromSystem_To10(0, writeStr, num, syst);
}




Flags_Errors fromSystem_To10(int mode, char** writeStr, char* data, int syst)
{
    int result = 0;
    char current, * dataPtr = data - 1;
    if (syst < 2 || syst>36) syst = 10;
    if (data == NULL) return FLAGS_STRINGISNULL;

    while ((current = *++dataPtr))
    {
        current -= isdigit(current) ? '0' : (mode == 1 ? 'A' : 'a') - 10;
        result += current;
        if (*(dataPtr + 1)) result *= syst;
    }

    dFlag(writeStr, result);
    return FLAGS_SUCCESS;
}


Flags_Errors MuFlag(char** result, unsigned int number) {
    MiFlag(result, number);
    return FLAGS_SUCCESS;
}

Flags_Errors MiFlag(char** result, int number) {

    char* resPtr = *result;
    unsigned int mask = 1 << 31;

    for (int i = 0; i < 32; ++i)
    {
        if (i != 0 && i % 8 == 0)
        {
            *resPtr++ = ' ';
            ++*result;
        }

        *resPtr++ = (number & mask ? '1' : '0');
        ++*result;
        number <<= 1;
    }

    return FLAGS_SUCCESS;
}

Flags_Errors MfFlag(char** result, float number) {
    FDDump(result, number, 1);
    return FLAGS_SUCCESS;
}

Flags_Errors MdFlag(char** result, double number) {
    FDDump(result, number, 0);
    return FLAGS_SUCCESS;
}

Flags_Errors FDDump(char** result, double number, int type) {   //void* потом   Трактуем его как массив символов чтобы перемещаться по байтам ниже

    char* resPtr = *result, * ptr = (char*)&number; //указатель на область памяти где начинается число.
    // Трактуем его как массив символов чтобы перемещаться по байтам
    int charBytesCount = sizeof(char) * 8,
        numberBytesCount = charBytesCount * (type == 0 ? sizeof(double) : sizeof(float)),
        mask, byteCode, i;


    for (i = numberBytesCount; i > 0; i--)
    {
        if (i != numberBytesCount && i % 8 == 0)
        {
            *resPtr++ = ' ';
            ++*result;
        }

        mask = 1 << i % charBytesCount;                   //перемещаемся по байтам (целочисл деление на 8(бит в char))
        byteCode = ptr[i / charBytesCount] & mask;          //затем по его битам (остаток от деления на 8) с помщью маски
        *resPtr++ = byteCode > 0 ? '1' : '0';
        ++*result;
    }
    return FLAGS_SUCCESS;
}

