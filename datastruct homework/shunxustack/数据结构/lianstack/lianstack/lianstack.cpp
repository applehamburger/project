#include"lianstack.h"

//初始化
void Init(LinkStack& S)
{
	S = NULL;
}
//栈入
int Push(LinkStack& S, ElemType e)
{
	SNode* s = new SNode;
	if (!s)exit(1);
	s->data = e;
	s->next = S;
	S = s;
	return 0;
}
//栈出
int Pop(LinkStack& S, ElemType& e)
{
	if (IsEmpty(S)) {
		cout << "栈空，不能出栈" << endl;
		return false;
	}
	SNode* q = S;
	S = q->next;
	e = q->data;
	delete q;
	cout << "已弹出" << e << endl;
	return 0;
}
//取顶
int GetTop(LinkStack& S, ElemType* e)
{
	if (!S->next)return 0;

	return S->data;
}
//判空
int IsEmpty(const LinkStack& S)
{
	return S == NULL;
}
//遍历
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
//清空
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


