#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int numeral_system; 
int numbers_numeral_system[256];
char string[1000], max_string[1000], number_string[256][1000];
char array_alv[11][2] = { "0","1","2","3", "4","5","6","7","8","9" };
char array_alv_bulv[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int number, i;

long recurtion(long number_ten, long const_n, int const_system_name, int count_local);
void recurtion_block_to_9(long, long);
void recurtion_block_to_18(long, long);
void recurtion_block_to_27(long, long);
void recurtion_block_to_36(long, long);

int main(void)
{
    printf("Enter the number system: ");
    scanf("%d", &numeral_system);

    if (numeral_system < 2 || numeral_system > 36) 
    {
        printf("Invalid Error: The number system is not included in the accessible range.");
        return 1;

    }

    printf("Enter number in basis, that and %d (to finish, enter \"Stop\"): ", numeral_system);
    scanf("%s", string);

    long max = strtol(string, NULL, numeral_system);

    while (strcmp(string, "Stop") != 0) 
    {
        if (abs(strtol(string, NULL, numeral_system)) > abs(max)) 
        {
            max = abs(strtol(string, NULL, numeral_system));
        }

        printf("Enter number in basis, that and %d (to finish, enter \"Stop\"): ", numeral_system);
        scanf("%s", string);

    }

    long const_n = max;
    printf("Maximum number in base 9: ");
    recurtion_block_to_9(max, const_n);
    printf("Maximum number in base 18: ");
    recurtion_block_to_18(max, const_n);
    printf("Maximum number in base 27: ");
    recurtion_block_to_27(max, const_n);
    printf("Maximum number in base 36: ");
    recurtion_block_to_36(max, const_n);
    return 0;
}

long recurtion(long n, long c, int const_system, int count)
{
    sprintf(number_string[0], (c % const_system < 10) ? "%ld" : "%c", (c % const_system < 10) ? c % const_system : array_alv_bulv[(c % const_system) - 10]);
    if (((n - (n % const_system)) / const_system) == 0) {
        return ((n % const_system < 10) ? (n % const_system) : array_alv_bulv[(n % const_system) - 10]);
    }
    else 
    {
        ++count;
        sprintf(number_string[count], (recurtion(n / const_system, c, const_system, count) < 10) ? "%ld" : "%c", recurtion(n / const_system, c, const_system, count));
        return ((n % const_system < 10) ? (n % const_system) : array_alv_bulv[(n % const_system) - 10]);
    }

}
void recurtion_block_to_9(long number_system_ten, long const_n)
{
    recurtion(number_system_ten, const_n, 9, 0);
    for (i = sizeof(number_string) / sizeof(number_string[256]); i >= 0; i--) 
    {
        printf("%s", number_string[i]);
    }
    printf("\n");
    for (i = sizeof(number_string) / sizeof(number_string[256]); i >= 0; i--) 
    {
        memset(number_string[i], 0, sizeof(number_string[i]));
    }
}

void recurtion_block_to_18(long number_system_ten, long const_n) {
    recurtion(number_system_ten, const_n, 18, 0);
    for (i = sizeof(number_string) / sizeof(number_string[256]); i >= 0; i--)
    {
        printf("%s", number_string[i]);
    }
    printf("\n");
    for (i = sizeof(number_string) / sizeof(number_string[256]); i >= 0; i--) 
    {
        memset(number_string[i], 0, sizeof(number_string[i]));
    }
}

void recurtion_block_to_27(long number_system_ten, long const_n)
{
    recurtion(number_system_ten, const_n, 27, 0);
    for (i = sizeof(number_string) / sizeof(number_string[256]); i >= 0; i--) 
    {
        printf("%s", number_string[i]);
    }
    printf("\n");
    for (i = sizeof(number_string) / sizeof(number_string[256]); i >= 0; i--) 
    {
        memset(number_string[i], 0, sizeof(number_string[i]));
    }
}

void recurtion_block_to_36(long number_system_ten, long const_n)
{
    recurtion(number_system_ten, const_n, 36, 0);
    for (i = sizeof(number_string) / sizeof(number_string[256]); i >= 0; i--)
    {
        printf("%s", number_string[i]);
    }

}