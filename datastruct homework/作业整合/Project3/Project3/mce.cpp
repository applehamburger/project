#include "mce.h"


// 初始化栈
void InitStack(SeqStack& opStack) {
    opStack.top = -1;  // 初始化栈顶指针为-1，表示空栈
}

// 判断栈是否为空
bool StackEmpty(SeqStack opStack) {
    return opStack.top == -1;
}

// 判断栈是否已满
bool StackFull(SeqStack opStack) {
    return opStack.top == MAX_SIZE - 1;
}

// 入栈操作
bool Push(SeqStack& opStack, elemtype element) {
    if (StackFull(opStack)) {
        cout << "栈已满，无法插入元素！" << endl;
        return false;
    }
    opStack.data[++opStack.top] = element;
    return true;
}

// 出栈操作
bool Pop(SeqStack& opStack, elemtype& element) {
    if (StackEmpty(opStack)) {
        cout << "栈为空，无法弹出元素！" << endl;
        return false;
    }
    element = opStack.data[opStack.top--];
    return true;
}

// 获取栈顶元素
bool GetTop(SeqStack opStack, elemtype& element) {
    if (StackEmpty(opStack)) {
        cout << "栈为空，无法获取栈顶元素！" << endl;
        return false;
    }
    element = opStack.data[opStack.top];
    return true;
}

// 遍历栈元素
void Traverse(SeqStack opStack) {
    if (StackEmpty(opStack)) {
        cout << "栈为空！" << endl;
        return;
    }
    cout << "栈中的元素为：";
    for (int i = 0; i <= opStack.top; i++) {
        cout << opStack.data[i] << " ";
    }
    cout << endl;
}

// 清空栈
void ClearStack(SeqStack& opStack) {
    opStack.top = -1;  // 将栈顶指针置为-1，表示空栈
    cout << "栈已清空！" << endl;
}

// 销毁栈
void DestroyStack(SeqStack& opStack) {
    opStack.top = -1;  // 将栈顶指针置为-1，表示空栈
    cout << "栈已销毁！" << endl;
}



// 定义运算符优先级函数，返回优先级值
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

// 将中缀表达式转换成后缀表达式
void  change(SeqStack& opStack,selemtype ch) {
      elemtype topelement;
        while (ch != '#') {//当读入的字符不是# 
        if (!In(ch)) {
            // 如果是数字，则直接输出
            cout << ch;
        }
        else if (ch == '(') {
            // 如果是左括号，直接入栈
            Push( opStack, ch);
        }
        else if (ch == ')') {
            // 如果是右括号，不断弹出栈顶元素，直到遇到左括号
            while (!StackEmpty(opStack) && opStack.data[opStack.top] != '(') {
                GetTop(opStack, topelement);
            }
            /*if (!StackEmpty(opStack) && opStack.data[opStack.top]= '(') {
                opStack.pop();
            }*/
        }
        else {
            // 如果是运算符，根据优先级决定是否弹出栈顶元素
            while (!StackEmpty(opStack) && getPriority(opStack.data[opStack.top]) >= getPriority(ch)) {
                GetTop(opStack, topelement);
            }
            Push(opStack, ch);
        }
        cin >> ch;
    }
    // 弹出栈中剩下所有元素
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
