#include<iostream>
#include<fstream>
using namespace std;

typedef int Status;
typedef string Vtype;
typedef int arctype;
typedef int Elemtype;
#define Maxsize 10
#define OK 1
#define error -1

//ALGraph的数据结构定义
typedef struct Arcnode {
	int nextIndex;     //下一个邻接顶点的坐标
	struct Arcnode* nextacr;//指向下一个顶点的指针
	arctype weight;   //边权重
}ArcNode;

typedef struct Vnode {
	Vtype data;         //顶点数据
	struct Arcnode* firstacr;  //指向第一个邻接顶点的指针
}VNode,AdjList[Maxsize];  //AdiList表示邻接表类型
typedef struct AjacentTable {
	int vexnum, arcnum;
	AdjList vertices;
	int count[Maxsize];
}ALGraph;
//队列结构体
typedef struct QNode {
	Elemtype data;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}Linkqueue;
//栈结构体
typedef struct SNode {
	struct SNode* next;
	Elemtype data;
}SNode, * SLinkList;

//有向图的函数声明
Status CreateDG(ALGraph& G, ifstream& fin);//创建有向图
int LocateVex(const ALGraph& G, Vtype u);
Status CountDegree(const ALGraph& G);
int FirstAdjVex(const ALGraph& G, int i);
int NextAdjVex(const ALGraph& G, int i, int w);
bool GraphEmpty(const ALGraph G);
int Getweight(const ALGraph& G, int u, int v);
Vtype GetValue(const ALGraph& G, int i);
void DFS(ALGraph G,int i); 
void DFSTraverse(ALGraph G);//深度遍历
void BFSTraverse(ALGraph G);//广度遍历
void TopologicalSort(ALGraph& G);//拓扑排序

//队列函数声明
Status InitQueue(Linkqueue& Q);
Status EnQueue(Linkqueue& Q, Elemtype e);
Status DeQueue(Linkqueue& Q, Elemtype& e);
bool QueueEmpty(Linkqueue& Q);

//栈函数声明
Status InitStack(SLinkList& S);
Status Push(SLinkList& S, Elemtype e);
Status Pop(SLinkList& S, Elemtype &e);
bool StackEmpty(SLinkList& S);

//创建有向图
Status CreateDG(ALGraph& G,ifstream &fin) {
	Vtype v1, v2;
	fin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++) {
		fin >> G.vertices[i].data;
		G.count[i] = 0;
		G.vertices[i].firstacr = NULL;
	}
	for (int k = 0; k < G.arcnum; k++) {
		fin >> v1 >> v2;
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		ArcNode* p = new ArcNode;  //头插法
		p->nextIndex = j;
		p->nextacr = G.vertices[i].firstacr;
		G.vertices[i].firstacr = p;
		G.count[j]++;
		/*p = new ArcNode;           //再插入对称的结点
		p->nextIndex = i;
		p->nextacr = G.vertices[j].firstacr;
		G.vertices[j].firstacr = p;*/
	}
	return OK;
}
//找到一个顶点在顶点表中的位置
int LocateVex(const ALGraph& G, Vtype u) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == u)return i;
	}
	return error;   //找不到
}
//寻找下标为i的顶点的第一个邻接顶点
int FirstAdjVex(const ALGraph& G, int i) {
	if (i >= 0 && i < G.vexnum&& G.vertices[i].firstacr!=NULL)
		return G.vertices[i].firstacr->nextIndex;
	return error;
}
//寻找下标为i的顶点从下标为w的顶点开始的下一个邻接顶点
int NextAdjVex(const ALGraph& G, int i, int w) {
	if (i >= 0 && i < G.vexnum && w >= 0 && w < G.vexnum) {
		ArcNode* p = G.vertices[i].firstacr;
		while (p != NULL) {
			if (p->nextIndex == w&& p->nextacr!=NULL) {
				return p->nextacr->nextIndex;
			}
			else p = p->nextacr;
		}
	}
	return error;
}
//判空
bool GraphEmpty(const ALGraph G) {
	return G.vexnum == 0;
}
//得到下标为u,v的两顶点之间的边的权重
int Getweight(const ALGraph& G, int u, int v) {
	if (u >= 0 && u < G.vexnum && v >= 0 && v < G.vexnum) {
		ArcNode* p = G.vertices[u].firstacr;
		while (p != NULL) {
			if (p->nextIndex == v) return p->weight;
			else p = p->nextacr;
		}
	}
	return error;
}
//得到顶点表中第i+1个顶点的值
Vtype GetValue(const ALGraph& G, int i) {
	if (i >= 0 && i < G.vexnum)
		return G.vertices[i].data;
	else return "";  //Vtype是string类型，不能返回error
}
//计算各个顶点的度
Status CountDegree(const ALGraph& G) {
	for (int i = 0; i < G.vexnum; i++) {
		ArcNode* p = G.vertices[i].firstacr;
		if (p == NULL) {
			cout << G.vertices[i].data << "无邻接顶点" << endl;
			continue;
		}
		cout << G.vertices[i].data << "的邻接顶点为:";
		while (p != NULL) {
			cout << p->nextIndex;
			p = p->nextacr;
		}
		cout << endl;
	}
	return OK;
}
bool visited[Maxsize] = { false };
//深度优先遍历
void DFS(ALGraph G, int i) {
	visited[i] = true;
	cout << G.vertices[i].data << " ";
	for (int w = FirstAdjVex(G, i); w != -1; w = NextAdjVex(G, i, w)) 
		if (visited[w] == false) DFS(G, w);
	}
