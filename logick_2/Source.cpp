#define _CRT_SECURE_NO_WARNINGS
#include "StdAfx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <malloc.h>
#include <fstream>
using namespace std;

int compare(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}
void shell(int* items, int count)
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
void qs(int* items, int left, int right)
{
	
	int i, j;
	int x, y;

	i = left; j = right;
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
	} 	while (i <= j); {
		if (left < j) {
			qs(items, left, j);
		}
		if (i < right) {
			qs(items, i, right);
		}
	}

}

int zadanie1(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t start, end;

	start = clock();
	int i = 0, j = 0, r, n = 800, m = 800;
	int elem_c;
	int** a, ** b, ** c;

	srand(time(NULL));

	a = (int**)malloc(n * sizeof(int*));
	while (i < n) {
		a[i] = (int*)malloc(m * sizeof(int*));
		while (j < m) {
			a[i][j] = rand() % 100 + 1;
			j++;
		}
		i++;
	}

	srand(time(NULL));
	i = 0; j = 0;

	b = (int**)malloc(n * sizeof(int*));
	while (i < n) {
		b[i] = (int*)malloc(m * sizeof(int*));
		while (j < m) {
			b[i][j] = rand() % 100 + 1;
			j++;
		}
		i++;
	}

	c = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		c[i] = (int*)malloc(m * sizeof(int*));
		for (j = 0; j < m; j++) {
			elem_c = 0;
			for (r = 0; r < n; r++) {
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		free(a[i]);
		free(b[i]);
		free(c[i]);
	}
	free(a);
	free(b);
	free(c);
	end = clock();
	float diff = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Matrix n*m = " << n << " " << "Time = " << diff << endl;
	return(0);
}

void q_two_one() {
	clock_t start_s, end_s, start_q, end_q;
	int count = 100000;
	cout << "Nomer 2_1" << endl;
	cout << "Count = 100000" << endl;

	int* items(NULL);
	items = (int*)malloc(count * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < count; i++)
		items[i] = rand() % 100 + 1;
	start_s = clock();
	shell(items, count);
	end_s = clock();
	cout << fixed;
	cout.precision(12);
	float diffqss = (float)(end_s - start_s) / CLOCKS_PER_SEC;
	cout << "Vremya shell_1 = " << diffqss << endl;
	cout << "Massive_shell = " << count << " " << "Time = " << diffqss << endl;

	int* items_q(NULL);
	items_q = (int*)malloc(count * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < count; i++)
		items_q[i] = rand() % 100 + 1;
	start_q = clock();
	qs(items_q, 0, count - 1);
	end_q = clock();
	float diffqs = (float)(end_q - start_q) / CLOCKS_PER_SEC;
	cout << "Massive_qs = " << count << " " << "Time = " << diffqs << endl;
	free(items);
}
void q_two_two() {
	
	clock_t start_s, end_s, start_q, end_q;
	int count = 200000;
	cout << "Nomer 2_2" << endl;
	cout << "Count = 200000" << endl;

	int* items(NULL);
	items = (int*)malloc(count * sizeof(int));
	for (int i = 0; i < count; i++)
		items[i] = count - i;
	start_s = clock();
	shell(items, count);
	end_s = clock();
	cout << fixed;
	cout.precision(12);
	float diffqss = (float)(end_s - start_s) / CLOCKS_PER_SEC;
	cout << "Massive_shell_2 = " << count << " " << "Time = " << diffqss << endl;

	int* items_q(NULL);
	items_q = (int*)malloc(count * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < count; i++)
		items_q[i] = count - i;
	start_q = clock();
	qs(items_q, 0, count - 1);
	end_q = clock();
	float diffqs = (float)(end_q - start_q) / CLOCKS_PER_SEC;
	cout << "Massive_qs_2 = " << count << " " << "Time = " << diffqs << endl;
	free(items);
}
void q_two_three() {
	
	clock_t start_s, end_s, start_q, end_q;
	int count = 150000;
	cout << "Nomer 2_3" << endl;
	cout << "Count = 150000" << endl;

	int* items(NULL);
	items = (int*)malloc(count * sizeof(int));
	for (int i = 0; i < count; i++) {
		items[i] = count + i;
	}
	start_s = clock();
	shell(items, count);
	end_s = clock();
	cout << fixed;
	cout.precision(12);
	float diffqss = (float)(end_s - start_s) / CLOCKS_PER_SEC;
	cout << "Massive_shell_3 = " << count << " " << "Time = " << diffqss << endl;
	
	int* items_q(NULL);
	items_q = (int*)malloc(count * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		items_q[i] = count + i;
	}
	start_q = clock();
	qs(items_q, 0, count - 1);
	end_q = clock();
	float diffqs = (float)(end_q - start_q) / CLOCKS_PER_SEC;
	cout << "Massive_qs_3 = " << count << " " << "Time = " << diffqs << endl;
	free(items);
}
void q_two_four() {

	clock_t start_s, end_s, start_q, end_q;
	int count = 100000;
	cout << "Nomer 2_4" << endl;
	cout << "Count = 100000" << endl;

	int* items(NULL);
	items = (int*)malloc(count * sizeof(int));

	for (int i = 0; i < count; i++) {
		if (i < (count / 2)) {
			items[i] = count + i;
		}
		else {
			items[i] = count - i;
		}
	}

	start_s = clock();
	shell(items, count);
	end_s = clock();
	cout << fixed;
	cout.precision(12);
	float diffqss = (float)(end_s - start_s) / CLOCKS_PER_SEC;
	cout << "Massive_shell_4 = " << count << " " << "Time = " << diffqss << endl;
	

	int* items_q(NULL);
	items_q = (int*)malloc(count * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		if (i < (count / 2)) {
			items_q[i] = count + i;
		}
		else {
			items_q[i] = count - i;
		}
	}
	start_q = clock();
	qs(items_q, 0, count - 1);
	end_q = clock();
	float diffqs = (float)(end_q - start_q) / CLOCKS_PER_SEC;
	cout << "Vremya qs_4 = " << diffqs << endl;
	
	cout << "Massive_qs_4 = " << count << " " << "Time = " << diffqs << endl;

	free(items);
}

void q_two_five_one() {
	clock_t start, end;
	int count = 50000;
	cout << "Nomer 2_5_1" << endl;
	cout << "Count = 50000" << endl;

	int* items(NULL);
	items = (int*)malloc(count * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < count; i++)
		items[i] = rand() % 100 + 1;
	start = clock();
	qsort(items, count, sizeof(int), compare);
	end = clock();
	float diffqs = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Vremya qsort_1 = " << diffqs << endl;
	cout << "Massive_qsort_1 = " << count << " " << "Time = " << diffqs << endl;
	
	
}
void q_two_five_two() {
	clock_t start, end;
	int count = 75000;
	cout << "Nomer 2_5_2" << endl;
	cout << "Count = 75000" << endl;

	int* items(NULL);
	items = (int*)malloc(count * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		items[i] = count + i;
	}
	start = clock();
	qsort(items, count, sizeof(int), compare);
	end = clock();
	float diffqs = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Vremya qsort_2 = " << diffqs << endl;

	cout << "Massive_qsort_2 = " << count << " " << "Time = " << diffqs << endl;
	
}
void q_two_five_three() {
	clock_t start, end;
	int count = 100000;
	cout << "Nomer 2_5_3" << endl;
	cout << "Count = 100000" << endl;

	int* items(NULL);
	items = (int*)malloc(count * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		items[i] = count - i;
	}
	start = clock();
	qsort(items, count, sizeof(int), compare);
	end = clock();
	float diffqs = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Vremya qsort_3 = " << diffqs << endl;
	cout << "Massive_qsort_3 = " << count << " " << "Time = " << diffqs << endl;
}
void q_two_five_four() {
	clock_t start, end;
	int count = 125000;
	cout << "Nomer 2_5_4" << endl;
	cout << "Count = 125000" << endl;

	int* items(NULL);
	items = (int*)malloc(count * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		if (i < (count / 2)) {
			items[i] = count + i;
		}
		else {
			items[i] = count - i;
		}
	}
	start = clock();
	qsort(items, count, sizeof(int), compare);
	end = clock();
	float diffqs = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Vremya qsort_4 = " << diffqs << endl;
	cout << "Massive_qsort_4 = " << count << " " << "Time = " << diffqs << endl;
}

int main() {
	ofstream out;
	freopen("test.txt", "w", stdout);
	zadanie1();
	q_two_one();
	cout << endl;
	q_two_two();
	cout << endl;
	q_two_three();
	cout << endl;
	q_two_four();
	cout << endl;
	q_two_five_one();
	cout << endl;
	q_two_five_two();
	cout << endl;
	q_two_five_three();
	cout << endl;
	q_two_five_four();
	cout << endl;
	out.close();
	system("pause");
}
