#include"linkqueue.h"
int main() {
	Qelemtype e;
	Qelemtype num;
	LinkQueue Q;
	InitQueue(Q);
	cout << "������Ԫ�ظ���:" ;
	cin >> num;
	cout << "������Ԫ��:" << endl;
	for(int i=0;i<num;i++){
		cin >> e;
		EnQueue(Q, e);
	}
	cout << "����ĿǰΪ:" << endl;
	QueueTraverse(Q);
	cout << endl;

	cout << "��һ��Ԫ��Ϊ��";
	GetHead(Q, e);
	cout << endl;


	cout << "������Ҫ���ӵ�Ԫ�ظ���:";
	cin >> num;
	for (int i = 0; i < num; i++) {
		Qelemtype de;
		DeQueue(Q, de);
	}
	cout << endl;

	cout << "����ĿǰΪ:" << endl;
	QueueTraverse(Q);
	cout << endl;

	cout << "��ʱ���г���Ϊ��";
	cout<<ListLength(Q)<<endl;
	
	
	cout << "�����ÿ���...";
	
	if(ClearQueue(Q))
		cout << "�������ÿ�" << endl;
	

	cout << "����������...";
	if (DestroyQueue(Q))
		cout << "����������" << endl;


	return 0;

	
}