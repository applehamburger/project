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

}Sqlist;

Status InitList(Sqlist& L) {
    L.elem = new ElemType[MAXSIZE];//分配大小为MAXSIZE的内存空间
    if (!L.elem) {
        cout << "失败" << endl;
        exit(0);
    }
    //分配失败则退出
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

    int i;
    for (i = 0; i < L.length; i++) {
        cout << L.elem[i] << " ";
    }
    //循环遍历列表并输出
    cout << endl;
}

Status GetElem(const Sqlist& L, int i, ElemType& e) {
    if (i < 1 || i > L.length) {
        return ERROR;
    }//判断i是否合理
    e = L.elem[i - 1];//将该位置的数赋给参数e返回
    return OK;
}

int LocateElem(const Sqlist& L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return i + 1;
        }//循环判断数值是否与e相等并返回该位置
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
    L.length += 1;
    return 0;
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
    ElemType a[] = { 4, 7, 11, 17, 113, 717 }, e = 717;

    cout << "初始化顺序表：" << endl;
    InitList(L);
    for (int i = 0; i < sizeof(a) / sizeof(ElemType); i++) {
        ListInsert(L, i + 1, a[i]);
    }

    ListTraverse(L);

    int pos = 3;
    cout << "在顺序表的第" << pos << "个位置插入元素e"<<endl;
    ListInsert(L, pos, e);
    ListTraverse(L);



    pos = 3;
    ElemType delelem;
    cout << "删除第" << pos << "个元素并返回它的值:" ;
    ListDelete(L, pos, delelem);
    cout<<delelem<<endl;
    
  

    cout << "与e相同的元素在第"<< LocateElem( L, e)<<"个位置";
    cout << "，找到返回序位i，找不到返回0" << endl;
    pos = LocateElem(L, e);
    cout << "'" << e << "'";
    cout << "在顺序表的第" << pos << "位" << endl;

    cout << "顺序表的长度为：" << ListLength(L) << endl;
    cout << "顺序表是否为空：" << (ListEmpty(L) ? "是" : "否") << endl;

    DestroyList(L);

    return OK;
}

