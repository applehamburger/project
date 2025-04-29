#include"lianstack.h"

int main() {
	LinkStack S;
	ElemType e = 0;
	//1����ʼ��һ��ջ��
	Init(S);
	//2��������ջ1, 2, 3, 4, 5��6
	for (int i = 1; i <= 6; i++) {
		Push(S, i);
	}
	//3���鿴ջ��Ԫ�ز���ӡ
	cout << "ջ��Ϊ" << GetTop(S, &e) << endl;
	//4������
	Traverse(S);
	//5����ջ6�Σ�����ӡ��ջ�����ݣ�������ܳ�ջ����Ļ�������ջ�գ����ܳ�ջ��
	for (int i = 1; i <= 6; i++) {
		Pop(S, e);
	}
	//6��������ջ1, 2, 3, 4, 5, 6
	for (int i = 1; i <= 6; i++) {
		Push(S, i);
	}
	//7�����ջ
	Clear(S);
	//8������ջ
	Destory(S);
}