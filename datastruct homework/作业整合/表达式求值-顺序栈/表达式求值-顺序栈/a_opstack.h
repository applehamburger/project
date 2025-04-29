#pragma once
#include<iostream>
using namespace std;

#define MAX_SIZE 100   // 定义栈的最大容量

typedef int elemtype;  // 定义栈元素类型
typedef char selemtype;
// 定义顺序栈结构体
struct SeqStack {
    elemtype data[MAX_SIZE];  // 栈数组
    int top;  // 栈顶指针
};

// 初始化栈
void InitStack(SeqStack& OPND);

// 判断栈是否为空
bool StackEmpty(SeqStack stack);

// 判断栈是否已满
bool StackFull(SeqStack stack);

// 入栈操作
bool Push(SeqStack& OPND, elemtype element);


// 出栈操作
bool Pop(SeqStack& OPND, elemtype& element);

// 获取栈顶元素
bool GetTop(SeqStack stack, elemtype& element);

//// 遍历栈元素
//void Traverse(SeqStack stack);
//
//// 清空栈
//void ClearStack(SeqStack& stack);
//
//// 销毁栈
//void DestroyStack(SeqStack&OPND);

bool EvaluateExpression(SeqStack OPND,selemtype ch);

bool In(selemtype ch);

int  Dooperate(elemtype a, elemtype ch, elemtype b);
