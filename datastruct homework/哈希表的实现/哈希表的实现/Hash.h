#pragma once
#include<iostream>
using namespace std;

//���ŵ�ַ��ɢ�б�Ĵ洢��ʾ
#define m 20    //ɢ�б�ı�
typedef int KeyType;
typedef int InfoType;
typedef struct HashNode{
	KeyType key;//�ؼ�����
	InfoType otherinfo;//����������
	struct HashNode* next;
}HashNode;

typedef struct {
	HashNode data[m];//��ϣ�������
	int count[m];//����ĳ���
}HashTable;

//��ʼ����ϣ��
void InitHashTable(HashTable& HT);
//����Ԫ�ص���ϣ��
void Insert(HashTable& HT, KeyType key, InfoType otherinfo);
//����Ԫ���ڹ�ϣ���е�λ�û�
int Search(HashTable& HT, KeyType key);
