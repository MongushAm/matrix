#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void out(const char* a, int** s, int row, int column) {
	FILE* f;
	f = fopen(a, "w");
	if (f == NULL) {
		puts("Open file error");
		return;
	}
	else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				fprintf(f, "%d", s[i][j]);
				if (j != column - 1)
					fprintf(f, "C:\\Users\\huawei\\source\\repos\\matrix2\\Matr.txt");
			}
			if (i != row - 1)
				fprintf(f, "\n");
		}
		fclose(f);
	}
}

int read(const char* a, int**& s, int& row, int& column) {
	FILE* f;
	f = fopen(a, "rt");
	if (f == NULL) {
		puts("Open file error");
		return -1;
	}
	else {
		if (fscanf(f, "%d", &row) == 0)
			return -1;
		if (fscanf(f, "%d", &column) == 0)
			return -1;
		int i;
		s = (int**)realloc(s, sizeof(int*) * row);
		if (s == NULL)
			return -1;
		for (i = 0; i < row; i++)
			s[i] = NULL;
		for (i = 0; i < row; i++) {
			s[i] = (int*)realloc(s[i], column * sizeof(int));
			if (s[i] == NULL)
				return -1;
		}


		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (fscanf(f, "%d", &s[i][j]) == 0)
					return -1;
			}
		}
		fclose(f);
	}
	return 0;
}

int* ind(int ii, int n, int** matr) {
	int* iP = matr[ii / n];
	int j = ii % n;
	j = (ii / n) & 1 ? n - j - 1 : j;
	return iP + j;
}

void swap(int** s, int i, int j, int column) {
	for (int k = 0; k < column; k++) {
		int tmp = s[i][k];
		s[i][k] = s[j][k];
		s[j][k] = tmp;
	}
}

void sort_col(const char* a, int** s, int row, int column) {
	for (int i = 0; i < row - 1; i++) {
		for (int j = i + 1; j < row; j++) {
			if (s[i][0] < s[j][0])
				swap(s, i, j, column);
		}
	}
	out(a, s, row, column);
}