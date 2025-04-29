#include"SparseMatrix.h"

int main() {
	TSMatrix M;
	TSMatrix T;
	TSMatrix C;
	Elemtype row;
	Elemtype col;
	Elemtype num;
	

	cout << "请输入矩阵的行数、列数以及非零元个数：";
	cin >> row>>col>>num;
	
	InitMatrix(M, row, col);
	cout << "请输入非零元所在行、列以及它的值"<<endl;
	for (int i = 0; i < num; i++) {
		cin >> M.data[i].i >> M.data[i].j >> M.data[i].e;
		M.tu++;
	}

	cout << "当前矩阵A为：" << endl;
	TraversMatrix(M);
	cout << endl;

	TransposeMatrix(M, T);
	cout << "转置后的矩阵B为：" << endl;
	TraversMatrix(T);
	cout << endl;

	FastTransMatrix(T, C);
	cout << "转置后的矩阵C为：" << endl;
	TraversMatrix(C);

	return 0;
}


