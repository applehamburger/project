#pragma once
#include <string>
#include <iostream>
using namespace std;

#define OK 1

#define ERROR 0








// ���嵥����ڵ�ṹ
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int value) : data(value), next(nullptr) {}
};

// ���嵥����ṹ
struct LinkList {
    ListNode* head;
    LinkList() : head(nullptr) {}
};

// ��ʼ������
void IniList(LinkList& L);

// β�巨

void CreateList_R(LinkList& L);

// ͷ�巨

void CreateList_H(LinkList& L);


// ��������
void ListTraverse(const LinkList& L);

// ��ȡ�����i��Ԫ�ص�ֵ
bool GetElem(const LinkList& L, int i, int& e);

// ���������е�һ��ֵΪe��Ԫ�ص�λ��
int LocateElem(const LinkList& L, const int& e);

// �������i��λ�ò���Ԫ��e
bool ListInsert(LinkList& L, int i, const int& e);

// ɾ�������i��λ�õ�Ԫ�أ�����ֵ�洢��e��
bool ListDelete(LinkList& L, int i, int& e);

// �ж������Ƿ�Ϊ��
bool ListEmpty(const LinkList& L);

// ������ĳ���
int ListLength(const LinkList& L);

// �ͷ������ڴ�
void DestroyList(LinkList& L);

// �ÿ�����
void ClearList(LinkList& L);