#include "stdafx.h"
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void shell(int *items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int *items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;

	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

/* --- компаратор для qsort --- */
int cmp(const void *a, const void *b)
{
	int x = *(const int*)a, y = *(const int*)b;
	return (x > y) - (x < y);
}

int main()
{
	setlocale(LC_ALL, "rus");
	clock_t s1, e1, s2, e2, s3, e3;
	double t1, t2, t3;

	const int N = 10000;
	int *Mas = (int*)malloc(N * sizeof(int));
	int *CopyShell = (int*)malloc(N * sizeof(int));
	int *CopyQS = (int*)malloc(N * sizeof(int));
	int *CopyStd = (int*)malloc(N * sizeof(int));
	if (!Mas || !CopyShell || !CopyQS || !CopyStd) {
		printf("Ошибка выделения памяти\n");
		return 1;
	}

	//Задание 1
	srand(time(NULL));
	for (int i = 0; i < N; i++)
		Mas[i] = -20 + rand() % 61;

	memcpy(CopyShell, Mas, N * sizeof(int));
	s1 = clock(); shell(CopyShell, N);              e1 = clock();

	memcpy(CopyQS, Mas, N * sizeof(int));
	s2 = clock(); qs(CopyQS, 0, N - 1); e2 = clock();

	memcpy(CopyStd, Mas, N * sizeof(int));
	s3 = clock(); qsort(CopyStd, N, sizeof(int), cmp); e3 = clock();

	t1 = (double)(e1 - s1) / CLOCKS_PER_SEC;
	t2 = (double)(e2 - s2) / CLOCKS_PER_SEC;
	t3 = (double)(e3 - s3) / CLOCKS_PER_SEC;
	printf("Задание 1 :\n  Shell=%f\n  QS=%f\n  qsort=%f\n",
		t1, t2, t3);

	//Задание 2
	for (int i = 0; i < N; i++) Mas[i] = i + 1;

	memcpy(CopyShell, Mas, N * sizeof(int));
	s1 = clock(); shell(CopyShell, N); e1 = clock();

	memcpy(CopyQS, Mas, N * sizeof(int));
	s2 = clock(); qs(CopyQS, 0, N - 1);  e2 = clock();

	memcpy(CopyStd, Mas, N * sizeof(int));
	s3 = clock(); qsort(CopyStd, N, sizeof(int), cmp); e3 = clock();

	t1 = (double)(e1 - s1) / CLOCKS_PER_SEC;
	t2 = (double)(e2 - s2) / CLOCKS_PER_SEC;
	t3 = (double)(e3 - s3) / CLOCKS_PER_SEC;
	printf("Задание 2 :\n  Shell=%f\n  QS=%f\n  qsort=%f\n",
		t1, t2, t3);

	//Задание 3
	for (int i = 0; i < N; i++) Mas[i] = N - i;

	memcpy(CopyShell, Mas, N * sizeof(int));
	s1 = clock(); shell(CopyShell, N); e1 = clock();

	memcpy(CopyQS, Mas, N * sizeof(int));
	s2 = clock(); qs(CopyQS, 0, N - 1); e2 = clock();

	memcpy(CopyStd, Mas, N * sizeof(int));
	s3 = clock(); qsort(CopyStd, N, sizeof(int), cmp); e3 = clock();

	t1 = (double)(e1 - s1) / CLOCKS_PER_SEC;
	t2 = (double)(e2 - s2) / CLOCKS_PER_SEC;
	t3 = (double)(e3 - s3) / CLOCKS_PER_SEC;
	printf("Задание 3 :\n  Shell=%f\n  QS=%f\n  qsort=%f\n",
		t1, t2, t3);

	// Задание 4
	for (int i = 0; i < 10000; i++)       Mas[i] = i + 1;
	for (int i = 10000; i < N; i++)       Mas[i] = N - i;

	memcpy(CopyShell, Mas, N * sizeof(int));
	s1 = clock(); shell(CopyShell, N);  e1 = clock();

	memcpy(CopyQS, Mas, N * sizeof(int));
	s2 = clock(); qs(CopyQS, 0, N - 1);  e2 = clock();

	memcpy(CopyStd, Mas, N * sizeof(int));
	s3 = clock(); qsort(CopyStd, N, sizeof(int), cmp); e3 = clock();

	t1 = (double)(e1 - s1) / CLOCKS_PER_SEC;
	t2 = (double)(e2 - s2) / CLOCKS_PER_SEC;
	t3 = (double)(e3 - s3) / CLOCKS_PER_SEC;
	printf("Задание 4 :\n  Shell=%f\n  QS=%f\n  qsort=%f\n", t1, t2, t3);

	free(Mas);
	free(CopyShell);
	free(CopyQS);
	free(CopyStd);

	_getch();
	return 0;
}