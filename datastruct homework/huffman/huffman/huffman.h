#pragma once
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MaxValue 100
typedef int ElemType;
typedef int Status;
const int n = 4;//字符种类数
typedef char** HuffCode;//编码表
typedef struct {
	char word;
	int weight;
}Enode;//叶结点权重和对应的字符
typedef struct {
	Enode data;
	int parent, lchild, rchild;
}HTNode;//树的结点
typedef struct {
	HTNode HT[2 * n - 1];
	int root;
}HuffmanTree;//哈夫曼树
//创建哈夫曼树
Status CrtHuffmanTree(HuffmanTree& T, Enode h[]);
//求哈夫曼编码表
void EncodeHT(HuffmanTree T, HuffCode& HC);
//将字符序列转换成哈夫曼编码序列
void EncodeStrHT(HuffCode HC, Enode t[]);
//将哈夫曼编码序列转换为字符序列
void DecodeHTStr(HuffmanTree T, char* seq);