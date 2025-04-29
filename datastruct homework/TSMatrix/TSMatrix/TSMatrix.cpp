#include"TSMatrix.h"
bool isSymmetricMatrix(TSMatrix M) {
    for (int i = 1; i <= M.n; i++) {
        for (int j = 1; j <= M.n; j++) {
            if (M.data[(i - 1) * M.n + (j - 1)] != M.data[(j - 1) * M.n + (i - 1)]) {//判断上三角和下三角元素是否相等
                return false;
            }
        }
    }
    return true;
}
void compressMatrix(TSMatrix M, ElemType* a) {  //压缩矩阵
    int m = 0;
    for (int i = 1; i <= M.n; i++) {//遍历矩阵的行
        for (int j = 1; j <= M.n; j++) {   //遍历矩阵的列
            if (i >= j) {  // 上三角部分或主对角线上的元素
                a[m++] = M.data[(i - 1) * M.n + (j - 1)];  // 将对称矩阵中的元素按照压缩存储规则存入数组a
            }
        }
    }
}
void restoreMatrix(ElemType* a, TSMatrix& M) {   //还原矩阵
    M.data = new ElemType[M.n * (M.n + 1) / 2];  //建立存储空间，将指针赋值给data成员
    int m = 0;
    for (int i = 1; i <= M.n; i++) {
        for (int j = 1; j <= M.n; j++) {
            if (i >= j) {
                M.data[(i - 1) * M.n + (j - 1)] = a[m];  //将元素存入对称矩阵
                M.data[(j - 1) * M.n + (i - 1)] = a[m];  //将对应元素进行复制
                m++;
            }
        }
    }
}