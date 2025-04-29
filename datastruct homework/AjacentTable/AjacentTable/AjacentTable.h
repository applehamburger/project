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

//ALGraph�����ݽṹ����
typedef struct Arcnode {
	int nextIndex;     //��һ���ڽӶ��������
	struct Arcnode* nextacr;//ָ����һ�������ָ��
	arctype weight;   //��Ȩ��
}ArcNode;

typedef struct Vnode {
	Vtype data;         //��������
	struct Arcnode* firstacr;  //ָ���һ���ڽӶ����ָ��
}VNode,AdjList[Maxsize];  //AdiList��ʾ�ڽӱ�����
typedef struct AjacentTable {
	int vexnum, arcnum;
	AdjList vertices;
	int count[Maxsize];
}ALGraph;
//���нṹ��
typedef struct QNode {
	Elemtype data;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}Linkqueue;
//ջ�ṹ��
typedef struct SNode {
	struct SNode* next;
	Elemtype data;
}SNode, * SLinkList;

//����ͼ�ĺ�������
Status CreateDG(ALGraph& G, ifstream& fin);//��������ͼ
int LocateVex(const ALGraph& G, Vtype u);
Status CountDegree(const ALGraph& G);
int FirstAdjVex(const ALGraph& G, int i);
int NextAdjVex(const ALGraph& G, int i, int w);
bool GraphEmpty(const ALGraph G);
int Getweight(const ALGraph& G, int u, int v);
Vtype GetValue(const ALGraph& G, int i);
void DFS(ALGraph G,int i); 
void DFSTraverse(ALGraph G);//��ȱ���
void BFSTraverse(ALGraph G);//��ȱ���
void TopologicalSort(ALGraph& G);//��������

//���к�������
Status InitQueue(Linkqueue& Q);
Status EnQueue(Linkqueue& Q, Elemtype e);
Status DeQueue(Linkqueue& Q, Elemtype& e);
bool QueueEmpty(Linkqueue& Q);

//ջ��������
Status InitStack(SLinkList& S);
Status Push(SLinkList& S, Elemtype e);
Status Pop(SLinkList& S, Elemtype &e);
bool StackEmpty(SLinkList& S);

//��������ͼ
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
		ArcNode* p = new ArcNode;  //ͷ�巨
		p->nextIndex = j;
		p->nextacr = G.vertices[i].firstacr;
		G.vertices[i].firstacr = p;
		G.count[j]++;
		/*p = new ArcNode;           //�ٲ���ԳƵĽ��
		p->nextIndex = i;
		p->nextacr = G.vertices[j].firstacr;
		G.vertices[j].firstacr = p;*/
	}
	return OK;
}
//�ҵ�һ�������ڶ�����е�λ��
int LocateVex(const ALGraph& G, Vtype u) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == u)return i;
	}
	return error;   //�Ҳ���
}
//Ѱ���±�Ϊi�Ķ���ĵ�һ���ڽӶ���
int FirstAdjVex(const ALGraph& G, int i) {
	if (i >= 0 && i < G.vexnum&& G.vertices[i].firstacr!=NULL)
		return G.vertices[i].firstacr->nextIndex;
	return error;
}
//Ѱ���±�Ϊi�Ķ�����±�Ϊw�Ķ��㿪ʼ����һ���ڽӶ���
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
//�п�
bool GraphEmpty(const ALGraph G) {
	return G.vexnum == 0;
}
//�õ��±�Ϊu,v��������֮��ıߵ�Ȩ��
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
//�õ�������е�i+1�������ֵ
Vtype GetValue(const ALGraph& G, int i) {
	if (i >= 0 && i < G.vexnum)
		return G.vertices[i].data;
	else return "";  //Vtype��string���ͣ����ܷ���error
}
//�����������Ķ�
Status CountDegree(const ALGraph& G) {
	for (int i = 0; i < G.vexnum; i++) {
		ArcNode* p = G.vertices[i].firstacr;
		if (p == NULL) {
			cout << G.vertices[i].data << "���ڽӶ���" << endl;
			continue;
		}
		cout << G.vertices[i].data << "���ڽӶ���Ϊ:";
		while (p != NULL) {
			cout << p->nextIndex;
			p = p->nextacr;
		}
		cout << endl;
	}
	return OK;
}
bool visited[Maxsize] = { false };
//������ȱ���
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
			DFS(G, i);//ÿ�ε���DFS����һ����ͨͼ
}
//������ȱ���
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
//��������(����ջ)
void TopologicalSort1(ALGraph& G) {
	int* count = new int[G.vexnum];
	int* stack = new int[G.vexnum];
	int top = 0;//��ʼ��ջ
	for (int i = 0; i < G.vexnum; i++)
	{
		count[i] = G.count[i];//���ı�ͼ�ṹ
		if (count[i] == 0) stack[top++] = i;

	}
	int sum = 0;
	while (top != 0)//ջ�ǿ�
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
	if (sum != G.vexnum) cout << "ͼ���л�·!"<<endl;
}
//��������
void TopologicalSort(ALGraph& G) {
	int j, k, count[Maxsize] = {0};
	SLinkList S;
	InitStack(S);
	for (int i = 0; i < G.vexnum; i++) {
		count[i] = G.count[i];//��ֹ������count�����ʱ��ı�ԭ����
		if (count[i] == 0)
			Push(S, i);//���Ϊ�յĶ�����ջ
	}
	for (int i = 0; i < G.vexnum; i++)
		if (StackEmpty(S)) {
			cout << "�������л�·��\n";
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

//��ʼ������
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

//ջ
Status InitStack(SLinkList& S) {
	S= NULL; //��ջ��ջ��Ԫ��Ҳ��ͷԪ��
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