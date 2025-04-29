#include"huffman.h"
Status CrtHuffmanTree(HuffmanTree& T, Enode t[]) {
	int p1 = -1, p2 = -1, min1, min2;//p1,p2��ʾ�±�,min1Ϊ��С��min2Ϊ��С
	for (int i = 0; i < n; i++) {
		T.HT[i].data.weight = t[i].weight;
		T.HT[i].data.word = t[i].word;
	}
	for (int j = 0; j < 2 * n - 1; j++) {
		T.HT[j].parent = -1;
		T.HT[j].lchild = -1;
		T.HT[j].rchild = -1;
	}//��ʼ��
	for (int i = n; i < 2 * n - 1; i++) {
		min1 = min2 = MaxValue;
		for (int j = 0; j < i; j++) {//ÿ��ѭ������С�ʹ�С
			if (T.HT[j].parent == -1) {//û�и����
				if (T.HT[j].data.weight < min1) {
					min2 = min1;
					min1 = T.HT[j].data.weight;
					p2 = p1;
					p1 = j;
				}//min2<min1<weight
				else if (T.HT[j].data.weight < min2) {
					min2 = T.HT[j].data.weight;
					p2 = j;
				}//min2<weight<min1
			}
		}
		T.HT[i].data.weight = T.HT[p1].data.weight + T.HT[p2].data.weight;
		T.HT[i].lchild = p1;
		T.HT[i].rchild = p2;
		T.HT[p1].parent = i;
		T.HT[p2].parent = i;
	}
	return OK;
}
void EncodeHT(HuffmanTree T, HuffCode& HC) {
	HC = new char* [n + 1];
	int p, R, start;
	char* cd = new char[n];
	cd[n - 1] = '\0';
	for (int i = 0; i < n; i++) {
		start = n - 1;
		p = i;
		R = T.HT[i].parent;
		while (R != -1) {
			start--;
			if (T.HT[R].lchild == p)
				cd[start] = '0';
			else
				cd[start] = '1';
			p = R;
			R = T.HT[p].parent;
		}
		HC[i] = new char[n - start];
		strcpy_s(HC[i], n - start + 1, &cd[start]);
		cout << T.HT[i].data.word << ':' << HC[i] << ' ';
	}
	delete[]cd;
}
void EncodeStrHT(HuffCode HC, Enode t[]) {
	cout << "�������ַ�����:" << endl;
	char e;
	cin >> e;
	while (e != '#') {
		for (int j = 0; j < n; j++) {
			if (e == t[j].word)
				cout << HC[j];
		}
		cin >> e;
	}
}
void DecodeHTStr(HuffmanTree T, char* seq) {
	int i = 0;
	int p = 2 * n - 2;//���ڵ��±�
	while (seq[i] != '\0') {
		if (seq[i] == '0')
			p = T.HT[p].lchild;
		else
			p = T.HT[p].rchild;
		if (T.HT[p].lchild == -1 && T.HT[p].rchild == -1) {//�±�Ϊp�Ľ��ΪҶ�ڵ�
			cout << T.HT[p].data.word;
			p = 2 * n - 2;//�ٴӸ��ڵ㿪ʼ
		}
		i++;
	}
}