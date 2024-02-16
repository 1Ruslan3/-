#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>


int main()
{
	char* arr = (char*)malloc(22 * sizeof(char));
	if (arr == NULL)
	{
		return -1;
	};

	strcpy(arr, "Hello world, super!!!");
	printf("%s\n", arr);
	
	char* arr1 = (char*)malloc(10 * sizeof(char));
	if (arr1 == NULL)
	{
		return -2;
	};

	strcpy(arr1, arr + 13);
	printf("%s\n", arr1);

	char* temp = (char*)realloc(arr, 11);
	if (temp == NULL)
	{
		return -3;
	}
	else
	{
		arr = temp;
		temp = NULL;
	};
	printf("%s\n", arr);


	return 0;
}
