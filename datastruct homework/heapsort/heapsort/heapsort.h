#pragma once
#include <iostream>

using namespace std;

// ���ݽṹ����
struct Element {
    int key;
    // �������ݳ�Ա������У�
};

struct dataList {
    Element* V;
    int length; // ��¼Ԫ�ظ���
};


// ��������
void Swap(Element& a, Element& b);
// �����Ѻ���
void siftDown(dataList& H, int start, int end);
// ��������
void HeapSort(dataList& H);