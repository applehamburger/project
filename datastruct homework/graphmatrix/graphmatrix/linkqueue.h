#pragma once
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0

typedef int Status;
typedef char Qelemtype;
typedef struct QNode {
	Qelemtype data;
	struct QNode* next;
}QNode, * Queueptr;

typedef struct {
	Queueptr front;
	Queueptr rear;
}LinkQueue;


Status InitQueue(LinkQueue& Q);

Status QueueEmpty(const LinkQueue& Q);

Status QueueTraverse(LinkQueue Q);

Status EnQueue(LinkQueue& Q, Qelemtype e);

Status DeQueue(LinkQueue& Q, Qelemtype& e);

Status GetHead(const LinkQueue& Q, Qelemtype& e);

Status DestroyQueue(LinkQueue& Q);

Status ClearQueue(LinkQueue& Q);

int ListLength(const LinkQueue& Q);

