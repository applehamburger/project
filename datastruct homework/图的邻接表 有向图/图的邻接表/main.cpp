#include"ALGraph.h"
int main() {
	ALGraph G;
	CreateDG(G);//��������ͼ

	bool visited[MVNum] = { false };
	cout << "DFS���������" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		if (!visited[i]) {
			DFS(G, i, visited);
		}
	}
	cout << endl;

	memset(visited, false, sizeof(visited));
	cout << "BFS���������" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		if (!visited[i]) {
			BFS(G, i, visited);
		}
	}
	cout << endl;

	cout << "������������" << endl;
	if (TopologicalSort(G)) {
		cout<<"������ͼ��DAG"<<endl;
	}
	else {
		cout << "������ͼ�л�" << endl;
	}
	return 0;
}