#pragma once
#include <iostream>
#include <string>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;
typedef  string elemtype;
// 定义小动物节点
typedef struct AnimalNode {
    elemtype name; // 小动物的英文名
    AnimalNode* next; // 指向下一个小动物节点的指针
}ANode, * AnimalList;

Status InitList(AnimalList& A);

void CreateList_R(AnimalList& A, string n);

void ListTraverse(const AnimalList& A);

void RemoveCats(AnimalList& A);

void SortList(AnimalList& A);
