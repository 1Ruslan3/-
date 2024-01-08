#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int main()
{
	srand((unsigned)time(0));
	FILE* file;
	int i, j, k = 0;
	int mas[128];
	char a;
	if ((file = fopen("Arguments.txt", "w")) != NULL)
	{
		for (j = 0; j < 128; j++)
		{
			i = (rand() % 300 + 1);
			fprintf(file, "%d ", i);
		}
	}
	else
	{
		fclose(file);
		return 1;
	}
	fclose(file);

	FILE* file2;
	if ((file2 = fopen("Arguments.txt", "r")) != NULL)
	{
		for (i = 0; i < 128; i++)
		{
			fscanf(file2, "%d", &mas[i]);
		}
	}
	else
	{
		fclose(file2);
		return 2;
	}
	fclose(file2);

	scanf("%c", &a);
	if (a == 'a')
	{
		int newmas[64];
		for (i = 1; i < 128; i += 2)
		{
			newmas[k] = mas[i];
			k++;
		}
		for (i = 0; i < 64; i++)
		{
			printf("%d ", newmas[i]);
		}
	}
	else if (a == 'b')
	{
		int newmas[128];
		j = 0;
		for (i = 0; i < 128; i++)
		{
			if (mas[i] % 2 == 0)
			{
				newmas[j] = mas[i];
				j++;
			}
		}
		k = j;
		for (j; j < 128; j++)
			newmas[j] = 0;
		for (i = 0; i < k; i++)
		{
			printf("%d ", newmas[i]);
		}
	}
	else if (a == 'c')
	{
		scanf("%d", &k);
		if (k > 127 || k < 0)
		{
			printf("The number is not in the allowed range");
			return 4;
		}
		int max = 0;
		int index = 0;
		for (i = 0; i < 128; i++)
		{
			if (abs(mas[i] - mas[k]) > max)
			{
				max = abs(mas[i] - mas[k]);
				index = i;
			}
		}
		/*for (i = 0; i < 128; i++)
		{
			printf("%d ", mas[i]);
		}*/
		printf("mas[%d] = %d	max difference = %d	index = %d	mas[%d] = %d", k, mas[k], max, index, index, mas[index]);
	}
	else if (a == 'd')
	{
		scanf("%d", &k);
		if (k > 127 || k < 0)
		{
			printf("The number is not in the allowed range");
			return 5;
		}
		int sum = 0;
		for (i = 0; i < k; i++)
			sum += mas[i];
		for (i = 0; i < 128; i++)
		{
			printf("%d ", mas[i]);
		}
		printf("\n\nmas[%d] = %d	sum = %d", k, mas[k], sum);
	}
	else if (a == 'e')
	{
		scanf("%d", &k);
		if (k > 127 || k < 0)
		{
			printf("The number is not in the allowed range");
			return 6;
		}
		int sum = 0;
		for (i = 0; i < 128; i++)
		{
			if (mas[k] > mas[i])
			{
				sum += mas[i];
			}
		}
		for (i = 0; i < 128; i++)
		{
			printf("%d ", mas[i]);
		}
		printf("\n\nmas[%d] = %d	sum = %d", k, mas[k], sum);
	}
	else
	{
		printf("The flag was entered incorrectly");
		return 3;
	}
	return 0;
}