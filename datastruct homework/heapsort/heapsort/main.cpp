#include"heapsort.h"
int main() {
    dataList H;
    int n;
    cout << "������Ԫ�ظ�����";
    cin >> n; // ����Ԫ�ظ���
    H.length = n;
    H.V = new Element[n]; // ��̬���������ڴ�ռ�
    cout << "����������Ԫ�أ�" << endl;
    for (int i = 0; i < n; i++) {
        cin >> H.V[i].key; // ����Ԫ��ֵ
    }
    HeapSort(H); // ���ö���������Ԫ�ؽ�������
    cout << "�������Ľ���ǣ�" << endl;
    for (int i = 0; i < n; i++) {
        cout << H.V[i].key << " "; // ���������
    }
    cout << endl;
    delete[] H.V; // �ͷ������ڴ�ռ�
    return 0;
}