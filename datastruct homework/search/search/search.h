#pragma once
#include<iostream>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
using namespace std;
typedef int KeyType;
typedef int Status;
typedef struct {
	KeyType key;//关键字域
	//InfoType otherinfo;//其他域
}ElemType;

typedef struct {
	ElemType* elem;//数据元素存储空间基址，0号单元不留空
	int length;//表长度
}SSTable;

Status InitList(SSTable& ST);
void CreateST(SSTable& ST, int n);
//顺序表的顺序查找
int Search_Seq(SSTable ST, KeyType key);
//递归算法
int SeqSearch(SSTable ST, KeyType x, int loc);
//冒泡排序
void bubble_sort(SSTable& ST, int n);
//遍历
void Traverse(SSTable ST);
//有序表的折半查找
//非递归
int Search_Bin(SSTable ST, KeyType key);
//递归
int BinSearch(SSTable ST, KeyType x, int low, int high);