void DFSTraverse(ALGraph G) {
	for (int i = 0; i < G.vexnum; i++) visited[i] = false;
	for (int i = 0; i < G.vexnum; i++)
		if (visited[i] == false)
			DFS(G, i);//每次调用DFS访问一个连通图
}
//广度优先遍历
void BFSTraverse(ALGraph G) {
	Linkqueue Q;
	InitQueue(Q);
	for (int i = 0; i < G.vexnum; i++) 
		visited[i] = false;
	for (int i = 0; i < G.vexnum; i++) 
		if (!visited[i]) {
			visited[i] = true;
			EnQueue(Q, i);
			cout << G.vertices[i].data << " ";
			Elemtype e;
			while (!QueueEmpty(Q)) {
				DeQueue(Q, e);
				for (int w = FirstAdjVex(G, e); w != -1; w = NextAdjVex(G, e, w)) 
					if (!visited[w]) {
						visited[w] = true;
						EnQueue(Q, w);
						cout << G.vertices[w].data << " ";
					}				
			}
		}
}
//拓扑排序(数组栈)
void TopologicalSort1(ALGraph& G) {
	int* count = new int[G.vexnum];
	int* stack = new int[G.vexnum];
	int top = 0;//初始化栈
	for (int i = 0; i < G.vexnum; i++)
	{
		count[i] = G.count[i];//不改变图结构
		if (count[i] == 0) stack[top++] = i;

	}
	int sum = 0;
	while (top != 0)//栈非空
	{
		int gettop = stack[--top];
		sum++;
		cout << G.vertices[gettop].data << " ";
		ArcNode* p = G.vertices[gettop].firstacr;
		while (p != NULL)
		{
			int nextvex = p->nextIndex;
			if (--count[nextvex] == 0) stack[top++] = nextvex;
			p = p->nextacr;
		}
	}
	if (sum != G.vexnum) cout << "图中有回路!"<<endl;
}
//拓扑排序
void TopologicalSort(ALGraph& G) {
	int j, k, count[Maxsize] = {0};
	SLinkList S;
	InitStack(S);
	for (int i = 0; i < G.vexnum; i++) {
		count[i] = G.count[i];//防止后面用count数组的时候改变原数据
		if (count[i] == 0)
			Push(S, i);//入度为空的顶点入栈
	}
	for (int i = 0; i < G.vexnum; i++)
		if (StackEmpty(S)) {
			cout << "网络中有回路！\n";
			return;
		}
		else {
			Pop(S, j);
			cout << G.vertices[j].data <<" ";
			ArcNode* p = G.vertices[j].firstacr;
			while (p != NULL) {
				k = p->nextIndex;
				if (--count[k] == 0)
					Push(S, k);
				p = p->nextacr;
			}
		}
}

//初始化队列
Status InitQueue(Linkqueue& Q) {
	Q.rear = Q.front = new QNode;
	Q.front->next = NULL;
	return OK;
}
Status EnQueue(Linkqueue& Q, Elemtype e) {
	QueuePtr s = new QNode;
	s->data = e;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
	return OK;
}
Status DeQueue(Linkqueue& Q, Elemtype& e) {
	if (QueueEmpty(Q))return error;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	return OK;
}
bool QueueEmpty(Linkqueue& Q) {
	return Q.front == Q.rear;
}

//栈
Status InitStack(SLinkList& S) {
	S= NULL; //链栈：栈顶元素也是头元素
	return OK;
}
Status Push(SLinkList& S, Elemtype e) {
	SNode* p = new SNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
Status Pop(SLinkList& S, Elemtype &e) {
	if (StackEmpty(S))return error;
	SNode* p = S;
	S = S->next;
	e = p->data;
	delete p;
	return OK;
}
bool StackEmpty(SLinkList& S) {
	return S == NULL;
}