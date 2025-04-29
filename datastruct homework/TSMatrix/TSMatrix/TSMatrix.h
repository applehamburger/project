#pragma once
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct {
	ElemType *data;
	int n;
}TSMatrix;
bool isSymmetricMatrix(TSMatrix M);
void compressMatrix(TSMatrix M, ElemType *a);
void restoreMatrix(ElemType* a,TSMatrix& M);




