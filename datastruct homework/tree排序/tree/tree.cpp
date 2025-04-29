#include<iostream>
#include<fstream>
using namespace std;
typedef int Elemtype;
ifstream fin;

typedef struct  BiTNode {
	Elemtype data;
	BiTNode* lchild, *rchild;
}BiTNode,*BiTree;


//栈的定义和相关函数
#define SElemType BiTNode*
#define MAXSIZE 100
#define OVERFLOW -1
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
} Sstack;
enum Status {
	ERROR,     // 执行成功
	OK  // 执行失败
};
Status InitStack(Sstack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(Sstack& S, BiTNode* e) {
	if (S.top - S.base == S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(Sstack& S, BiTNode*& e) {
	if (S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}
bool StackEmpty(const Sstack& S) {
	if (S.top == S.base)
		return true;
	else
		return false;
}
Status Traverse(const Sstack& S) {

	int i;
	for (i = 0; i < (S.top - S.base); i++) {
		cout << S.base[i] << " ";
	}
	cout << endl;
	return OK;
}



//队列相关操作
typedef BiTree QElemType;
typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}
Status QueueTraverse(LinkQueue Q) {
	QueuePtr p = Q.front->next;
	while (p != NULL) {
		cout << p->data->data << " ";
		p = p->next;
	}
	cout << endl;
	return OK;
}
Status EnQueue(LinkQueue& Q, QElemType e) {
	QueuePtr p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
bool isEmpty(const LinkQueue& Q) {
	return Q.front == Q.rear;
}
Status DeQueue(LinkQueue& Q, QElemType& e) {
	if (isEmpty(Q)) return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
	return OK;
}



//先序遍历
void PreOrder(BiTree T) {
	if (T) {
		cout << T->data << " ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//中序遍历
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		cout << T->data<<" ";
		InOrder(T->rchild);
	}
}
//后序遍历
void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data << " ";
	}
	}
//创建树
void PreOrderCreate(BiTree& T) {
	char c;
	fin >> c;
	if (c == '#')
		T = NULL;
	else {
		T = new BiTNode;
		T->data = c;
		PreOrderCreate(T->lchild);
		PreOrderCreate(T->rchild);
	}
}


//非递归先序遍历
void PreOrdered(BiTree T) {
	Sstack S;
	InitStack(S);
	BiTNode* p = T;
	while (p != NULL || S.top != S.base) {
		if (p != NULL) {
			cout << p->data<<" ";
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S, p);
			p = p->rchild;
		}
	}
	cout << endl;
}
//非递归中序遍历
void InOrdered(BiTree T) {
	Sstack S;
	InitStack(S);
	BiTree p = T;
	do {
		while (p != NULL) {
			Push(S, p);
			p = p->lchild;
		}
		if (!StackEmpty(S)) {
			Pop(S, p);
			cout << p->data<<" ";
			p = p->rchild;
		}
	} while (p != NULL || !StackEmpty(S));
	cout << endl;
}


//层次遍历
void LayerOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);
	BiTree p = T;
	if (p) {
		EnQueue(Q, p);
		while (!isEmpty(Q)) {
			DeQueue(Q, p);
			cout << p->data<<" ";
			if (p->lchild)
				EnQueue(Q, p->lchild);
			if (p->rchild)
				EnQueue(Q, p->rchild);
		}
	}
	cout << endl;
}


//计算叶子结点
int n = 0;
Status leaf(BiTree T) {
	if (T != NULL) {
		if (T->lchild == NULL && T->rchild == NULL)
			n++;
		leaf(T->lchild);
		leaf(T->rchild);
	}
	
	return OK;
}
//结点总数
int NodeCount(BiTree T) {
	if (T == NULL) return 0;
	else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;

}
//树的高度
int Depth(BiTree T)
{
	int m, n;
	if (T == NULL)
		return 0;
	else {
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		if (m > n) return (m + 1);
		else return (n + 1);
	}
}
//求位于二叉树先序序列中第k个位置的结点的值
Status PreorderKnode(BiTree T,int k, Elemtype& e, int& count) {
	if (T == NULL) return ERROR;
	count++;
	if (count == k) {
		e = T->data;
		return OK;
	}
	else if (count > k) return ERROR;
	else {
		if (PreorderKnode(T->lchild,k, e, count) == ERROR)
			return PreorderKnode(T->rchild,k, e, count);
		return OK;
	}

}

