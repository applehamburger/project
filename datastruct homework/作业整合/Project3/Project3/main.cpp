#include "mce.h"

int main() {
    //SeqStack stack;
    //InitStack(stack);

    //// 测试Push操作
    //Push(stack, 1);
    //Push(stack, 2);
    //Push(stack, 3);

    //// 测试Traverse操作
    //Traverse(stack);

    //// 测试Pop操作
    //elemtype poppedElement;
    //Pop(stack, poppedElement);
    //cout << "弹出的元素为：" << poppedElement << endl;

    //// 测试GetTop操作
    //elemtype topElement;
    //GetTop(stack, topElement);
    //cout << "栈顶元素为：" << topElement << endl;

    //// 测试ClearStack操作
    //ClearStack(stack);

    //// 测试StackEmpty操作
    //if (StackEmpty(stack)) {
    //    cout << "栈为空！" << endl;
    //}
    //else {
    //    cout << "栈不为空！" << endl;
    //}

    // 测试DestroyStack操作
    //DestroyStack(stack);
     // 测试代码

    SeqStack opStack;
    InitStack(opStack);
    selemtype ch;
    elemtype topElement;
    
    cout << "请输入表达式" << endl;
    cin >> ch;
    cout << "转换成后缀表达式为" << endl;
    change(opStack, ch);
    
    return 0;
}