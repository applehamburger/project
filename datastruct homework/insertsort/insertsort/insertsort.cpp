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

// ����������
void InsertSort(dataList& L) {
    Element w;
    int i, j;
    for (i = 1; i < L.length; i++) { // ����n-1��
        if (L.V[i].key < L.V[i - 1].key) {
            w = L.V[i];
            L.V[i] = L.V[i - 1];
            for (j = i - 1; j > 0; j--) { // �Ӻ���ǰ�Ƚ�
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
            //��V[0..i-1] ������Ѱ��V[i]�Ĳ���λ��
            mid = (left + right) / 2; //�м�λ��
            if (w.key < L.V[mid].key)
                right = mid - 1;
            else left = mid + 1;

        }
        for (k = i - 1; k >= left; k--)
            L.V[k + 1] = L.V[k]; //�ճ�leftλ��
        L.V[left] = w;

    } // for 
}

// main����
int main() {
    dataList L;
    int n;
    cout << "������Ԫ�ظ�����";
    cin >> n;
    L.length = n;
    L.V = new Element[n]; // ��̬���������ڴ�ռ�
    cout << "����������Ԫ�أ�" << endl;   
    for (int i = 0; i < n; i++) {
        cin >> L.V[i].key;
    }
    InsertSort(L);
    cout << "��������Ľ���ǣ�";
    for (int i = 0; i < n; i++) {
        cout << L.V[i].key << " ";
    }
    cout << endl;
    BinaryInsSort(L);
    cout << "�۰��������Ľ���ǣ�";
    for (int i = 0; i < n; i++) {
        cout << L.V[i].key << " ";
    }
    delete[] L.V; // �ͷ������ڴ�ռ�
    return 0;
}
