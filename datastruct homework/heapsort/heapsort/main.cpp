#include"heapsort.h"
int main() {
    dataList H;
    int n;
    cout << "请输入元素个数：";
    cin >> n; // 输入元素个数
    H.length = n;
    H.V = new Element[n]; // 动态分配数组内存空间
    cout << "请依次输入元素：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> H.V[i].key; // 输入元素值
    }
    HeapSort(H); // 调用堆排序函数对元素进行排序
    cout << "堆排序后的结果是：" << endl;
    for (int i = 0; i < n; i++) {
        cout << H.V[i].key << " "; // 输出排序结果
    }
    cout << endl;
    delete[] H.V; // 释放数组内存空间
    return 0;
}