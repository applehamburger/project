#include"SparseMatrix.h"

int main() {
	TSMatrix M;
	TSMatrix T;
	TSMatrix C;
	Elemtype row;
	Elemtype col;
	Elemtype num;
	

	cout << "���������������������Լ�����Ԫ������";
	cin >> row>>col>>num;
	
	InitMatrix(M, row, col);
	cout << "���������Ԫ�����С����Լ�����ֵ"<<endl;
	for (int i = 0; i < num; i++) {
		cin >> M.data[i].i >> M.data[i].j >> M.data[i].e;
		M.tu++;
	}

	cout << "��ǰ����AΪ��" << endl;
	TraversMatrix(M);
	cout << endl;

	TransposeMatrix(M, T);
	cout << "ת�ú�ľ���BΪ��" << endl;
	TraversMatrix(T);
	cout << endl;

	FastTransMatrix(T, C);
	cout << "ת�ú�ľ���CΪ��" << endl;
	TraversMatrix(C);

	return 0;
}


