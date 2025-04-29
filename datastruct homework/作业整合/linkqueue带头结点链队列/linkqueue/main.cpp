#include"linkqueue.h"
int main() {
	Qelemtype e;
	Qelemtype num;
	LinkQueue Q;
	InitQueue(Q);
	cout << "请输入元素个数:" ;
	cin >> num;
	cout << "请输入元素:" << endl;
	for(int i=0;i<num;i++){
		cin >> e;
		EnQueue(Q, e);
	}
	cout << "队列目前为:" << endl;
	QueueTraverse(Q);
	cout << endl;

	cout << "第一个元素为：";
	GetHead(Q, e);
	cout << endl;


	cout << "请输入要出队的元素个数:";
	cin >> num;
	for (int i = 0; i < num; i++) {
		Qelemtype de;
		DeQueue(Q, de);
	}
	cout << endl;

	cout << "队列目前为:" << endl;
	QueueTraverse(Q);
	cout << endl;

	cout << "此时队列长度为：";
	cout<<ListLength(Q)<<endl;
	
	
	cout << "队列置空中...";
	
	if(ClearQueue(Q))
		cout << "队列已置空" << endl;
	

	cout << "队列销毁中...";
	if (DestroyQueue(Q))
		cout << "队列已销毁" << endl;


	return 0;

	
}