#include"ALGraph.h"
Status CreateDG(ALGraph& G) {
	cout << "请输入顶点数目和弧数目：" << endl;
	cin >> G.vexnum >> G.arcnum;

	cout << "请输入顶点信息：" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
		G.vertices[i].indegree = 0;
	}

	cout << "请输入弧的信息（起始顶点 结束顶点）" << endl;
	for (int k = 0; k < G.arcnum; k++) {
		char v1, v2;
		int i, j;
		cout << "请输入第" << k + 1 << "条弧：";
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		ArcNode* p = new ArcNode;
		p->adjvex = j;
		p->next = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;
		G.vertices[i].indegree++;   //计算入度
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
	cout << G.vertices[i].data << " ";//访问顶点
	visited[i] = true;//标记该顶点已经被访问
	ArcNode* p = G.vertices[i].firstarc;
	while (p) {
		if (!visited[p->adjvex])//如果邻接顶点未被访问，则递归调用DFS函数
			DFS(G, p->adjvex, visited);
		p = p->next;
	}
}
void BFS(const ALGraph& G, int i, bool visited[]) {
	queue<int> Q;
	cout << G.vertices[i].data << " ";//访问顶点
	visited[i] = true;//标记该顶点已经被访问
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
	int count = 0;//记录已经输出的顶点数
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].indegree == 0) {
			Q.push(i);//将入度为0的顶点加入队列
		}
	}
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		cout << G.vertices[i].data << " ";//输出顶点
		count++;
		ArcNode* p = G.vertices[i].firstarc;
		while (p) {
			int j = p->adjvex;
			G.vertices[j].indegree--;
			if (G.vertices[j].indegree == 0)
				Q.push(j);//将入度为0的顶点加入对列
			p = p->next;
		}
	}
	cout << endl;
	if (count < G.vexnum) {
		cout << "存在环路，拓扑排序失败！" << endl;
		return 0;
	}
	else {
		cout << "拓扑排序成功！" << endl;
		return 1;
	}
}