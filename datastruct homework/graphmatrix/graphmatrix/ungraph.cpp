#include"ungraph.h"
#include"linkqueue.h"
extern ifstream fin;
//��������ͼ
Status CreateUDG(UMGraph& G) {
	VerTexType v1, v2;
	int i, j;
	/*cout << "�������ܶ�����������" << endl;*/
	fin >> G.vexnum >> G.arcnum;
	//��ʼ�������
	/*cout << "���������붥��Ԫ��" << endl;*/
	for (int i = 0; i < G.vexnum; i++) {
		fin >> G.vexs[i];
	}
	//��ʼ���ڽӾ���
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = -1;
	}
	//�����ڽӾ���
	/*cout << "�������������������" << endl;*/
	for (int k = 0; k < G.arcnum; k++) {
		fin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

int LocateVex(const UMGraph& G, VerTexType u) {
	for (int i = 0; i < G.vexnum; i++)
		if (u == G.vexs[i])
			return i;
	return -1;
}

Status CountDegree(const UMGraph& G) {

	for (int i = 0; i < G.vexnum; i++) {
		int count = 0;
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[i][j] != -1) {
				count++;
			}
		}
		cout << G.vexs[i] << "�Ķ�Ϊ��" << count << endl;
	}
	return OK;
}

int FirstAdjVex(const UMGraph& G, int v) {

	if (v != -1) {
		for (int col = 0; col < G.vexnum; col++)
			if (G.arcs[v][col] > 0 && G.arcs[v][col] < MaxInt)
				return col;
	}
	return -1;
}

int NextAdjVex(const UMGraph& G, int v, int w) {
	if (v != -1) {
		for (int col = w + 1; col < G.vexnum; col++)
			if (G.arcs[v][col] > 0 && G.arcs[v][col] < MaxInt)
				return col;
	}
	return -1;
}

void DFS(const UMGraph& G, int v, bool visited[]) {
	visited[v] = true;//��Ǹö�����ʹ�
	cout << G.vexs[v] << " ";  // ������ʵĶ���ֵ

	for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {//����һ�ڽӶ���
		if (!visited[w]) {//δ����
			DFS(G, w, visited);  // �ݹ����DFS����
		}
	}
}

void DFSTraverse(const UMGraph& G) {
	bool visited[MVNum];
	for (int i = 0; i < G.vexnum; i++) {
		visited[i] = false;  // ��ʼ��visited����Ϊfalse
	}

	for (int v = 0; v < G.vexnum; v++) {
		if (!visited[v]) {
			DFS(G, v, visited);  // ����DFS����
		}
	}
	cout << endl;
}

void BFSTraverse(UMGraph G) {
	bool visited[MVNum];
	LinkQueue Q;
	Qelemtype e;
	for (int v = 0; v < G.vexnum; v++) visited[v] = false;
	InitQueue(Q);
	for (int v = 0; v < G.vexnum; ++v)
		if (!visited[v]) {
			visited[v] = true;
			EnQueue(Q, G.vexs[v]);
			while (!QueueEmpty(Q)) {
				DeQueue(Q, e); int el;
			    el=LocateVex(G, e);
				for (int w = FirstAdjVex(G, el); w>=0; w = NextAdjVex(G, el, w))
					if (!visited[w]) {
						visited[w] = true;
						EnQueue(Q, G.vexs[w]);

					} //~if

			} //~while

		} //~if
}
