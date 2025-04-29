#pragma once
#include <iostream>
#include <string>
using namespace std;

// 链表节点
struct ListNode {
    string data; // 节点数据
    ListNode* next; // 指向下一个节点的指针
};

// 链表结构
struct List {
    ListNode* head; // 指向链表头节点的指针
    int length; // 链表长度
};

// 初始化链表
void InitList(List* L);

// 头插法创建链表
void CreateList_H(List* L);

// 尾插法创建链表
void CreateList_R(List* L);

// 遍历链表
void ListTraverse(List L);

// 获取第i个节点的数据
bool GetElem(List L, int i, string& e);

// 查找元素e的位置
int LocateElem(List L, string e);

// 在第i个位置插入元素e
bool ListInsert(List* L, int i, string e);

// 删除第i个节点，并返回删除的节点数据
bool ListDelete(List* L, int i, string& e);

// 判断链表是否为空
bool ListEmpty(List L);

// 求链表长度
int ListLength(List L);

// 释放链表空间
void DestroyList(List* L);

// 置空链表
void ClearList(List* L);

//按值查找
ListNode* Find(List L, string e);

// 弱化位序后的按位查找（返回指针）
ListNode* Locate(List L, int i);
