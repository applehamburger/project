#include "shunxustack.h"


// ��ʼ��ջ
void InitStack(SeqStack& stack) {
    stack.top = -1;  // ��ʼ��ջ��ָ��Ϊ-1����ʾ��ջ
}

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SeqStack stack) {
    return stack.top == -1;
}

// �ж�ջ�Ƿ�����
bool StackFull(SeqStack stack) {
    return stack.top == MAX_SIZE - 1;
}

// ��ջ����
bool Push(SeqStack& stack, elemtype element) {
    if (StackFull(stack)) {
        cout << "ջ�������޷�����Ԫ�أ�" << endl;
        return false;
    }
    stack.data[++stack.top] = element;
    return true;
}

// ��ջ����
bool Pop(SeqStack& stack, elemtype& element) {
    if (StackEmpty(stack)) {
        cout << "ջΪ�գ��޷�����Ԫ�أ�" << endl;
        return false;
    }
    element = stack.data[stack.top--];
    return true;
}

// ��ȡջ��Ԫ��
bool GetTop(SeqStack stack, elemtype& element) {
    if (StackEmpty(stack)) {
        cout << "ջΪ�գ��޷���ȡջ��Ԫ�أ�" << endl;
        return false;
    }
    element = stack.data[stack.top];
    return true;
}

// ����ջԪ��
void Traverse(SeqStack stack) {
    if (StackEmpty(stack)) {
        cout << "ջΪ�գ�" << endl;
        return;
    }
    cout << "ջ�е�Ԫ��Ϊ��";
    for (int i = 0; i <= stack.top; i++) {
        cout << stack.data[i] << " ";
    }
    cout << endl;
}

// ���ջ
void ClearStack(SeqStack& stack) {
    stack.top = -1;  // ��ջ��ָ����Ϊ-1����ʾ��ջ
    cout << "ջ����գ�" << endl;
}

// ����ջ
void DestroyStack(SeqStack& stack) {
    stack.top = -1;  // ��ջ��ָ����Ϊ-1����ʾ��ջ
    cout << "ջ�����٣�" << endl;
}

