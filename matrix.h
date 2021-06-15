#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void out(const char* a, int** s, int row, int column);
int read(const char* a, int**& s, int& row, int& column);
int* ind(int ii, int n, int** matr);
void swap(int** s, int i, int j, int column);
void sort_col(const char* a, int** s, int row, int column);