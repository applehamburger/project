#pragma once
#include <iostream>
#include <string>
using namespace std;

// ����ڵ�
struct ListNode {
    string data; // �ڵ�����
    ListNode* next; // ָ����һ���ڵ��ָ��
};

// ����ṹ
struct List {
    ListNode* head; // ָ������ͷ�ڵ��ָ��
    int length; // ������
};

// ��ʼ������
void InitList(List* L);

// ͷ�巨��������
void CreateList_H(List* L);

// β�巨��������
void CreateList_R(List* L);

// ��������
void ListTraverse(List L);

// ��ȡ��i���ڵ������
bool GetElem(List L, int i, string& e);

// ����Ԫ��e��λ��
int LocateElem(List L, string e);

// �ڵ�i��λ�ò���Ԫ��e
bool ListInsert(List* L, int i, string e);

// ɾ����i���ڵ㣬������ɾ���Ľڵ�����
bool ListDelete(List* L, int i, string& e);

// �ж������Ƿ�Ϊ��
bool ListEmpty(List L);

// ��������
int ListLength(List L);

// �ͷ�����ռ�
void DestroyList(List* L);

// �ÿ�����
void ClearList(List* L);

//��ֵ����
ListNode* Find(List L, string e);

// ����λ���İ�λ���ң�����ָ�룩
ListNode* Locate(List L, int i);
