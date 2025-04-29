#include "mce.h"


// ��ʼ��ջ
void InitStack(SeqStack& opStack) {
    opStack.top = -1;  // ��ʼ��ջ��ָ��Ϊ-1����ʾ��ջ
}

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SeqStack opStack) {
    return opStack.top == -1;
}

// �ж�ջ�Ƿ�����
bool StackFull(SeqStack opStack) {
    return opStack.top == MAX_SIZE - 1;
}

// ��ջ����
bool Push(SeqStack& opStack, elemtype element) {
    if (StackFull(opStack)) {
        cout << "ջ�������޷�����Ԫ�أ�" << endl;
        return false;
    }
    opStack.data[++opStack.top] = element;
    return true;
}

// ��ջ����
bool Pop(SeqStack& opStack, elemtype& element) {
    if (StackEmpty(opStack)) {
        cout << "ջΪ�գ��޷�����Ԫ�أ�" << endl;
        return false;
    }
    element = opStack.data[opStack.top--];
    return true;
}

// ��ȡջ��Ԫ��
bool GetTop(SeqStack opStack, elemtype& element) {
    if (StackEmpty(opStack)) {
        cout << "ջΪ�գ��޷���ȡջ��Ԫ�أ�" << endl;
        return false;
    }
    element = opStack.data[opStack.top];
    return true;
}

// ����ջԪ��
void Traverse(SeqStack opStack) {
    if (StackEmpty(opStack)) {
        cout << "ջΪ�գ�" << endl;
        return;
    }
    cout << "ջ�е�Ԫ��Ϊ��";
    for (int i = 0; i <= opStack.top; i++) {
        cout << opStack.data[i] << " ";
    }
    cout << endl;
}

// ���ջ
void ClearStack(SeqStack& opStack) {
    opStack.top = -1;  // ��ջ��ָ����Ϊ-1����ʾ��ջ
    cout << "ջ����գ�" << endl;
}

// ����ջ
void DestroyStack(SeqStack& opStack) {
    opStack.top = -1;  // ��ջ��ָ����Ϊ-1����ʾ��ջ
    cout << "ջ�����٣�" << endl;
}



// ������������ȼ��������������ȼ�ֵ
int getPriority(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

// ����׺���ʽת���ɺ�׺���ʽ
void  change(SeqStack& opStack,selemtype ch) {
      elemtype topelement;
        while (ch != '#') {//��������ַ�����# 
        if (!In(ch)) {
            // ��������֣���ֱ�����
            cout << ch;
        }
        else if (ch == '(') {
            // ����������ţ�ֱ����ջ
            Push( opStack, ch);
        }
        else if (ch == ')') {
            // ����������ţ����ϵ���ջ��Ԫ�أ�ֱ������������
            while (!StackEmpty(opStack) && opStack.data[opStack.top] != '(') {
                GetTop(opStack, topelement);
            }
            /*if (!StackEmpty(opStack) && opStack.data[opStack.top]= '(') {
                opStack.pop();
            }*/
        }
        else {
            // �������������������ȼ������Ƿ񵯳�ջ��Ԫ��
            while (!StackEmpty(opStack) && getPriority(opStack.data[opStack.top]) >= getPriority(ch)) {
                GetTop(opStack, topelement);
            }
            Push(opStack, ch);
        }
        cin >> ch;
    }
    // ����ջ��ʣ������Ԫ��
        selemtype optr;
        while (!StackEmpty(opStack)) {
           optr = opStack.data[opStack.top--];
           cout << optr;
        }
    
}

bool In(selemtype ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;

    else
        return false;
}
