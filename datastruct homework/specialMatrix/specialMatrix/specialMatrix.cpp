#include"specialMatrix.h"




// ���һ�������ǲ��ǶԳƾ���
bool IsSymmetricMatrix(const SMatrix M) {
    for (int i = 0; i < M.length; i++) {
        for (int j = 0; j < M.length; j++) {
            if (M.data[i * M.length + j] != M.data[j * M.length + i]) {//�ж������Ǻ�������Ԫ���Ƿ����
                return false;
            }
        }
    }
    return true;
}

Status CompressMatrix(const SMatrix &M, ElemType *arry) {  //ѹ������
    int m = 0;
    for (int i = 0; i < M.length; i++) {//�����������
        for (int j = 0; j < M.length; j++) {   //�����������
            if (i >= j) {  // �����ǲ��ֻ����Խ����ϵ�Ԫ��
                arry[m] = M.data[i * M.length + j];
                m++;// ���Գƾ����е�Ԫ�ذ���ѹ���洢�����������
            }
        }
    }
    return OK;
}


Status RestoreMatrix(ElemType *arry, SMatrix& M) {   //��ԭ����
    
    int m = 0;
    for (int i = 0; i < M.length; i++) {
        for (int j = 0; j < M.length; j++) {
            if (i >= j) {
                M.data[i * M.length +j] = arry[m];  //��Ԫ�ش���Գƾ���
                M.data[j * M.length +i] = arry[m];  //����Գ�λ��
                m++;
            }
        }
    }
    return OK;
}

Status TraverseMatrix(const SMatrix& M) {
    for (int i = 0; i < M.length; i++) {
        for (int j = 0; j < M.length; j++) {
            cout << M.data[i * M.length + j] << " ";
        }
        cout << endl;
    }
    return OK;
}