#include "a_opstack.h"


// ��ʼ��ջ
void InitStack(SeqStack& OPND) {
    OPND.top = -1;  // ��ʼ��ջ��ָ��Ϊ-1����ʾ��ջ
}

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SeqStack OPND) {
    return OPND.top == -1;
}

// �ж�ջ�Ƿ�����
bool StackFull(SeqStack OPND) {
    return OPND.top == MAX_SIZE - 1;
}

// ��ջ����
bool Push(SeqStack& OPND, elemtype element) {
    if (StackFull(OPND)) {
        cout << "ջ�������޷�����Ԫ�أ�" << endl;
        return false;
    }
    OPND.data[++OPND.top] = element;
    return true;
}

// ��ջ����
bool Pop(SeqStack& OPND, elemtype& element) {
    if (StackEmpty(OPND)) {
        cout << "ջΪ�գ��޷�����Ԫ�أ�" << endl;
        return false;
    }
    element = OPND.data[OPND.top--];
    return true;
}

// ��ȡջ��Ԫ��
bool GetTop(SeqStack OPND, elemtype& element) {
    if (StackEmpty(OPND)) {
        cout << "ջΪ�գ��޷���ȡջ��Ԫ�أ�" << endl;
        return false;
    }
    element = OPND.data[OPND.top];
    cout << element << endl;
    return true;
}

//// ����ջԪ��
//void Traverse(SeqStack stack) {
//    if (StackEmpty(stack)) {
//        cout << "ջΪ�գ�" << endl;
//        return;
//    }
//    cout << "ջ�е�Ԫ��Ϊ��";
//    for (int i = 0; i <= stack.top; i++) {
//        cout << stack.data[i] << " ";
//    }
//    cout << endl;
//}
//
//// ���ջ
//void ClearStack(SeqStack& stack) {
//    stack.top = -1;  // ��ջ��ָ����Ϊ-1����ʾ��ջ
//    cout << "ջ����գ�" << endl;
//}
//
//// ����ջ
//void DestroyStack(SeqStack& stack) {
//    stack.top = -1;  // ��ջ��ָ����Ϊ-1����ʾ��ջ
//    cout << "ջ�����٣�" << endl;
//}

bool EvaluateExpression(SeqStack OPND,selemtype ch) {

    
    elemtype topElement;
    elemtype a; 
    elemtype b;

    

    while (ch != '#') {//��������ַ�����#

        if (!In(ch)) { Push(OPND, ch - 48); }//��������������push��OPND

        else {

            Pop(OPND, b); Pop(OPND, a);//���������pop������ջ����a b

            Push(OPND, Dooperate(a, ch, b));//��������������push��OPND
        }
        cin >> ch;
    }

    GetTop(OPND, topElement);//���������ȡ��ջ��Ԫ�ء������
    return true;

}


//�ж��Ƿ����ַ���
bool In(selemtype ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;

    else
        return false;
}

//������
int  Dooperate(elemtype a,elemtype ch,elemtype b) {
    switch (ch)
    {case'+':
        return a + b;
    case'-':
        return a - b;
    case'*':
        return a * b;
    case'/':
        return a / b;
    default:
        break;
    }


}

