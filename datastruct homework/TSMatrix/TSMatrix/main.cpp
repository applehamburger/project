#include"TSMatrix.h"
int main() {
	TSMatrix M;
	int n;
	cout << "��������������";
	cin >> n;
	M.n = n;
	M.data = new ElemType[n * (n + 1) / 2];
	cout << "���������Ԫ�أ�";
	cout << endl;
	for (int i = 1; i <= M.n; i++) {
		for (int j = 1; j <= M.n; j++) {
			cin >> M.data[(i - 1) * M.n + (j - 1)];
		}
	}
	if (isSymmetricMatrix(M)) {
		cout << "M�ǶԳƾ���";
		cout << endl;
		ElemType* a = new ElemType[n * (n + 1) / 2];
		compressMatrix(M, a);
		cout << "ѹ�����һά����Ϊ��";
		for (int i = 0; i < n * (n + 1) / 2; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		TSMatrix N;
		N.n = n;
		restoreMatrix(a, N);
		cout << "��ԭ��ľ���Ϊ��";
		cout << endl;
		for (int i = 1; i <= N.n; i++) {
			for (int j = 1; j <= N.n; j++) {
				cout << N.data[(i - 1) * N.n + (j - 1)]<<" ";
			}
			cout << endl;
		}
    }
	else {
		cout << "M���ǶԳƾ���";
	}
	return 0;

}