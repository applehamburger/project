#pragma once
#include<iostream>
using namespace std;
#define MAXQSIZE 100
#define OK 1
#define ERROR 0

typedef int QElemType;
typedef int Status;
typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue& Q);
bool QueueEmpty(const SqQueue& Q);
bool QueueFull(const SqQueue& Q);
int QueueLength(SqQueue Q);
Status EnQueue(SqQueue& Q, QElemType e);
Status DeQueue(SqQueue& Q, QElemType& e);
Status GetHead(const SqQueue& Q, QElemType& e);
void ListTraverse(const SqQueue& Q);
Status ClearList(SqQueue& Q);
Status DestroyList(SqQueue& Q);
