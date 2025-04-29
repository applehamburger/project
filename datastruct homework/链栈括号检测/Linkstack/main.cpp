#include "LinkStack.h"
#include <iostream>
using namespace std;
int main() {
    LinkStack stack;
    CreateStack(stack);

    Push(stack, '1');
    Push(stack, '3');
    Push(stack, '5');

    Traverse(stack);

    ElemType top = GetTop(stack);//���ջ��Ԫ��
    cout << "ջ��Ԫ��: " << top << endl;

    ElemType popElem;
    Pop(stack, popElem);
    cout << "ɾ����ջ��Ԫ��: " << popElem << endl;

    

    top = GetTop(stack);
    cout << "��һ��ջ��Ԫ��: " << top << endl;

    
    ClearStack(stack);
    cout << "���ջ��ջ�е�Ԫ��Ϊ��" << endl;
    Traverse(stack);

    CreateStack(stack);

    cout << "��������Ҫ���Եı��ʽ����#��������";
    if (Matching(stack) == OK)
    {
        cout << "����ƥ��ɹ���" << endl;
    }
    else
    {
        cout << "����ƥ��ʧ�ܣ�" << endl;
    }

    DestroyStack(stack);

    return 0;
    
}