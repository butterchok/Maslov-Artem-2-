#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 3
#define MAX_COLUMNS 4

typedef struct {
    int rows;
    int columns;
    int* data;
} DArray;

DArray createDArray(int rows, int columns) {
    DArray arr;
    arr.rows = rows;
    arr.columns = columns;
    arr.data = (int*)malloc(rows * columns * sizeof(int));

    if (arr.data == NULL) {
        printf("ERROR: memory alloc failed\n");
        exit(1);
    }

    return arr;
}

void setElement(DArray* arr, int row, int column, int val) {
    if (row >= 0 && row < arr->rows && column >= 0 && column < arr->columns) {
        *(arr->data + (row * arr->columns) + column) = val;
    }
    else {
        printf("ERROR: Out of range\n");
        exit(1);
    }
}

int getElement(DArray* arr, int row, int column) {
    return *(arr->data + (row * arr->columns) + column);
}

void freeDArray(DArray* arr) {
    free(arr->data);
}

int main() {
    DArray arr = createDArray(MAX_ROWS, MAX_COLUMNS);

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            setElement(&arr, i, j, i * MAX_COLUMNS + j);
        }
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            printf("%d ", getElement(&arr, i, j));
        }
        printf("\n");
    }

    freeDArray(&arr);

    return 0;
}
