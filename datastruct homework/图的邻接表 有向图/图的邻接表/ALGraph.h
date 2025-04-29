#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef int Status;

#define MaxInt INT_MAX
#define MVNum 20

//����߱�ڵ�
typedef struct ArcNode {
	int adjvex;   //�ڽӵ���
	int weight;   //�ߵ�Ȩ�أ�������������
	struct ArcNode* next;  //ָ����һ���ߵ�ָ��
}ArcNode;

//���嶥���ڵ�
typedef struct VNode {
	char data;   //��������
	ArcNode* firstarc;  //ָ���һ�������ö���ıߵ�ָ��
	int indegree;   //��ȣ���������ͼ��
}VNode, AdjList[MVNum];

//�����ڽӱ�ͼ
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;


//��������ͼ
Status CreateDG(ALGraph& G);
//��ȡ�������ڽӱ��е�λ��
int LocateVex(const ALGraph& G, char u);
//���������������ͼ
void DFS(const ALGraph& G, int i, bool visited[]);
//���������������ͼ
void BFS(const ALGraph& G, int i, bool visited[]);
//��������
Status TopologicalSort(ALGraph& G);