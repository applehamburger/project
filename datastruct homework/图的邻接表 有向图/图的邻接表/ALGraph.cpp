#include"ALGraph.h"
Status CreateDG(ALGraph& G) {
	cout << "�����붥����Ŀ�ͻ���Ŀ��" << endl;
	cin >> G.vexnum >> G.arcnum;

	cout << "�����붥����Ϣ��" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
		G.vertices[i].indegree = 0;
	}

	cout << "�����뻡����Ϣ����ʼ���� �������㣩" << endl;
	for (int k = 0; k < G.arcnum; k++) {
		char v1, v2;
		int i, j;
		cout << "�������" << k + 1 << "������";
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		ArcNode* p = new ArcNode;
		p->adjvex = j;
		p->next = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;
		G.vertices[i].indegree++;   //�������
	}
	return -1;
}
int LocateVex(const ALGraph& G, char u) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == u)
			return i;
	}
	return -1;
}
void DFS(const ALGraph& G, int i, bool visited[]) {
	cout << G.vertices[i].data << " ";//���ʶ���
	visited[i] = true;//��Ǹö����Ѿ�������
	ArcNode* p = G.vertices[i].firstarc;
	while (p) {
		if (!visited[p->adjvex])//����ڽӶ���δ�����ʣ���ݹ����DFS����
			DFS(G, p->adjvex, visited);
		p = p->next;
	}
}
void BFS(const ALGraph& G, int i, bool visited[]) {
	queue<int> Q;
	cout << G.vertices[i].data << " ";//���ʶ���
	visited[i] = true;//��Ǹö����Ѿ�������
	Q.push(i);
	while (!Q.empty()) {
		int j = Q.front();
		Q.pop();
		ArcNode* p = G.vertices[j].firstarc;
		while (p) {
			if (!visited[p->adjvex]) {
				cout << G.vertices[p->adjvex].data << " ";
				visited[p->adjvex] = true;
				Q.push(p->adjvex);
			}
			p = p->next;
		}
	}
}
Status TopologicalSort(ALGraph& G) {
	queue<int> Q;
	int count = 0;//��¼�Ѿ�����Ķ�����
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].indegree == 0) {
			Q.push(i);//�����Ϊ0�Ķ���������
		}
	}
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		cout << G.vertices[i].data << " ";//�������
		count++;
		ArcNode* p = G.vertices[i].firstarc;
		while (p) {
			int j = p->adjvex;
			G.vertices[j].indegree--;
			if (G.vertices[j].indegree == 0)
				Q.push(j);//�����Ϊ0�Ķ���������
			p = p->next;
		}
	}
	cout << endl;
	if (count < G.vexnum) {
		cout << "���ڻ�·����������ʧ�ܣ�" << endl;
		return 0;
	}
	else {
		cout << "��������ɹ���" << endl;
		return 1;
	}
}