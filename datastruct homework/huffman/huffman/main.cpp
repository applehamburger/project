#include"Huffman.h"
int main() {
	HuffmanTree T;
	HuffCode HC;
	Enode t[] = { 'C',2,'A',7,'S',4,'T',5 };
	if(CrtHuffmanTree(T, t))
	  cout << "ÒÑ´´½¨¹þ·òÂüÊ÷" << endl;
	cout << "Ã¿¸ö×Ö·ûµÄ¹þ·òÂü±àÂë:" << endl;
	EncodeHT(T, HC);
	cout << endl;
	cout << "½«×Ö·ûÐòÁÐ×ª»»³É¹þ·òÂü±àÂëÐòÁÐ(×Ö·ûÐòÁÐÒÔ#½áÊø):" << endl;
	EncodeStrHT(HC, t);
	cout << endl;
	char seq[] = "110011110110110110001111010";
	cout << "½«¹þ·òÂü±àÂëÐòÁÐ×ª»»³É×Ö·ûÐòÁÐ:" << endl;
	DecodeHTStr(T, seq);
	return 0;
}