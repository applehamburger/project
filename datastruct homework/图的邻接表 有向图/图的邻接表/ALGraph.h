#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef int Status;

#define MaxInt INT_MAX
#define MVNum 20

//定义边表节点
typedef struct ArcNode {
	int adjvex;   //邻接点编号
	int weight;   //边的权重（用于有向网）
	struct ArcNode* next;  //指向下一条边的指针
}ArcNode;

//定义顶点表节点
typedef struct VNode {
	char data;   //顶点数据
	ArcNode* firstarc;  //指向第一条依附该顶点的边的指针
	int indegree;   //入度（用于有向图）
}VNode, AdjList[MVNum];

//定义邻接表图
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;


//创建有向图
Status CreateDG(ALGraph& G);
//获取顶点在邻接表中的位置
int LocateVex(const ALGraph& G, char u);
//深度优先搜索遍历图
void DFS(const ALGraph& G, int i, bool visited[]);
//广度优先搜索遍历图
void BFS(const ALGraph& G, int i, bool visited[]);
//拓扑排序
Status TopologicalSort(ALGraph& G);