//释放二叉树的所有结点空间
Status deleteBiTree(BiTree& T) {
	if (T != NULL) {
		deleteBiTree(T->lchild);
		deleteBiTree(T->rchild);
	}
	return OK;
}
//删除并释放二叉树中以元素值为x的结点作为根的子树
void deleteXTree(BiTree& T, Elemtype x) {
	if (T != NULL) {
		if (T->data == x) deleteBiTree(T);
		else {
			deleteXTree(T->lchild, x);
			deleteXTree(T->rchild, x);
		}
	}
}

//二叉排序树的查找
void Find(BiTree T, Elemtype x, BiTree& p, BiTree& pr) {
	if (T == NULL) { p = NULL; }
	else if (T->data == x) p = T;//p保存查找到的节点
	else if (T->data > x) {
		pr = T;//pr保存父节点
		Find(T->lchild, x, p, pr);
	}
	else {
		pr = T;
		Find(T->rchild, x, p, pr);
	}
}
//二叉排序树插入（非递归）
void Insert(BiTree& T, Elemtype x) {
	BiTNode* pt, * prt = NULL, * q;
	Find(T, x, pt, prt);
	if (pt == NULL) {
		q = new BiTNode; q->data = x;//把x存入q这个节点
		q->lchild = q->rchild = NULL;
		if (prt == NULL) T = q;
		else if (x < prt->data) prt->lchild = q;
		else prt->rchild = q;
	}
}

//二叉排序树插入（递归）
void Insertd(BiTree& T, Elemtype x) {
	BiTNode* S;
	if (!T) {
		S = new BiTNode;
		S->data = x;
		S->lchild = S->rchild = NULL;
		T = S;

	}
	else if (x < T->data)
		Insertd(T->lchild, x);
	else if (x > T->data)
		Insertd(T->rchild, x);

}


int main() {
	Elemtype e;
	BiTree T = NULL;
	cout << "请输入元素，以-1结束:"<<endl;
	cin >> e;
	while (e != -1) {
		Insertd(T, e);
		cin >> e;
	}
	/*PreOrderCreate(T);*/
	cout << "先序遍历：";
	PreOrder(T);
	cout << endl;
	cout << "中序遍历：" ;
	InOrder(T);
	cout << endl;
	cout << "后序遍历：";
	PostOrder(T);
	cout << endl;
	cout << "非递归先序遍历：";
	PreOrdered(T);
	cout << "非递归中序遍历：";
	InOrdered(T);
	cout << "层次遍历：";
	LayerOrder(T);
	cout << "树的高度为："<< Depth(T)<<endl;
	cout << "结点总数为： "<< NodeCount(T)<<endl;
	
	leaf(T);
	cout << "叶子结点数为："<< n<<endl;
	cout << "非叶子结点数为："<< NodeCount(T)- leaf(T)<<endl;

	Elemtype x;
	BiTNode* p, * pr;
	cout << "请输入查找的数x:";
	cin >> x;
	
	Find(T, x, p, pr);
	if (p!=NULL) cout << "查找成功" << endl;
	else cout << "查找失败" << endl;

	//Elemtype e; int c = 0; Elemtype k = 2;
	//PreorderKnode(T, k, e, c);
	//cout << "第二个结点的值为:" <<e << endl;
	//
	//deleteXTree(T, e);
	//
	////释放空间
	//if (deleteBiTree(T))
	//	cout << "已删除该树";

	/*fin.close();*/
	return 0;
}