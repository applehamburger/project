#include"heapsort.h"
// 交换函数
void Swap(Element& a, Element& b) {
    Element temp = a;
    a = b;
    b = temp;
}

// 调整堆函数
void siftDown(dataList& H, int start, int end) {
    int root = start;
    while (root * 2 + 1 <= end) { // 存在左子节点
        int child = root * 2 + 1; // 左子节点
        int swapIdx = root; // 需要交换的节点索引
        if (H.V[swapIdx].key < H.V[child].key) { // 如果父节点小于左子节点
            swapIdx = child;
        }
        if (child + 1 <= end && H.V[swapIdx].key < H.V[child + 1].key) { // 如果存在右子节点且父节点小于右子节点
            swapIdx = child + 1;
        }
        if (swapIdx != root) { // 如果需要交换
            Swap(H.V[root], H.V[swapIdx]);
            root = swapIdx;
        }
        else {
            break;
        }
    }
}

// 堆排序函数
void HeapSort(dataList& H) {
    for (int i = (H.length - 2) / 2; i >= 0; i--) {
        siftDown(H, i, H.length - 1); // 初始堆
    }
    for (int i = H.length - 1; i >= 1; i--) {
        Swap(H.V[0], H.V[i]); // 交换
        siftDown(H, 0, i - 1); // 重建最大堆
    }
}