#pragma warning(disable:4996)
#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

const int SIZE = 100;
#define ERROR 0
#define OK 1


//���������Ĵ洢��ʾ
typedef struct {
	int weight;    //����Ȩֵ
	int parent, lchild, rchild;//���˫�ס����ӡ��Һ��ӵ��±�
}HTNode,*HuffmanTree;   //��̬��������洢�ṹ��������
//�����������Ĵ洢��ʾ
//typedef char** HuffmanCode;//��̬��������洢�����������

int FindWeight(char code[], char p[], int w[]);
void CreateHuffmanTree(HuffmanTree& HT, int n, int w[]);
void Select(HuffmanTree& HT, int k, int &s1, int &s2);
void CreateHuffmanCode(HuffmanTree HT, int n, int q[][10],int road[]);
void HuffmanDecode(int code2[], HuffmanTree& HT, char p[], int n);
void print(int q[][10], char p[], int n);
void print2(int q[][10], char code[]);