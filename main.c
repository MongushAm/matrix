#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "matrix.h"

int main() {
	int** s = NULL;
	int row = 0, column = 0;
	int rez = read("C:\\Users\\huawei\\source\\repos\\matrix2\\Matr.txt", s, row, column);
	if (rez == -1)
		return -1;
	sort_col("C:\\Users\\huawei\\source\\repos\\matrix2\\Matr_out.txt", s, row, column);
	return 0;
}