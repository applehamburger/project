#include"SparseMatrix.h"

Status InitMatrix(TSMatrix& M, int rows, int cols) {
	M.mu = rows;           // ��������
	M.nu = cols;           // ��������
	M.tu = 0;              // ��ʼʱ����Ԫ�ظ���Ϊ 0

	// ����ϡ������ data ���鲢��ʼ��ÿ��Ԫ��
	for (int i = 0; i <= MAXSIZE; i++) {
		M.data[i].i = 0;
		M.data[i].j = 0;
		M.data[i].e = 0;
	}
	return OK;
}

void TraversMatrix(const TSMatrix& M) {
	for (int k = 0; k < M.tu; k++) {
		cout << "(" << M.data[k].i<<"," << M.data[k].j<<"," << M.data[k].e << ") ";
	}
}
Status TransposeMatrix(TSMatrix M, TSMatrix& T) {
	T.mu = M.nu; T.nu = M.mu; T.tu = M.tu;
	//����Ԫ���T.data���С������ͷ�0Ԫ�ظ���
	if (M.tu == 0) cout << "The Matrix A = 0\n" << endl;
	else {
		int q = 0;
		for (int col = 1; col <= M.nu; col++)
			//ÿѭ��һ���ҵ�ת�ú��һ����Ԫ��
			for (int p = 0; p < M.tu; p++) //ѭ�������Ƿ�0Ԫ�ظ���
				if (M.data[p].j == col) {
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					q++;

				}

	}
	return OK;

}

Status FastTransMatrix(TSMatrix &T, TSMatrix& C) {
	int p, q, col, k;
	Elemtype num[MAXSIZE], cpot[MAXSIZE];
	C.mu = T.nu;
	C.nu = T.mu;
	C.tu = T.tu;

	if (C.tu == 0) {
		cout << "The Matrix B = 0" << endl;
	}
	else {
		for (col = 1; col <= T.nu; ++col) {
			num[col] = 0;
		}
		for (k = 1; k <= T.tu; ++k) {
			++num[T.data[k].j];
		}
		cpot[0] = 1;
		for (col = 2; col <= T.mu; ++col) {
			cpot[col] = cpot[col - 1] + num[col - 1];
		}
		for (p = 1; p <= T.tu; ++p) {
			col = T.data[p].j;
			q = cpot[col];
			C.data[q].i = T.data[p].j;
			C.data[q].j = T.data[p].i;
			C.data[q].e = T.data[p].e;
			++cpot[col];
        }
    }
			 return  OK;
	}