#include "triangle.h"
int main() {
	int s = 0;
	QElemType t;
	QElemType n;
	SqQueue Q;
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 0);
	cout << "ÇëÊäÈë½×Êý£º";
	cin >>n;
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++)
			cout << " ";
		while (1) {
			DeQueue(Q, t);
			if (t != 0) {
				cout << t << " ";
			}
			EnQueue(Q, s + t);
			s = t;
			if (!t) {
				EnQueue(Q, 0);
				break;
			}
		}
		cout<<endl;
	}


	return 0;
}