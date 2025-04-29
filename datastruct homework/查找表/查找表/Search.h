#pragma once
#include<iostream>
using namespace std;
#define MAXSIZE 100

#define OK 1
#define ERROR 0

typedef int KeyType;

typedef struct {
	KeyType key;//�ؼ�����
	//InfoType otherinfo;//������
}ElemType;

typedef struct {
	ElemType* elem;//����Ԫ�ش洢�ռ��ַ��0�ŵ�Ԫ������
	int length;//����
}SSTable;

void InitSSTable(SSTable& ST);
void CreateSSTable(SSTable& ST, int n);
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