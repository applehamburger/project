#include "specialMatrix.h"

int main() {
	ElemType n;
	ElemType e;
	
	SMatrix M;
	SMatrix S;

	cout << "���������M���� ";
	cin >> n;
	M.data = new  ElemType[n * (n + 1) / 2];//�����洢�ռ䣬��ָ�븳ֵ��data��Ա
	M.length = n;
	cout << "���������Ԫ�� "<<endl;
	for (int i = 0; i < M.length; i++) {
		for (int j = 0; j < M.length; j++) {
			cin >> e;
			M.data[i * n + j]=e;
			}
		}
	cout << "��ǰ����Ϊ" << endl;
	TraverseMatrix(M);
	if (IsSymmetricMatrix(M)) {
		ElemType* arry = new ElemType[n * (n + 1) / 2];
		cout << "�þ����ǶԳƾ���" << endl;

		CompressMatrix(M, arry);
		cout << "ѹ�����һά����Ϊ��" << endl;
		for (int i = 0; i < n * (n + 1) / 2; i++) {
			cout << arry[i] << " ";
		}
		cout << endl;
		RestoreMatrix(arry,M);
		cout << "��ԭ��ľ���Ϊ��" << endl;
		TraverseMatrix(M);
	}
	else cout << "�þ����ǶԳƾ���" << endl;

	


	return 0;
}