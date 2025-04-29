#include"Huffman.h"

int main() {
	HuffmanTree HT;
	//HuffmanCode HC;
	char code[50];//待编码的字符串
	int w[SIZE] = { 0 };//存储叶子结点的权重
	char p[27] = { 0 };//存储字符串中不同的字符
	int q[SIZE][10];//存储不同字符的编码
	int road[SIZE];//存储叶子结点到根结点的路径长度
	int n;//叶子结点的个数
	memset(q, -1, sizeof(q));
	memset(road, 0, sizeof(road));
	cout << "请输入待编码字符串：" << endl;//CASTCASTSATATATASA
	cin >> code;
	n = FindWeight(code, p, w);
	cout << "叶子结点个数为：" << n << endl;
	cout << "各叶子结点权重为：" << endl;
	for (int i = 0; i < n; i++)
		cout << p[i] << ":" << w[i] << " ";
	cout << endl;
	CreateHuffmanTree(HT, n, w);
	for (int i = 0; i < 2 * n - 1; i++) {
		cout << setiosflags(ios::left) << setw(4) << i;
		cout << setiosflags(ios::left) << setw(4) << HT[i].weight;
		cout << setiosflags(ios::left) << setw(4) << HT[i].parent;
		cout << setiosflags(ios::left) << setw(4) << HT[i].lchild;
		cout << setiosflags(ios::left) << setw(4) << HT[i].rchild << endl;
	}
	CreateHuffmanCode(HT, n, q, road);
	print(q, p, n);
	cout << "各叶子结点的路径为：" << endl;
	for (int i = 0; i < n; i++) {
		cout << p[i] << ":" << road[i] << " ";
	}
	cout << endl;

	cout << "请输入待编码字符串：" << endl;
	cin >> code;
	print2(q, code);
	cout << endl;
	int code2[SIZE], t, l = 0;
	memset(code2, -1, sizeof(code2));
	cout << "请输入待解码编码（以-1截至）：" << endl;
	//1 1 0 0 1 1 1 1 0 1 1 0 1 1 0 1 1 0 0 0 1 1 1 1 0 1 0 -1
	cin >> t;
	while (t != -1) {
		code2[l] = t;
		cin >> t;
		l++;
	}
	HuffmanDecode(code2, HT, p, n);
}