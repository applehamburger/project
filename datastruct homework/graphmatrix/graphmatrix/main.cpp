#include"ungraph.h"
#include"linkqueue.h"
ifstream fin;
int main() {

	fin.open("data.txt");
	UMGraph  G;
	//LinkQueue Q;
	if (CreateUDG(G))
		cout << "创建无向图成功！" << endl;
	fin.close();
	CountDegree(G);
	cout << "DFS遍历无向图" << endl;
	DFSTraverse(G);
	cout << "BFS遍历无向图" << endl;
	BFSTraverse(G);
	
	return 0;
} 