#pragma once
#include<iostream>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
using namespace std;
typedef int KeyType;
typedef int Status;
typedef struct {
	KeyType key;//�ؼ�����
	//InfoType otherinfo;//������
}ElemType;

typedef struct {
	ElemType* elem;//����Ԫ�ش洢�ռ��ַ��0�ŵ�Ԫ������
	int length;//����
}SSTable;

Status InitList(SSTable& ST);
void CreateST(SSTable& ST, int n);
//˳����˳�����
int Search_Seq(SSTable ST, KeyType key);
//�ݹ��㷨
int SeqSearch(SSTable ST, KeyType x, int loc);
//ð������
void bubble_sort(SSTable& ST, int n);
//����
void Traverse(SSTable ST);
//�������۰����
//�ǵݹ�
int Search_Bin(SSTable ST, KeyType key);
//�ݹ�
int BinSearch(SSTable ST, KeyType x, int low, int high);