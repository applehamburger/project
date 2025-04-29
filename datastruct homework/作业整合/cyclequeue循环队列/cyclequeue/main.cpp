#include"cyclequeue.h"
int main() {
	SqQueue Q;
	InitQueue(Q);
	QElemType num;
	QElemType e;
	cout << "请输入元素个数：";
	cin>>num;
	cout << "请输入元素：" << endl;
	for (int i = 0; i < num; i++) {
		cin >> e;
		EnQueue(Q, e);
	}
	cout << "当前队列为：" << endl;
	ListTraverse(Q);
	
	cout << "队列长度为："<<QueueLength(Q)<<endl;
	GetHead(Q, e);
	cout << "第一个元素为："<<e << endl;

	cout << "请输入出队元素个数：";
	cin >> num;
	cout << "出队元素为：" << endl;
	for (int i = 0; i < num; i++) {
		DeQueue(Q, e);
		cout << e << " ";
	}
	cout << endl;

	cout << "当前队列为：" << endl;
	ListTraverse(Q);

	cout << "队列置空中..." <<"  ";
	if (ClearList(Q))
		cout << "已置空" << endl;

	cout << "队列销毁中..." << "  ";
	if (DestroyList(Q))
		cout << "已销毁" << endl;
	return 0;
}