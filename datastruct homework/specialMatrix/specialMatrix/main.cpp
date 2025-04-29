#include "specialMatrix.h"

int main() {
	ElemType n;
	ElemType e;
	
	SMatrix M;
	SMatrix S;

	cout << "请输入矩阵M阶数 ";
	cin >> n;
	M.data = new  ElemType[n * (n + 1) / 2];//建立存储空间，将指针赋值给data成员
	M.length = n;
	cout << "请输入矩阵元素 "<<endl;
	for (int i = 0; i < M.length; i++) {
		for (int j = 0; j < M.length; j++) {
			cin >> e;
			M.data[i * n + j]=e;
			}
		}
	cout << "当前矩阵为" << endl;
	TraverseMatrix(M);
	if (IsSymmetricMatrix(M)) {
		ElemType* arry = new ElemType[n * (n + 1) / 2];
		cout << "该矩阵是对称矩阵" << endl;

		CompressMatrix(M, arry);
		cout << "压缩后的一维数组为：" << endl;
		for (int i = 0; i < n * (n + 1) / 2; i++) {
			cout << arry[i] << " ";
		}
		cout << endl;
		RestoreMatrix(arry,M);
		cout << "还原后的矩阵为：" << endl;
		TraverseMatrix(M);
	}
	else cout << "该矩阵不是对称矩阵" << endl;

	


	return 0;
}