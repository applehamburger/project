#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Sstack S;
    InitStack(S);
    int num, ele;

    cout << "请输入元素个数：" << endl;
    cin >> num;

    cout << "请输入" << num << "个元素：" << endl;
    for (int i = 0; i < num; i++) {
        cin >> ele;
        Push(S, ele);
    }

    cout << "栈中的元素为：" << endl;
    Traverse(S);

    ClearStack(S);
    cout << "清空栈后，栈中的元素为：" << endl;
    Traverse(S);

    int d, N;

    cout << "请输入一个十进制数";
    cin >> N;

    cout << "请输入目标进制";
    cin >> d;

    cout << "转换后结果为:";
    conversion(N, d, S);


    DestroyStack(S);


    return 0;
}
