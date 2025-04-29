
#include<iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType* elem;
    int length;
} Sqlist;

Status InitList(Sqlist& L) {
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem)
        exit(0);
    L.length = 0;
    return OK;
}

Status DestroyList(Sqlist& L) {
    delete[] L.elem;
    L.elem = NULL;
    L.length = 0;
    return OK;
}

Status ClearList(Sqlist& L) {
    L.length = 0;
    return OK;
}

void ListTraverse(const Sqlist& L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

Status GetElem(const Sqlist& L, int i, ElemType& e) {
    if (i < 1 || i > L.length) {
        return ERROR;
    }
    e = L.elem[i - 1];
    return OK;
}

int LocateElem(const Sqlist& L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

Status ListInsert(Sqlist& L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) {
        return ERROR;
    }

    for (int j = L.length - 1; j >= i - 1; j--) {
        L.elem[j + 1] = L.elem[j];
    }

    L.elem[i - 1] = e;
    L.length++;
    return OK;
}

Status ListDelete(Sqlist& L, int i, ElemType& e) {
    if (i < 1 || i > L.length) {
        return ERROR;
    }

    e = L.elem[i - 1];
    for (int j = i; j < L.length; j++) {
        L.elem[j - 1] = L.elem[j];
    }

    L.length--;
    return OK;
}

int ListLength(const Sqlist& L) {
    return L.length;
}

bool ListEmpty(const Sqlist& L) {
    return L.length == 0;
}

int main() {
    Sqlist L;
    ElemType a[] = { 3, 6, 9, 16, 309, 929 }, e = 9;

    cout << "初始化顺序表：" << endl;
    InitList(L);
    for (int i = 0; i < sizeof(a) / sizeof(ElemType); i++) {
        ListInsert(L, i + 1, a[i]);
    }
    ListTraverse(L);

    int pos = 3;
    cout << "在顺序表的第" << pos << "个位置插入元素e";
    cout << "'" << e << "'" << ":" << endl;
    ListInsert(L, pos, e);
    ListTraverse(L);

大绿绿青蛙变蝌蚪:

    pos = 5;
    ElemType delelem;
    cout << "删除第" << pos << "个元素并返回它的值" << endl;
    ListDelete(L, pos, delelem);
    ListTraverse(L);

    cout << "查找与e相同的元素";
    cout << "'" << e << "'";
    cout << "，找到返回序位i，找不到返回0" << endl;
    pos = LocateElem(L, e);
    cout << "'" << e << "'";
    cout << "在顺序表的第" << pos << "位" << endl;

    cout << "顺序表的长度为：" << ListLength(L) << endl;
    cout << "顺序表是否为空：" << (ListEmpty(L) ? "是" : "否") << endl;

    DestroyList(L);

    return OK;
}
