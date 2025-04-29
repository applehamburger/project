#include "shunxustack.h"


// 初始化栈
void InitStack(SeqStack& stack) {
    stack.top = -1;  // 初始化栈顶指针为-1，表示空栈
}

// 判断栈是否为空
bool StackEmpty(SeqStack stack) {
    return stack.top == -1;
}

// 判断栈是否已满
bool StackFull(SeqStack stack) {
    return stack.top == MAX_SIZE - 1;
}

// 入栈操作
bool Push(SeqStack& stack, elemtype element) {
    if (StackFull(stack)) {
        cout << "栈已满，无法插入元素！" << endl;
        return false;
    }
    stack.data[++stack.top] = element;
    return true;
}

// 出栈操作
bool Pop(SeqStack& stack, elemtype& element) {
    if (StackEmpty(stack)) {
        cout << "栈为空，无法弹出元素！" << endl;
        return false;
    }
    element = stack.data[stack.top--];
    return true;
}

// 获取栈顶元素
bool GetTop(SeqStack stack, elemtype& element) {
    if (StackEmpty(stack)) {
        cout << "栈为空，无法获取栈顶元素！" << endl;
        return false;
    }
    element = stack.data[stack.top];
    return true;
}

// 遍历栈元素
void Traverse(SeqStack stack) {
    if (StackEmpty(stack)) {
        cout << "栈为空！" << endl;
        return;
    }
    cout << "栈中的元素为：";
    for (int i = 0; i <= stack.top; i++) {
        cout << stack.data[i] << " ";
    }
    cout << endl;
}

// 清空栈
void ClearStack(SeqStack& stack) {
    stack.top = -1;  // 将栈顶指针置为-1，表示空栈
    cout << "栈已清空！" << endl;
}

// 销毁栈
void DestroyStack(SeqStack& stack) {
    stack.top = -1;  // 将栈顶指针置为-1，表示空栈
    cout << "栈已销毁！" << endl;
}

