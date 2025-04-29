#include <iostream>
using namespace std;

#define SElemType int
#define MAXSIZE 100
#define OVERFLOW -1

typedef struct {
    SElemType* base;
    SElemType* top;
    int stacksize;
} Sstack;

enum Status {
    OK,     // 执行成功
    ERROR   // 执行失败
};

Status InitStack(Sstack& S);
Status Push(Sstack& S, SElemType e);
Status Pop(Sstack& S, SElemType& e);
Status Traverse(const Sstack& S);
Status ClearStack(Sstack& S);
Status DestroyStack(Sstack& S);
bool StackEmpty(const Sstack& S);
bool StackFull(const Sstack& S);
Status conversion(int N, int d, Sstack S);

