#include"ALGraph.h"
int main() {
	ALGraph G;
	CreateDG(G);//创建有向图

	bool visited[MVNum] = { false };
	cout << "DFS遍历结果：" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		if (!visited[i]) {
			DFS(G, i, visited);
		}
	}
	cout << endl;

	memset(visited, false, sizeof(visited));
	cout << "BFS遍历结果：" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		if (!visited[i]) {
			BFS(G, i, visited);
		}
	}
	cout << endl;

	cout << "拓扑排序结果：" << endl;
	if (TopologicalSort(G)) {
		cout<<"该有向图是DAG"<<endl;
	}
	else {
		cout << "该有向图有环" << endl;
	}
	return 0;
}