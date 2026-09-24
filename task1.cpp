#include "stdafx.h"
#include <conio.h>;
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setlocale(LC_ALL,"RUS");
	clock_t start1, end,start2; // объявляем переменные для определения времени выполнения
	start1 = clock();
	int i = 0, j = 0, r;
	static int a[10000][10000], b[10000][10000], c[10000][10000], elem_c;

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i<10000)
	{
		while (j<10000)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i<10000)
	{
		while (j<10000)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	start2 = clock();

	for (i = 0; i<10000; i++)
	{
		for (j = 0; j<10000; j++)
		{
			elem_c = 0;
			for (r = 0; r<10000; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	end = clock();
	double t2 = (double)(end - start1) / CLOCKS_PER_SEC;
	double t1 = (double)(end - start2) / CLOCKS_PER_SEC;
	printf("Время выполнения программы:%f\n Время выполнения перемножения:%f",t2,t1);

	_getch();
	return(0);
}
