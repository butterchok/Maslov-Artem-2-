#pragma once

#include <stdlib.h>

typedef struct {
	int rows;
	int column;
	int* data;
} DArray;

DArray createDArray(int rows, int column) {
	DArray arr;
	arr.rows = rows;
	arr.column = column;
	arr.data = (int*)malloc(rows * column * sizeof(int));
	return arr;
}

//void setElement(DArray arr, int row, int column, int val) {
//	*(arr.data + (row * arr.column) + column) = val;
//}

void setElement(DArray arr, int row, int column, int val) {
	if (row >= 0 && row < arr.rows && column >= 0 && column < arr.column) {
		*(arr.data + (row * arr.column) + column) = val;
	}
	else {
		printf("ERROR: out of range\n");
		exit(1);
	}
}

int getElement(DArray arr, int row, int column) {
	return *(arr.data + (row * arr.column) + column);
}

void freeDArray(DArray arr) {
	free(arr.data);
}
