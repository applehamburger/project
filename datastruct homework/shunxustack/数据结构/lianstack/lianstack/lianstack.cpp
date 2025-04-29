#include"lianstack.h"

//��ʼ��
void Init(LinkStack& S)
{
	S = NULL;
}
//ջ��
int Push(LinkStack& S, ElemType e)
{
	SNode* s = new SNode;
	if (!s)exit(1);
	s->data = e;
	s->next = S;
	S = s;
	return 0;
}
//ջ��
int Pop(LinkStack& S, ElemType& e)
{
	if (IsEmpty(S)) {
		cout << "ջ�գ����ܳ�ջ" << endl;
		return false;
	}
	SNode* q = S;
	S = q->next;
	e = q->data;
	delete q;
	cout << "�ѵ���" << e << endl;
	return 0;
}
//ȡ��
int GetTop(LinkStack& S, ElemType* e)
{
	if (!S->next)return 0;

	return S->data;
}
//�п�
int IsEmpty(const LinkStack& S)
{
	return S == NULL;
}
//����
void Traverse(const LinkStack& S)
{
	SNode* p;
	p = S;
	while (p != NULL) {
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}
//���
void Clear(LinkStack& L) {
	SNode* p = L;
	while (p != NULL) {
		SNode* temp = p;
		p = p->next;
		delete temp;
	}
	L = NULL;
}
//xiaohui
void Destory(LinkStack& L) {
	SNode* p = L;
	while (p != NULL) {
		SNode* temp = p;
		p = p->next;
		delete temp;
	}
	L = NULL;
}


