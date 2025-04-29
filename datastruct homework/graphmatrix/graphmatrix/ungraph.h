
#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;
#define MaxInt INT_MAX //����ֵ��ȡϵͳ�Դ����������
#define MVNum 20 //ͼ��󶥵���
typedef char VerTexType; //���趥�����������Ϊ�ַ���
typedef int ArcType; //����ߵ�Ȩֵ����Ϊ����


//дͼ�����ݽṹ����
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}UMGraph;

Status CreateUDG(UMGraph& G);//��������ͼ

int LocateVex(const UMGraph& G, VerTexType u);//��λ����
Status CountDegree(const UMGraph& G);//�����

int FirstAdjVex(const UMGraph& G, int v);//v�ĵ�һ���ڽӶ���
int NextAdjVex(const UMGraph& G, int v, int w);//v��w�Ժ����һ���ڽӶ��� 
//������������������Ҫ�õ��Ļ�������������GraphEmpty��Getweight��GetValue�ȡ�


void DFS(const UMGraph& G, int v, bool visited[]);
void DFSTraverse(const UMGraph& G);

void BFSTraverse(UMGraph G);
int test();
