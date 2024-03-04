#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include<ctype.h>



int substr(int *tt,char* to_find, int case_sensitive, char*** results, int*** positions, size_t* results_count, ...)
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
	char* lwr = (char*)malloc(sizeof(char) * (*tt));
	if (lwr == NULL)
	{
		return 5;
	}
	char* rwr = (char*)malloc(sizeof(char) * (*tt));
	if (rwr == NULL)
	{
		return 6;
	}
	va_list first;
	va_start(first, results_count);
	char* tmp = va_arg(first, char*);
	char* time = tmp;
	int count = 0;
	int** ptr_count;
	char** ptr_result;

	while (tmp != NULL)
	{
			//time = tmp;
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
					positions[*results_count] = count;
					(*results_count)++;
					if ((*results_count) > (*tt))
					{
						(*tt) *= 2;
						ptr_result = (char**)realloc(results, sizeof(char*) * (*tt));
						if (ptr_result != NULL)
						{
							results = ptr_result;
							ptr_result = NULL;
						}
						for (i = 0; i < (*tt); i++)
						{
							ptr_result = (char*)realloc(results[i], sizeof(char) * (*tt));
							if (ptr_result != NULL)
							{
								results[i] = ptr_result;
								ptr_result = NULL; 
							}
						}
						ptr_count = (int**)realloc(positions, sizeof(int*) * (*tt)); 
						if (ptr_count != NULL) 
						{
							positions = ptr_count;
							ptr_count = NULL;
						}
						for (i = 0; i < (*tt); i++)
						{
							ptr_count = (int*)realloc(positions[i], sizeof(int) * (*tt));
							if (ptr_count != NULL)  
							{
								positions[i] = ptr_count; 
								ptr_count = NULL; 
							}
						}
					}
				}
			}
			tmp = va_arg(first, char*);
			count++;
	};

	free(lwr);
	free(rwr);
	free(tmp);

	return 0;
}



int main()
{
	size_t results_count = 0;
	int i;

	int tt = 32;

	char* to_find = (char*)malloc(sizeof(char) * tt);
	if (to_find == NULL)
	{
		return 1;
	}

	char** results = (char**)malloc(sizeof(char*) * tt);
	if (results == NULL)
	{
		return 2;
	}
	for (i = 0; i < tt; i++)
	{
		results[i] = (char*)malloc(sizeof(char) * tt);
		if (results[i] == NULL)
		{
			return 2;
		}
	}

	int** positions = (int**)malloc(sizeof(int*) * tt);
	if (positions == NULL)
	{
		return 3;
	}
	for (i = 0; i < tt; i++)
	{
		positions[i] = (int*)malloc(sizeof(int) * tt);
		if (positions[i] == NULL)
		{
			return 3;
		}
	}

	memcpy(to_find, "Hydro", 13);
	
	
	printf("%s\n", to_find);

	int x = substr(&tt,to_find, 0, results, positions, &results_count, "hydrocanal!!!", "hydrocanal!!!", "Hydrocanal!!!", "Hydrocanal!!!", NULL);
	printf("%d\n", x);
	printf("%d\n", results_count);
	for (i = 0; i < results_count; i++)
	{
		printf("%s\n", results[i]);
	}

	for (i = 0; i < results_count; i++)
	{
		printf("%d\n", positions[i]);
	}

	for (i = tt; i >= 0; i--) 
	{
		free(positions[i]);  
		free(results[i]);  
	}

	free(results);
	free(positions);
	free(to_find);

	return 0;
}