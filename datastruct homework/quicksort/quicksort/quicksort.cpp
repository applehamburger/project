#include <iostream>
using namespace std;

// 数据结构定义
struct Element {
    int key;
    // 其他数据成员（如果有）
};

struct dataList {
    Element* V;
};

// 划分函数
int Partition(dataList& L, int i, int j) {
    Element w = L.V[i];
    while (i < j) {
        while (i < j && L.V[j].key >= w.key)
            j--;
        L.V[i] = L.V[j];
        while (i < j && L.V[i].key <= w.key)
            i++;
        L.V[j] = L.V[i];
    }
    L.V[i] = w;
    return i;
}

// 快速排序函数
void QuickSort(dataList& L, int left, int right) {
    if (left < right) {
        int pivotpos = Partition(L, left, right);
        QuickSort(L, left, pivotpos - 1);
        QuickSort(L, pivotpos + 1, right);
    }
}

void Traverse(dataList& L, int n){
    for (int i = 0; i < n; i++)
        cout << L.V[i].key<<" ";
}

// main函数
int main() {
    dataList L;
    int n;
    cout << "请输入元素个数：";
    cin >> n;
    L.V = new Element[n]; // 动态分配数组内存空间
    cout << "请依次输入元素："<<endl;
    for (int i = 0; i < n; i++) {
        cin >> L.V[i].key;
    }
    QuickSort(L, 0, n - 1);
    cout << "快排后得到的数组为：" << endl;
    Traverse(L, n);
    delete[] L.V; // 释放数组内存空间
    return 0;
}
