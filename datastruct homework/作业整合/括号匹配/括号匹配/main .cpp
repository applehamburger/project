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

    ElemType top = GetTop(stack);//输出栈顶元素
    cout << "栈顶元素为: " << top << endl;

    ElemType popElem;
    Pop(stack, popElem);
    cout << "删除的栈顶元素: " << popElem << endl;



    top = GetTop(stack);
    cout << "下一个栈顶元素: " << top << endl;


    ClearStack(stack);
    cout << "清空栈后，栈中的元素为：" << endl;
    Traverse(stack);

    CreateStack(stack);

    cout << "请输入需要测试的表达式,以&结束：";
    if (Matching(stack) == OK)
    {
        cout << "耶耶,括号匹配成功" << endl;
    }
    else
    {
        cout << "阿偶，括号匹配失败" << endl;
    }

    DestroyStack(stack);

    return 0;

}