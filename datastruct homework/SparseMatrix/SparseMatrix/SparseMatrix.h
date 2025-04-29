#pragma once
#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0


typedef int Status;
typedef int Elemtype;
//��Ԫ��ṹ
typedef struct {
	int i;//��
	int j;//��
	Elemtype e;//����Ԫֵ
}Triple;

//ϡ�����ṹ
typedef struct {
	int mu;//����
	int nu;//����
	int tu;//����Ԫ����
	Triple data[MAXSIZE + 1];
}TSMatrix;

Status InitMatrix(TSMatrix& M, int rows, int cols);
Status TransposeMatrix(TSMatrix M, TSMatrix& T);
void TraversMatrix(const TSMatrix& M);
Status FastTransMatrix(TSMatrix& T, TSMatrix& C);