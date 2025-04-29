
#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;
#define MaxInt INT_MAX //极大值，取系统自带的最大整数
#define MVNum 20 //图最大顶点数
typedef char VerTexType; //假设顶点的数据类型为字符型
typedef int ArcType; //假设边的权值类型为整型


//写图的数据结构定义
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}UMGraph;

Status CreateUDG(UMGraph& G);//创建无向图

int LocateVex(const UMGraph& G, VerTexType u);//定位顶点
Status CountDegree(const UMGraph& G);//计算度

int FirstAdjVex(const UMGraph& G, int v);//v的第一个邻接顶点
int NextAdjVex(const UMGraph& G, int v, int w);//v从w以后的下一个邻接顶点 
//这里声明其他可能需要用到的基本操作，例如GraphEmpty、Getweight、GetValue等。


void DFS(const UMGraph& G, int v, bool visited[]);
void DFSTraverse(const UMGraph& G);

void BFSTraverse(UMGraph G);
int test();
