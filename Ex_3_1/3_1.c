#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include<ctype.h>

int substr(char* to_find, int case_sensitive, char*** results, int*** positions, size_t* results_count, ...)
{
	if (to_find == NULL)
	{
		return 1;
	}

	if (results == NULL)
	{
		return 2;
	}

	if (positions == NULL)
	{
		return 3;
	}

	if (results_count == NULL)
	{
		return 4;
	}

	int len, sublen, i, j;
	sublen = strlen(to_find);
	char* lwr = (char*)malloc(sizeof(char) * 13);
	if (lwr == NULL)
	{
		return 5;
	}
	char* rwr = (char*)malloc(sizeof(char) * 13);
	if (rwr == NULL)
	{
		return 6;
	}
	va_list first;
	va_start(first, results_count);
	char* tmp = va_arg(first, char*);
	char* time = tmp;
	while (tmp != NULL)
	{
			time = tmp;
			len = strlen(tmp);
			if (case_sensitive == 0)
			{
				for (i = 0; i < strlen(tmp); i++) 
				{
					lwr[i] = tolower(tmp[i]); 
				} 
				for (i = 0; i < strlen(to_find); i++)
				{
					rwr[i] = tolower(to_find[i]);
				}
				tmp = lwr;
				to_find = rwr;
			}
			for (i = 0; i <= len - sublen; i++)
			{
				for (j = 0; j < sublen; j++)
				{
					if (tmp[i + j] != to_find[j])  
					{
						break;
					}
				}
				if (j == sublen)
				{
					memcpy(results[*results_count], time, strlen(tmp));
					(*results_count)++;
				}
			}
			tmp = va_arg(first, char*);

	};

	free(lwr);
	free(rwr);

	return 0;
}

int main()
{
	size_t results_count = 0;
	int i;


	char* to_find = (char*)malloc(sizeof(char) * 13);
	if (to_find == NULL)
	{
		return 1;
	}

	char** results = (char**)malloc(sizeof(char*) * 13);
	if (results == NULL)
	{
		return 2;
	}
	for (i = 0; i < 13; i++)
	{
		results[i] = (char*)malloc(sizeof(char) * 13);
		if (results[i] == NULL)
		{
			return 2;
		}
	}

	int** positions = (int**)malloc(sizeof(int*) * 13);
	if (positions == NULL)
	{
		return 3;
	}
	for (i = 0; i < 13; i++)
	{
		positions[i] = (int*)malloc(sizeof(int) * 13);
		if (positions[i] == NULL)
		{
			return 3;
		}
	}

	memcpy(to_find, "Hydro", 13);
	
	
	printf("%s\n", to_find);

	int x = substr(to_find, 1, results, positions, &results_count, "hydrocanal!!!", "hydrocanal!!!", "Hydrocanal!!!", "Hydrocanal!!!", NULL);
	printf("%d\n", x);
	printf("%d\n", results_count);
	for (i = 0; i < results_count; i++)
	{
		printf("%s\n", results[i]);
	}

	/*for (i = 0; i < 13; i++)
	{
		free(positions[i]);
		free(results[i]);
	}*/

	free(results);
	free(positions);

	return 0;
}