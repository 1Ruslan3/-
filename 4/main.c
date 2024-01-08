#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char* argv[]) 
{
    FILE* input;
    FILE* output;

    if (argc != 2)
    {
        printf("Enter file name in arguments console command");
        return 1;
    }
    if ((input = fopen(argv[1], "r")) == NULL) 
    {
        printf("Invalid reading file");
        return 2;
    }
    char a1[100], a2[100], a3[100];
    input = fopen("stolb.txt", "r");
    output = fopen("output.txt", "w");
    for (int i = 0; i < 3; i++)
    {
        fscanf(input, "%s %s %s", a1, a2, a3);
        fprintf(output, "%s %s %s\n", a1, a2, a3);
    }
    fclose(input);
    fclose(output);

    input = fopen("stolb.txt", "w");
    output = fopen("output.txt", "r");
    for (int r = 0; r < 3; r++)
    {
        fscanf(output, "%s %s %s", a1, a2, a3);
        fprintf(input, "%s %s %s\n", a3, a1, a2);
    }
    fclose(input);
    fclose(output);
}