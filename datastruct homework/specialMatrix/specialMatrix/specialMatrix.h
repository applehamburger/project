#pragma once
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType* data;
	int length;
}SMatrix;


bool IsSymmetricMatrix(SMatrix M);
Status CompressMatrix(const SMatrix& M, ElemType* arry);
Status RestoreMatrix(ElemType* arry, SMatrix& M);
Status TraverseMatrix(const SMatrix& M);
