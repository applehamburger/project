#pragma once
#include <iostream>

using namespace std;

// 数据结构定义
struct Element {
    int key;
    // 其他数据成员（如果有）
};

struct dataList {
    Element* V;
    int length; // 记录元素个数
};


// 交换函数
void Swap(Element& a, Element& b);
// 调整堆函数
void siftDown(dataList& H, int start, int end);
// 堆排序函数
void HeapSort(dataList& H);