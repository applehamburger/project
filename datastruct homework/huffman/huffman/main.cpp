#include"Huffman.h"
int main() {
	HuffmanTree T;
	HuffCode HC;
	Enode t[] = { 'C',2,'A',7,'S',4,'T',5 };
	if(CrtHuffmanTree(T, t))
	  cout << "�Ѵ�����������" << endl;
	cout << "ÿ���ַ��Ĺ���������:" << endl;
	EncodeHT(T, HC);
	cout << endl;
	cout << "���ַ�����ת���ɹ�������������(�ַ�������#����):" << endl;
	EncodeStrHT(HC, t);
	cout << endl;
	char seq[] = "110011110110110110001111010";
	cout << "����������������ת�����ַ�����:" << endl;
	DecodeHTStr(T, seq);
	return 0;
}