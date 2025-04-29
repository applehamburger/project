#pragma once
#include<iostream>
using namespace std;

#define MAX_SIZE 100   // 定义栈的最大容量
typedef char selemtype;
typedef int elemtype;  // 定义栈元素类型

// 定义顺序栈结构体
struct SeqStack {
    elemtype data[MAX_SIZE];  // 栈数组
    int top;  // 栈顶指针
};

// 初始化栈
void InitStack(SeqStack& opStack);

// 判断栈是否为空
bool StackEmpty(SeqStack opStack);

// 判断栈是否已满
bool StackFull(SeqStack opStack);

// 入栈操作
bool Push(SeqStack& opStack, elemtype element);


// 出栈操作
bool Pop(SeqStack& opStack, elemtype& element);

// 获取栈顶元素
bool GetTop(SeqStack opStack, elemtype& element);

// 遍历栈元素
void Traverse(SeqStack opStack);

// 清空栈
void ClearStack(SeqStack& opStack);

// 销毁栈
void DestroyStack(SeqStack& opStack);

void change(SeqStack& opStack, selemtype ch);

bool In(selemtype ch);