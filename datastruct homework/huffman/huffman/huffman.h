#pragma once
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MaxValue 100
typedef int ElemType;
typedef int Status;
const int n = 4;//�ַ�������
typedef char** HuffCode;//�����
typedef struct {
	char word;
	int weight;
}Enode;//Ҷ���Ȩ�غͶ�Ӧ���ַ�
typedef struct {
	Enode data;
	int parent, lchild, rchild;
}HTNode;//���Ľ��
typedef struct {
	HTNode HT[2 * n - 1];
	int root;
}HuffmanTree;//��������
//������������
Status CrtHuffmanTree(HuffmanTree& T, Enode h[]);
//������������
void EncodeHT(HuffmanTree T, HuffCode& HC);
//���ַ�����ת���ɹ�������������
void EncodeStrHT(HuffCode HC, Enode t[]);
//����������������ת��Ϊ�ַ�����
void DecodeHTStr(HuffmanTree T, char* seq);