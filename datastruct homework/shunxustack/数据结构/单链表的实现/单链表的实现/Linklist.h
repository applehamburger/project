#pragma once
#include <string>
#include <iostream>
using namespace std;

#define OK 1

#define ERROR 0








// 定义单链表节点结构
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int value) : data(value), next(nullptr) {}
};

// 定义单链表结构
struct LinkList {
    ListNode* head;
    LinkList() : head(nullptr) {}
};

// 初始化链表
void IniList(LinkList& L);

// 尾插法

void CreateList_R(LinkList& L);

// 头插法

void CreateList_H(LinkList& L);


// 遍历链表
void ListTraverse(const LinkList& L);

// 获取链表第i个元素的值
bool GetElem(const LinkList& L, int i, int& e);

// 查找链表中第一个值为e的元素的位置
int LocateElem(const LinkList& L, const int& e);

// 在链表第i个位置插入元素e
bool ListInsert(LinkList& L, int i, const int& e);

// 删除链表第i个位置的元素，并将值存储在e中
bool ListDelete(LinkList& L, int i, int& e);

// 判断链表是否为空
bool ListEmpty(const LinkList& L);

// 求链表的长度
int ListLength(const LinkList& L);

// 释放链表内存
void DestroyList(LinkList& L);

// 置空链表
void ClearList(LinkList& L);