#include "a_opstack.h"

int main() {
    //SeqStack stack;
    //InitStack(stack);

    //// ����Push����
    //Push(stack, 1);
    //Push(stack, 2);
    //Push(stack, 3);

    //// ����Traverse����
    //Traverse(stack);

    //// ����Pop����
    //elemtype poppedElement;
    //Pop(stack, poppedElement);
    //cout << "������Ԫ��Ϊ��" << poppedElement << endl;

    //// ����GetTop����
    //elemtype topElement;
    //GetTop(stack, topElement);
    //cout << "ջ��Ԫ��Ϊ��" << topElement << endl;

    //// ����ClearStack����
    //ClearStack(stack);

    //// ����StackEmpty����
    //if (StackEmpty(stack)) {
    //    cout << "ջΪ�գ�" << endl;
    //}
    //else {
    //    cout << "ջ��Ϊ�գ�" << endl;
    //}

    //// ����DestroyStack����
    //DestroyStack(stack);
    SeqStack OPND;
    
    InitStack(OPND);
    
    selemtype ch;
    elemtype topElement;
    elemtype a;
    elemtype b;
    cout << "��������ʽ" << endl;
    cin >> ch;
    EvaluateExpression(OPND,ch);
    return 0;
}