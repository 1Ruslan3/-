#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DELIMITERS " .,:;?\n\t" /* символы-разделители */
#define N 1024

 void Init(int* flag, const char* s)/* инициализация массива flag размера 256 */
{

	int i;

	for (i = 0; i < 256; i++) flag[i] = 0;

	for (i = 0; s[i]; i++) flag[s[i]] = 1;

}

/* разбиение строки на слова: */

char* my_strtok2(char* s, const int* flag)
{

	static char* beg = NULL; 
	char* pstr, * pword = NULL; 
	int len;

	if (s != NULL)
	{

		for (pstr = s; *pstr && flag[*pstr]; ++pstr);

		beg = pstr;

	}else	pstr = beg;

	for (; *beg && !flag[*beg]; ++beg);

	if (*pstr)
	{

		pword = (char*)malloc(beg - pstr + 1); 
		if (pword != NULL)
		{

			len = (beg - pstr) / sizeof(char); 
			strncpy(pword, pstr, len);
			pword[len] = '\0'; 

		}

	}

	for (; *beg && flag[*beg]; ++beg);

	return pword;

}

int main()
{

	char s[N], * word; 
	int flag[256]; 
	fgets(s, N, stdin);

	Init(flag, DELIMITERS);/* инициализируем массив flag: */


	word = my_strtok2(s, flag); 
	while (word != NULL)/* разбиваем строку на слова: */
	{

		puts(word);

		free(word);

		word = my_strtok2(NULL, flag);

	}

	return 0;

}

