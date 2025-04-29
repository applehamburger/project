#include"Huffman.h"

int main() {
	HuffmanTree HT;
	//HuffmanCode HC;
	char code[50];//��������ַ���
	int w[SIZE] = { 0 };//�洢Ҷ�ӽ���Ȩ��
	char p[27] = { 0 };//�洢�ַ����в�ͬ���ַ�
	int q[SIZE][10];//�洢��ͬ�ַ��ı���
	int road[SIZE];//�洢Ҷ�ӽ�㵽������·������
	int n;//Ҷ�ӽ��ĸ���
	memset(q, -1, sizeof(q));
	memset(road, 0, sizeof(road));
	cout << "������������ַ�����" << endl;//CASTCASTSATATATASA
	cin >> code;
	n = FindWeight(code, p, w);
	cout << "Ҷ�ӽ�����Ϊ��" << n << endl;
	cout << "��Ҷ�ӽ��Ȩ��Ϊ��" << endl;
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
	cout << "��Ҷ�ӽ���·��Ϊ��" << endl;
	for (int i = 0; i < n; i++) {
		cout << p[i] << ":" << road[i] << " ";
	}
	cout << endl;

	cout << "������������ַ�����" << endl;
	cin >> code;
	print2(q, code);
	cout << endl;
	int code2[SIZE], t, l = 0;
	memset(code2, -1, sizeof(code2));
	cout << "�������������루��-1��������" << endl;
	//1 1 0 0 1 1 1 1 0 1 1 0 1 1 0 1 1 0 0 0 1 1 1 1 0 1 0 -1
	cin >> t;
	while (t != -1) {
		code2[l] = t;
		cin >> t;
		l++;
	}
	HuffmanDecode(code2, HT, p, n);
}