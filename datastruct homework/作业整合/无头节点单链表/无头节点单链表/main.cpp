#include "Linklist.h"

int main() {
    List L;
    InitList(&L);
    CreateList_H(&L);
    ListTraverse(L);
    string e;
    GetElem(L, 2, e);
    cout << "��2���ڵ������Ϊ��" << e << endl;
    int pos = LocateElem(L, "you");
    if (pos == 0) {
        cout << "�����в�����Ԫ��\"you\"" << endl;
    }
    else {
        cout << "\"you\"��λ��Ϊ��" << pos << endl;
    }
    ListInsert(&L, 3, "bbt");
    ListTraverse(L);
    ListDelete(&L, 2, e);
    cout << "ɾ����Ԫ��Ϊ��" << e << endl;
    ListTraverse(L);
    cout << "�����Ƿ�Ϊ�գ�" << ListEmpty(L) << endl;
    cout << "������Ϊ��" << ListLength(L) << endl;
    DestroyList(&L);
    cout << "�����Ƿ�Ϊ�գ�" << ListEmpty(L) << endl;
    cout << "������Ϊ��" << ListLength(L) << endl;
    return 0;
}