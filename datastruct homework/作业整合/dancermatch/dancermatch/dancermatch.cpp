#include"dancermatch.h"

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
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	return OK;
}

Status EnQueue(LinkQueue& Q, Qelemtype e) {
	Queueptr p = new QNode;
	p->data = e; p->next = NULL;
	Q.rear->next = p;//接在链尾
	Q.rear = p;//队尾指针向后移动
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
	return OK;
}

Status GetHead(const LinkQueue& Q, Qelemtype& e) {
	if (QueueEmpty(Q))  return ERROR;
	e = Q.front->next->data;
	cout << e<<endl;
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
		Q.front = p;

	}
	return OK;
}

Status ClearQueue(LinkQueue& Q) {
	Queueptr p = Q.front->next;
	while (p) {
		Queueptr q = p->next;
		delete p;
		p = q;

	}
	Q.front = NULL;
	Q.rear = NULL;
	return OK;
}
//bool GetNAME(const char* mazedata, Maze& M) {
//	std::ifstream fin;
//	fin.open(mazedata);
//	if (!fin) {
//		std::cout << "无法打开文件" << std::endl;
//		return false;
//	}
//	fin >> M.MazeSize;
//	M.intsec = new Intersection[M.MazeSize + 1];
//	for (int i = 1; i <= M.MazeSize; i++)
//		fin >> M.intsec[i].left >> M.intsec[i].forwd >> M.intsec[i].right;
//	fin >> M.EXIT;
//	fin.close();
//	return true;
//}