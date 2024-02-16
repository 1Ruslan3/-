#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

int substr(char* to_find,/* int case_secsitive,*/ char*** results,/* int*** positions,*/ int* results_count, ...)
{
	
	char *sub = "";
	if (to_find == NULL)
	{
		return 1;
	}
	va_list param;
	va_start(param, results_count);
	while (1)
	{
		sub = va_arg(param, char*);
		if (sub == NULL)
		{
			break;
		};
		
		if (seek_substring_KMP(sub, to_find) != -1)
		{
			
			(*results)[(*results_count)++] = sub;

		};


	}
	

	if (results_count == NULL)
	{
		return 4;
	};


	
	return 0;
}

int seek_substring_KMP(char* s, char* to_find)
{
	int i, j, N, M;
	N = strlen(s);
	M = strlen(to_find);

	// Динамический массив длины М
	int* d = (int*)malloc(M * sizeof(int));

	// Вычисление префикс-функции
	d[0] = 0;
	for (i = 1, j = 0; i < M; i++)
	{
		while (j > 0 && to_find[j] != to_find[i])
			j = d[j - 1];
		if (to_find[j] == to_find[i])
			j++;
		d[i] = j;
	}

	// Поиск
	for (i = 0, j = 0; i < N; i++)
	{
		while (j > 0 && to_find[j] != s[i])
			j = d[j - 1];
		if (to_find[j] == s[i])
			j++;
		if (j == M)
		{
			free(d);
			return i - j + 1;
		}
	}
	free(d);
	return -1;
}

int main()
{
	
    char* text = "ooddaaooaa";
    char* find = "dd";

	char **results = (char**)malloc(5 * sizeof(char*));
	if (results == NULL)
	{
		return 2;
	};
	for (int i = 0; i < 5; ++i)
	{
		(results)[i] = (char*)malloc(7 * sizeof(char));
		if (results[i] == NULL)
		{
			return 3;
		};
	}
	int results_count = 0;

	printf("%d\n", seek_substring_KMP(text, find));

	printf("%d\n", substr(find, &results, &results_count, "ddoodd", "dddd", "sood", "ssoo", "ddd", "oooo", "ddii", "kjdd", NULL));
	printf("%d\n", results_count);
	for (int i = 0; i < results_count; i++)
	{
		printf("%s\n", results[i]);
	}
	
	
	return 0;
}