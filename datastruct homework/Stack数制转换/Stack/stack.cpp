#include "stack.h"
#include <iostream>
using namespace std;

#define OVERFLOW -1

Status InitStack(Sstack& S) {
    S.base = new SElemType[MAXSIZE];
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

Status Push(Sstack& S, SElemType e) {
    if (S.top - S.base == S.stacksize) return ERROR;
    *S.top++ = e;
    return OK;
}

Status Pop(Sstack& S, SElemType& e) {
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}

Status Traverse(const Sstack& S) {
    if (S.top == S.base)
        cout << "这个栈居然是空的！" << endl;
    int i;
    for (i = 0; i < (S.top - S.base); i++) {
        cout << S.base[i] << " ";
    }
    cout << endl;
    return OK;
}

Status ClearStack(Sstack& S) {
    if (S.top == S.base)
        cout << "这个栈是空的" << endl;
    if (S.base) S.top = S.base;
    return OK;
}

Status DestroyStack(Sstack& S) {
    if (S.base) {
        delete[] S.base;
        S.stacksize = 0;
        S.base = NULL;
        S.top = NULL;
    }
    return OK;
}

bool StackEmpty(const Sstack& S) {
    if (S.top == S.base)
        return true;
    else
        return false;
}

bool StackFull(const Sstack& S) {
    if (S.top - S.base == S.stacksize)
        return true;
    else
        return false;
}

Status conversion(int N, int d, Sstack S) {
    InitStack(S);
    SElemType e;
    while (N) {
        Push(S, N % d); N = N / d;
    }
    while (!StackEmpty(S)) {
        Pop(S, e);
        cout << e;
    }
    return OK;
}



