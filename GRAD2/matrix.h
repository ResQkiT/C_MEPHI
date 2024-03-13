#pragma once
#include "fieldinfo.h"
typedef struct
{
    int m;
    int n;
    int* data;
    FieldInfo* impl;
} Matrix;
//Аргументы: (Количество строк, количество столбцов, имплементация )
Matrix* newMatrix(int, int, FieldInfo*);

void* get(Matrix*, int, int);
void set(Matrix*, int, int, void*);

void printMatrix(Matrix*);
void readMatrix(Matrix*);
void zeros(Matrix *);