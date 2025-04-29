#include "match.h"
#include <iostream>
using namespace std;
int main() {
    LinkStack stack;
    CreateStack(stack);

    Push(stack, '5');
    Push(stack, '6');
    Push(stack, '8');

    Traverse(stack);

    ElemType top = GetTop(stack);//���ջ��Ԫ��
    cout << "ջ��Ԫ��Ϊ: " << top << endl;

    ElemType popElem;
    Pop(stack, popElem);
    cout << "ɾ����ջ��Ԫ��: " << popElem << endl;



    top = GetTop(stack);
    cout << "��һ��ջ��Ԫ��: " << top << endl;


    ClearStack(stack);
    cout << "���ջ��ջ�е�Ԫ��Ϊ��" << endl;
    Traverse(stack);

    CreateStack(stack);

    cout << "��������Ҫ���Եı��ʽ,��&������";
    if (Matching(stack) == OK)
    {
        cout << "ҮҮ,����ƥ��ɹ�" << endl;
    }
    else
    {
        cout << "��ż������ƥ��ʧ��" << endl;
    }

    DestroyStack(stack);

    return 0;

}