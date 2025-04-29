#include"heapsort.h"
// ��������
void Swap(Element& a, Element& b) {
    Element temp = a;
    a = b;
    b = temp;
}

// �����Ѻ���
void siftDown(dataList& H, int start, int end) {
    int root = start;
    while (root * 2 + 1 <= end) { // �������ӽڵ�
        int child = root * 2 + 1; // ���ӽڵ�
        int swapIdx = root; // ��Ҫ�����Ľڵ�����
        if (H.V[swapIdx].key < H.V[child].key) { // ������ڵ�С�����ӽڵ�
            swapIdx = child;
        }
        if (child + 1 <= end && H.V[swapIdx].key < H.V[child + 1].key) { // ����������ӽڵ��Ҹ��ڵ�С�����ӽڵ�
            swapIdx = child + 1;
        }
        if (swapIdx != root) { // �����Ҫ����
            Swap(H.V[root], H.V[swapIdx]);
            root = swapIdx;
        }
        else {
            break;
        }
    }
}

// ��������
void HeapSort(dataList& H) {
    for (int i = (H.length - 2) / 2; i >= 0; i--) {
        siftDown(H, i, H.length - 1); // ��ʼ��
    }
    for (int i = H.length - 1; i >= 1; i--) {
        Swap(H.V[0], H.V[i]); // ����
        siftDown(H, 0, i - 1); // �ؽ�����
    }
}