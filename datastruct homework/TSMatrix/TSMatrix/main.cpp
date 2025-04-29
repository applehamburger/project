#include"TSMatrix.h"
int main() {
	TSMatrix M;
	int n;
	cout << "请输入矩阵阶数：";
	cin >> n;
	M.n = n;
	M.data = new ElemType[n * (n + 1) / 2];
	cout << "请输入矩阵元素：";
	cout << endl;
	for (int i = 1; i <= M.n; i++) {
		for (int j = 1; j <= M.n; j++) {
			cin >> M.data[(i - 1) * M.n + (j - 1)];
		}
	}
	if (isSymmetricMatrix(M)) {
		cout << "M是对称矩阵！";
		cout << endl;
		ElemType* a = new ElemType[n * (n + 1) / 2];
		compressMatrix(M, a);
		cout << "压缩后的一维数组为：";
		for (int i = 0; i < n * (n + 1) / 2; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		TSMatrix N;
		N.n = n;
		restoreMatrix(a, N);
		cout << "还原后的矩阵为：";
		cout << endl;
		for (int i = 1; i <= N.n; i++) {
			for (int j = 1; j <= N.n; j++) {
				cout << N.data[(i - 1) * N.n + (j - 1)]<<" ";
			}
			cout << endl;
		}
    }
	else {
		cout << "M不是对称矩阵！";
	}
	return 0;

}