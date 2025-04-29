#include "cyclequeue.h"
 Status InitQueue(SqQueue& Q) {
	 Q.base = new QElemType[MAXQSIZE];
	 if (!Q.base)exit(OVERFLOW);
	 Q.front = Q.rear = 0;
	 return OK;
	
}
 Status EnQueue(SqQueue& Q, QElemType e) {
	  if (QueueFull(Q))
		  return ERROR;
	  Q.base[Q.rear] = e;
	  Q.rear = (Q.rear + 1) % MAXQSIZE;
	  return OK;
	 
 }
  Status DeQueue(SqQueue & Q, QElemType & e) {
	  if (QueueEmpty(Q))
		  return ERROR;
	  e = Q.base[Q.front];
	  Q.front = (Q.front + 1) % MAXQSIZE;
	  return OK;
	 
 }
 int QueueLength(SqQueue Q) {
	 return(Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
	
}

 bool QueueEmpty(const SqQueue& Q) {
	 return Q.rear == Q.front;
	
}
 bool QueueFull(const SqQueue & Q) {
	 return (Q.rear + 1) % MAXQSIZE == Q.front;
	
}
 Status GetHead(const SqQueue & Q, QElemType & e) {
	if (QueueEmpty(Q))
		return ERROR;
	e = Q.base[Q.front];
	return OK;
	
}

void ListTraverse(const SqQueue& Q) {

	 int i;
	 for (i = Q.front; i < Q.rear; i++) {
		 cout << Q.base[i] << " ";
	 }
	 //循环遍历列表并输出
	 cout << endl;
 }

Status ClearList(SqQueue&Q) {
	Q.front = Q.rear = 0;
	return OK;
}

Status DestroyList(SqQueue& Q) {
	delete[] Q.base;
	Q.base = NULL;
	Q.front = Q.rear = NULL;
	return OK;
}