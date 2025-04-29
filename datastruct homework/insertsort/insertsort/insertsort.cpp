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

// 插入排序函数
void InsertSort(dataList& L) {
    Element w;
    int i, j;
    for (i = 1; i < L.length; i++) { // 插入n-1趟
        if (L.V[i].key < L.V[i - 1].key) {
            w = L.V[i];
            L.V[i] = L.V[i - 1];
            for (j = i - 1; j > 0; j--) { // 从后向前比较
                if (w.key < L.V[j - 1].key)
                    L.V[j] = L.V[j - 1];
                else
                    break;
            }
            L.V[j] = w;
        }
    }
}

void BinaryInsSort(dataList& L) {
    Element w; int i, k, left, right, mid;
    for (i = 1; i < L.length; i++) {
        left = 0; right = i - 1; w = L.V[i];
        while (left <= right) {
            //在V[0..i-1] 区间内寻找V[i]的插入位置
            mid = (left + right) / 2; //中间位置
            if (w.key < L.V[mid].key)
                right = mid - 1;
            else left = mid + 1;

        }
        for (k = i - 1; k >= left; k--)
            L.V[k + 1] = L.V[k]; //空出left位置
        L.V[left] = w;

    } // for 
}

// main函数
int main() {
    dataList L;
    int n;
    cout << "请输入元素个数：";
    cin >> n;
    L.length = n;
    L.V = new Element[n]; // 动态分配数组内存空间
    cout << "请依次输入元素：" << endl;   
    for (int i = 0; i < n; i++) {
        cin >> L.V[i].key;
    }
    InsertSort(L);
    cout << "插入排序的结果是：";
    for (int i = 0; i < n; i++) {
        cout << L.V[i].key << " ";
    }
    cout << endl;
    BinaryInsSort(L);
    cout << "折半插入排序的结果是：";
    for (int i = 0; i < n; i++) {
        cout << L.V[i].key << " ";
    }
    delete[] L.V; // 释放数组内存空间
    return 0;
}
