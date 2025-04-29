#include "Linklist.h"

int main() {
    List L;
    InitList(&L);
    CreateList_H(&L);
    ListTraverse(L);
    string e;
    GetElem(L, 2, e);
    cout << "第2个节点的数据为：" << e << endl;
    int pos = LocateElem(L, "you");
    if (pos == 0) {
        cout << "链表中不存在元素\"you\"" << endl;
    }
    else {
        cout << "\"you\"的位置为：" << pos << endl;
    }
    ListInsert(&L, 3, "bbt");
    ListTraverse(L);
    ListDelete(&L, 2, e);
    cout << "删除的元素为：" << e << endl;
    ListTraverse(L);
    cout << "链表是否为空：" << ListEmpty(L) << endl;
    cout << "链表长度为：" << ListLength(L) << endl;
    DestroyList(&L);
    cout << "链表是否为空：" << ListEmpty(L) << endl;
    cout << "链表长度为：" << ListLength(L) << endl;
    return 0;
}