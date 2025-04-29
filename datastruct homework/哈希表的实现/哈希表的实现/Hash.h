#pragma once
#include<iostream>
using namespace std;

//开放地址法散列表的存储表示
#define m 20    //散列表的表长
typedef int KeyType;
typedef int InfoType;
typedef struct HashNode{
	KeyType key;//关键字项
	InfoType otherinfo;//其他数据项
	struct HashNode* next;
}HashNode;

typedef struct {
	HashNode data[m];//哈希表的数组
	int count[m];//链表的长度
}HashTable;

//初始化哈希表
void InitHashTable(HashTable& HT);
//插入元素到哈希表
void Insert(HashTable& HT, KeyType key, InfoType otherinfo);
//查找元素在哈希表中的位置化
int Search(HashTable& HT, KeyType key);
