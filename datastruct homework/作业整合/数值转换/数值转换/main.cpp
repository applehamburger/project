#include"change.h"

#include <iostream>
using namespace std;

int main() {
    Sstack S;
    InitStack(S);
    int num, e;

    cout << "���������" << endl;
    cin >> num;

    cout << "������" << num << "��Ԫ�أ�" << endl;
    for (int i = 0; i < num; i++) {
        cin >> e;
        Push(S, e);
    }

    cout << "ջ�е�Ԫ��Ϊ��" << endl;
    Traverse(S);

    ClearStack(S);
    cout << "���ջ��ջ�е�Ԫ��Ϊ��" << endl;
    Traverse(S);

    int d, N;

    cout << "������һ��ʮ������";
    cin >> N;

    cout << "������Ŀ�����";
    cin >> d;

    cout << "ת������Ϊ:";
    conversion(N, d, S);


    DestroyStack(S);


    return 0;
}
