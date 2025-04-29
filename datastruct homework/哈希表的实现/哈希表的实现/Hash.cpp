#include"Hash.h"
void InitHashTable(HashTable& HT) {
	for (int i = 0; i < m; i++) {
		HT.count[i] = 0;//�������ȳ�ʼ��Ϊ0
	}
}
void Insert(HashTable& HT, KeyType key, InfoType otherinfo) {
	int index = key % m;//�����ϣֵ
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	node->key = key;
	node->otherinfo = otherinfo;
	node->next = NULL;
	if (HT.count[index] == 0) {//�������Ϊ�գ�ֱ�Ӳ���
		HT.data[index] = *node;
		HT.count[index]++;
	}
	else {//�������Ϊ�գ������ҵ����һ���ڵ㲢����
		HashNode* p = &(HT.data[index]);
		while (p->next != NULL)
			p = p->next;
		p->next = node;
		HT.count[index]++;
	}
}
int Search(HashTable &HT, KeyType key) {
	//��ɢ�б�HT�в��ҹؼ���Ϊkey��Ԫ�أ������ҳɹ�������ɢ�б�ĵ�Ԫ��ţ����򷵻�-1
	int index = key % m;//�����ϣֵ
	if (HT.count[index] == 0) {//�������Ϊ�գ�����-1��ʾʧ��
		return -1;
	}
	else {//�������Ϊ�գ���������Ԫ��
		HashNode* p = &(HT.data[index]);
		while (p != NULL) {
			if (p->key==key) {//�ҵ�Ԫ�أ���������λ��
				return index;
			}
			p = p->next;
		}
		return -1;//������������δ�ҵ�Ԫ�أ�����-1��ʾʧ��
	}
}