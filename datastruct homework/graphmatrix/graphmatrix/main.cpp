#include"ungraph.h"
#include"linkqueue.h"
ifstream fin;
int main() {

	fin.open("data.txt");
	UMGraph  G;
	//LinkQueue Q;
	if (CreateUDG(G))
		cout << "��������ͼ�ɹ���" << endl;
	fin.close();
	CountDegree(G);
	cout << "DFS��������ͼ" << endl;
	DFSTraverse(G);
	cout << "BFS��������ͼ" << endl;
	BFSTraverse(G);
	
	return 0;
} 