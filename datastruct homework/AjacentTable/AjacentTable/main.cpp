#include "AjacentTable.h"
int main() {
	ALGraph G;
	ifstream fin;
	fin.open("data.txt");
	CreateDG(G, fin);
	DFSTraverse(G);
	cout << endl;
	BFSTraverse(G);
	cout << endl;
	TopologicalSort(G);
	return 0;
}