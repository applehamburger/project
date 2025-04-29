
#include <iostream>
using namespace std;

const int MAXSIZE = 100; // 顺序表的最大长度

struct SeqList {
    int data[MAXSIZE];
    int length;
};

// 初始化顺序表
void InitList(SeqList& L) {
    L.length = 0;
}

// 合并两个顺序表
SeqList Merge(SeqList A, SeqList B) {
    SeqList C;
    InitList(C); // 初始化新的顺序表

    // 将A中的元素复制到C中
    for (int i = 0; i < A.length; i++) {
        C.data[i] = A.data[i];
        C.length++;
    }

    // 将B中的元素逐个插入到C的末尾
    for (int i = 0; i < B.length; i++) {
        C.data[C.length++] = B.data[i];
    }

    return C;
}

// 打印顺序表
void PrintList(SeqList L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SeqList A, B, C; // 声明三个顺序表

    // 初始化两个顺序表A、B
    InitList(A);
    A.length = 4;
    A.data[0] = 7;
    A.data[1] = 5;
    A.data[2] = 3;
    A.data[3] = 11;

    InitList(B);
    B.length = 3;
    B.data[0] = 2;
    B.data[1] = 6;
    B.data[2] = 3;

    cout << "合并前的顺序表A：";
    PrintList(A);

    cout << "合并前的顺序表B：";
    PrintList(B);

    C = Merge(A, B); // 合并两个顺序表

    cout << "合并后的顺序表C：";
    PrintList(C);

    return 0;
}
