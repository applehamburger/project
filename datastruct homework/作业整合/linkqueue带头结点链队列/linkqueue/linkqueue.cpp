#include"linkqueue.h"

Status InitQueue(LinkQueue& Q) {
	Q.rear = Q.front = new QNode;
	Q.front->next = NULL;
	return OK;
}

Status QueueEmpty(const LinkQueue& Q) {
	return Q.front == Q.rear;
}

Status QueueTraverse(LinkQueue Q) {
	Queueptr p = Q.front->next;
	while (p !=  NULL) {
		cout << p->data<<" ";
		p = p->next;
	}
	return OK;
}

Status EnQueue(LinkQueue& Q, Qelemtype e) {
	Queueptr p = new QNode;
	p->data = e; p->next = NULL;
	Q.rear->next = p;//������β
	Q.rear = p;//��βָ������ƶ�
	return OK;
}

Status DeQueue(LinkQueue& Q, Qelemtype& e) {
	if (QueueEmpty(Q)) return ERROR;
	Queueptr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
	cout << e<<" ";
	return OK;
}

Status GetHead(const LinkQueue& Q, Qelemtype& e) {
	if (QueueEmpty(Q))  return ERROR;
	e = Q.front->next->data;
	cout << e;
	return OK;
}

int ListLength(const LinkQueue& Q) {
	int count = 0;
	Queueptr p = Q.front->next;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}
Status DestroyQueue(LinkQueue& Q) {
	while (!QueueEmpty(Q)) {
		Queueptr p = Q.front->next;
		delete Q.front;
		Q.front=p;

	}
	return OK;
}

Status ClearQueue(LinkQueue& Q) {
	Queueptr p = Q.front->next;
	while (p ){
		Queueptr q = p->next;
		delete p;
		p= q;

	}
	Q.front = NULL;
	Q.rear = NULL;
	return OK;
}
