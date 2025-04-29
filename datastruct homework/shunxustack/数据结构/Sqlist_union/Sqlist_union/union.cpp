
#include <iostream>
using namespace std;

const int MAXSIZE = 100; // ˳������󳤶�

struct SeqList {
    int data[MAXSIZE];
    int length;
};

// ��ʼ��˳���
void InitList(SeqList& L) {
    L.length = 0;
}

// �ϲ�����˳���
SeqList Merge(SeqList A, SeqList B) {
    SeqList C;
    InitList(C); // ��ʼ���µ�˳���

    // ��A�е�Ԫ�ظ��Ƶ�C��
    for (int i = 0; i < A.length; i++) {
        C.data[i] = A.data[i];
        C.length++;
    }

    // ��B�е�Ԫ��������뵽C��ĩβ
    for (int i = 0; i < B.length; i++) {
        C.data[C.length++] = B.data[i];
    }

    return C;
}

// ��ӡ˳���
void PrintList(SeqList L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SeqList A, B, C; // ��������˳���

    // ��ʼ������˳���A��B
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

    cout << "�ϲ�ǰ��˳���A��";
    PrintList(A);

    cout << "�ϲ�ǰ��˳���B��";
    PrintList(B);

    C = Merge(A, B); // �ϲ�����˳���

    cout << "�ϲ����˳���C��";
    PrintList(C);

    return 0;
}
