#include"specialMatrix.h"




// 检查一个矩阵是不是对称矩阵
bool IsSymmetricMatrix(const SMatrix M) {
    for (int i = 0; i < M.length; i++) {
        for (int j = 0; j < M.length; j++) {
            if (M.data[i * M.length + j] != M.data[j * M.length + i]) {//判断上三角和下三角元素是否相等
                return false;
            }
        }
    }
    return true;
}

Status CompressMatrix(const SMatrix &M, ElemType *arry) {  //压缩矩阵
    int m = 0;
    for (int i = 0; i < M.length; i++) {//遍历矩阵的行
        for (int j = 0; j < M.length; j++) {   //遍历矩阵的列
            if (i >= j) {  // 上三角部分或主对角线上的元素
                arry[m] = M.data[i * M.length + j];
                m++;// 将对称矩阵中的元素按照压缩存储规则存入数组
            }
        }
    }
    return OK;
}


Status RestoreMatrix(ElemType *arry, SMatrix& M) {   //还原矩阵
    
    int m = 0;
    for (int i = 0; i < M.length; i++) {
        for (int j = 0; j < M.length; j++) {
            if (i >= j) {
                M.data[i * M.length +j] = arry[m];  //将元素存入对称矩阵
                M.data[j * M.length +i] = arry[m];  //存入对称位置
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