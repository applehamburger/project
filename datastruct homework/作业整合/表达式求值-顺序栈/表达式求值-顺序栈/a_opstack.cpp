#include "a_opstack.h"


// 初始化栈
void InitStack(SeqStack& OPND) {
    OPND.top = -1;  // 初始化栈顶指针为-1，表示空栈
}

// 判断栈是否为空
bool StackEmpty(SeqStack OPND) {
    return OPND.top == -1;
}

// 判断栈是否已满
bool StackFull(SeqStack OPND) {
    return OPND.top == MAX_SIZE - 1;
}

// 入栈操作
bool Push(SeqStack& OPND, elemtype element) {
    if (StackFull(OPND)) {
        cout << "栈已满，无法插入元素！" << endl;
        return false;
    }
    OPND.data[++OPND.top] = element;
    return true;
}

// 出栈操作
bool Pop(SeqStack& OPND, elemtype& element) {
    if (StackEmpty(OPND)) {
        cout << "栈为空，无法弹出元素！" << endl;
        return false;
    }
    element = OPND.data[OPND.top--];
    return true;
}

// 获取栈顶元素
bool GetTop(SeqStack OPND, elemtype& element) {
    if (StackEmpty(OPND)) {
        cout << "栈为空，无法获取栈顶元素！" << endl;
        return false;
    }
    element = OPND.data[OPND.top];
    cout << element << endl;
    return true;
}

//// 遍历栈元素
//void Traverse(SeqStack stack) {
//    if (StackEmpty(stack)) {
//        cout << "栈为空！" << endl;
//        return;
//    }
//    cout << "栈中的元素为：";
//    for (int i = 0; i <= stack.top; i++) {
//        cout << stack.data[i] << " ";
//    }
//    cout << endl;
//}
//
//// 清空栈
//void ClearStack(SeqStack& stack) {
//    stack.top = -1;  // 将栈顶指针置为-1，表示空栈
//    cout << "栈已清空！" << endl;
//}
//
//// 销毁栈
//void DestroyStack(SeqStack& stack) {
//    stack.top = -1;  // 将栈顶指针置为-1，表示空栈
//    cout << "栈已销毁！" << endl;
//}

bool EvaluateExpression(SeqStack OPND,selemtype ch) {

    
    elemtype topElement;
    elemtype a; 
    elemtype b;

    

    while (ch != '#') {//当读入的字符不是#

        if (!In(ch)) { Push(OPND, ch - 48); }//如果不是运算符就push进OPND

        else {

            Pop(OPND, b); Pop(OPND, a);//是运算符就pop出靠近栈顶的a b

            Push(OPND, Dooperate(a, ch, b));//将运算后的数字再push进OPND
        }
        cin >> ch;
    }

    GetTop(OPND, topElement);//运算结束后取出栈顶元素——结果
    return true;

}


//判断是否是字符串
bool In(selemtype ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;

    else
        return false;
}

//做运算
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

