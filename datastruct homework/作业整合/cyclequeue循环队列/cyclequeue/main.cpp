#include"cyclequeue.h"
int main() {
	SqQueue Q;
	InitQueue(Q);
	QElemType num;
	QElemType e;
	cout << "������Ԫ�ظ�����";
	cin>>num;
	cout << "������Ԫ�أ�" << endl;
	for (int i = 0; i < num; i++) {
		cin >> e;
		EnQueue(Q, e);
	}
	cout << "��ǰ����Ϊ��" << endl;
	ListTraverse(Q);
	
	cout << "���г���Ϊ��"<<QueueLength(Q)<<endl;
	GetHead(Q, e);
	cout << "��һ��Ԫ��Ϊ��"<<e << endl;

	cout << "���������Ԫ�ظ�����";
	cin >> num;
	cout << "����Ԫ��Ϊ��" << endl;
	for (int i = 0; i < num; i++) {
		DeQueue(Q, e);
		cout << e << " ";
	}
	cout << endl;

	cout << "��ǰ����Ϊ��" << endl;
	ListTraverse(Q);

	cout << "�����ÿ���..." <<"  ";
	if (ClearList(Q))
		cout << "���ÿ�" << endl;

	cout << "����������..." << "  ";
	if (DestroyList(Q))
		cout << "������" << endl;
	return 0;
}