#pragma once
#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0


typedef int Status;
typedef int Elemtype;
//三元组结构
typedef struct {
	int i;//行
	int j;//列
	Elemtype e;//非零元值
}Triple;

//稀疏矩阵结构
typedef struct {
	int mu;//行数
	int nu;//列数
	int tu;//非零元个数
	Triple data[MAXSIZE + 1];
}TSMatrix;

Status InitMatrix(TSMatrix& M, int rows, int cols);
Status TransposeMatrix(TSMatrix M, TSMatrix& T);
void TraversMatrix(const TSMatrix& M);
Status FastTransMatrix(TSMatrix& T, TSMatrix& C);