#include <iostream>
using namespace std;

// ���ݽṹ����
struct Element {
    int key;
    // �������ݳ�Ա������У�
};

struct dataList {
    Element* V;
};

// ���ֺ���
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

// ����������
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

// main����
int main() {
    dataList L;
    int n;
    cout << "������Ԫ�ظ�����";
    cin >> n;
    L.V = new Element[n]; // ��̬���������ڴ�ռ�
    cout << "����������Ԫ�أ�"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> L.V[i].key;
    }
    QuickSort(L, 0, n - 1);
    cout << "���ź�õ�������Ϊ��" << endl;
    Traverse(L, n);
    delete[] L.V; // �ͷ������ڴ�ռ�
    return 0;
}
