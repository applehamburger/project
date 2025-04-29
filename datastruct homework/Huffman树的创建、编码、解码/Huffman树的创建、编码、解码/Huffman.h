#pragma warning(disable:4996)
#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

const int SIZE = 100;
#define ERROR 0
#define OK 1


//哈夫曼树的存储表示
typedef struct {
	int weight;    //结点的权值
	int parent, lchild, rchild;//结点双亲、左孩子、右孩子的下标
}HTNode,*HuffmanTree;   //动态分配数组存储结构哈夫曼树
//哈夫曼编码表的存储表示
//typedef char** HuffmanCode;//动态分配数组存储哈夫曼编码表

int FindWeight(char code[], char p[], int w[]);
void CreateHuffmanTree(HuffmanTree& HT, int n, int w[]);
void Select(HuffmanTree& HT, int k, int &s1, int &s2);
void CreateHuffmanCode(HuffmanTree HT, int n, int q[][10],int road[]);
void HuffmanDecode(int code2[], HuffmanTree& HT, char p[], int n);
void print(int q[][10], char p[], int n);
void print2(int q[][10], char code[]);