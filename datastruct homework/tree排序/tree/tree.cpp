#include<iostream>
#include<fstream>
using namespace std;
typedef int Elemtype;
ifstream fin;

typedef struct  BiTNode {
	Elemtype data;
	BiTNode* lchild, *rchild;
}BiTNode,*BiTree;


//ջ�Ķ������غ���
#define SElemType BiTNode*
#define MAXSIZE 100
#define OVERFLOW -1
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
} Sstack;
enum Status {
	ERROR,     // ִ�гɹ�
	OK  // ִ��ʧ��
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



//������ز���
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



//�������
void PreOrder(BiTree T) {
	if (T) {
		cout << T->data << " ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//�������
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		cout << T->data<<" ";
		InOrder(T->rchild);
	}
}
//�������
void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data << " ";
	}
	}
//������
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


//�ǵݹ��������
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
//�ǵݹ��������
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


//��α���
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


//����Ҷ�ӽ��
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
//�������
int NodeCount(BiTree T) {
	if (T == NULL) return 0;
	else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;

}
//���ĸ߶�
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
//��λ�ڶ��������������е�k��λ�õĽ���ֵ
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

//�ͷŶ����������н��ռ�
Status deleteBiTree(BiTree& T) {
	if (T != NULL) {
		deleteBiTree(T->lchild);
		deleteBiTree(T->rchild);
	}
	return OK;
}
//ɾ�����ͷŶ���������Ԫ��ֵΪx�Ľ����Ϊ��������
void deleteXTree(BiTree& T, Elemtype x) {
	if (T != NULL) {
		if (T->data == x) deleteBiTree(T);
		else {
			deleteXTree(T->lchild, x);
			deleteXTree(T->rchild, x);
		}
	}
}

//�����������Ĳ���
void Find(BiTree T, Elemtype x, BiTree& p, BiTree& pr) {
	if (T == NULL) { p = NULL; }
	else if (T->data == x) p = T;//p������ҵ��Ľڵ�
	else if (T->data > x) {
		pr = T;//pr���游�ڵ�
		Find(T->lchild, x, p, pr);
	}
	else {
		pr = T;
		Find(T->rchild, x, p, pr);
	}
}
//�������������루�ǵݹ飩
void Insert(BiTree& T, Elemtype x) {
	BiTNode* pt, * prt = NULL, * q;
	Find(T, x, pt, prt);
	if (pt == NULL) {
		q = new BiTNode; q->data = x;//��x����q����ڵ�
		q->lchild = q->rchild = NULL;
		if (prt == NULL) T = q;
		else if (x < prt->data) prt->lchild = q;
		else prt->rchild = q;
	}
}

//�������������루�ݹ飩
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
	cout << "������Ԫ�أ���-1����:"<<endl;
	cin >> e;
	while (e != -1) {
		Insertd(T, e);
		cin >> e;
	}
	/*PreOrderCreate(T);*/
	cout << "���������";
	PreOrder(T);
	cout << endl;
	cout << "���������" ;
	InOrder(T);
	cout << endl;
	cout << "���������";
	PostOrder(T);
	cout << endl;
	cout << "�ǵݹ����������";
	PreOrdered(T);
	cout << "�ǵݹ����������";
	InOrdered(T);
	cout << "��α�����";
	LayerOrder(T);
	cout << "���ĸ߶�Ϊ��"<< Depth(T)<<endl;
	cout << "�������Ϊ�� "<< NodeCount(T)<<endl;
	
	leaf(T);
	cout << "Ҷ�ӽ����Ϊ��"<< n<<endl;
	cout << "��Ҷ�ӽ����Ϊ��"<< NodeCount(T)- leaf(T)<<endl;

	Elemtype x;
	BiTNode* p, * pr;
	cout << "��������ҵ���x:";
	cin >> x;
	
	Find(T, x, p, pr);
	if (p!=NULL) cout << "���ҳɹ�" << endl;
	else cout << "����ʧ��" << endl;

	//Elemtype e; int c = 0; Elemtype k = 2;
	//PreorderKnode(T, k, e, c);
	//cout << "�ڶ�������ֵΪ:" <<e << endl;
	//
	//deleteXTree(T, e);
	//
	////�ͷſռ�
	//if (deleteBiTree(T))
	//	cout << "��ɾ������";

	/*fin.close();*/
	return 0;
}