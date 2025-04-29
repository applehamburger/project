#include"TSMatrix.h"
bool isSymmetricMatrix(TSMatrix M) {
    for (int i = 1; i <= M.n; i++) {
        for (int j = 1; j <= M.n; j++) {
            if (M.data[(i - 1) * M.n + (j - 1)] != M.data[(j - 1) * M.n + (i - 1)]) {//�ж������Ǻ�������Ԫ���Ƿ����
                return false;
            }
        }
    }
    return true;
}
void compressMatrix(TSMatrix M, ElemType* a) {  //ѹ������
    int m = 0;
    for (int i = 1; i <= M.n; i++) {//�����������
        for (int j = 1; j <= M.n; j++) {   //�����������
            if (i >= j) {  // �����ǲ��ֻ����Խ����ϵ�Ԫ��
                a[m++] = M.data[(i - 1) * M.n + (j - 1)];  // ���Գƾ����е�Ԫ�ذ���ѹ���洢�����������a
            }
        }
    }
}
void restoreMatrix(ElemType* a, TSMatrix& M) {   //��ԭ����
    M.data = new ElemType[M.n * (M.n + 1) / 2];  //�����洢�ռ䣬��ָ�븳ֵ��data��Ա
    int m = 0;
    for (int i = 1; i <= M.n; i++) {
        for (int j = 1; j <= M.n; j++) {
            if (i >= j) {
                M.data[(i - 1) * M.n + (j - 1)] = a[m];  //��Ԫ�ش���Գƾ���
                M.data[(j - 1) * M.n + (i - 1)] = a[m];  //����ӦԪ�ؽ��и���
                m++;
            }
        }
    }
}