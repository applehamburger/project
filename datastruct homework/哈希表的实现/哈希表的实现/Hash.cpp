#include"Hash.h"
void InitHashTable(HashTable& HT) {
	for (int i = 0; i < m; i++) {
		HT.count[i] = 0;//将链表长度初始化为0
	}
}
void Insert(HashTable& HT, KeyType key, InfoType otherinfo) {
	int index = key % m;//计算哈希值
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	node->key = key;
	node->otherinfo = otherinfo;
	node->next = NULL;
	if (HT.count[index] == 0) {//如果链表为空，直接插入
		HT.data[index] = *node;
		HT.count[index]++;
	}
	else {//如果链表不为空，遍历找到最后一个节点并插入
		HashNode* p = &(HT.data[index]);
		while (p->next != NULL)
			p = p->next;
		p->next = node;
		HT.count[index]++;
	}
}
int Search(HashTable &HT, KeyType key) {
	//在散列表HT中查找关键字为key的元素，若查找成功，返回散列表的单元标号，否则返回-1
	int index = key % m;//计算哈希值
	if (HT.count[index] == 0) {//如果链表为空，返回-1表示失败
		return -1;
	}
	else {//如果链表不为空，遍历查找元素
		HashNode* p = &(HT.data[index]);
		while (p != NULL) {
			if (p->key==key) {//找到元素，返回索引位置
				return index;
			}
			p = p->next;
		}
		return -1;//遍历完链表仍未找到元素，返回-1表示失败
	}
}