#pragma once
#include <iostream>
#include <string>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;
typedef  string elemtype;
// ����С����ڵ�
typedef struct AnimalNode {
    elemtype name; // С�����Ӣ����
    AnimalNode* next; // ָ����һ��С����ڵ��ָ��
}ANode, * AnimalList;

Status InitList(AnimalList& A);

void CreateList_R(AnimalList& A, string n);

void ListTraverse(const AnimalList& A);

void RemoveCats(AnimalList& A);

void SortList(AnimalList& A);
