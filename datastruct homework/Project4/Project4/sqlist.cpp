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
    L.elem = new ElemType[MAXSIZE];//�����СΪMAXSIZE���ڴ�ռ�
    if (!L.elem) {
        cout << "ʧ��" << endl;
        exit(0);
    }
    //����ʧ�����˳�
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
    //ѭ�������б����
    cout << endl;
}

Status GetElem(const Sqlist& L, int i, ElemType& e) {
    if (i < 1 || i > L.length) {
        return ERROR;
    }//�ж�i�Ƿ����
    e = L.elem[i - 1];//����λ�õ�����������e����
    return OK;
}

int LocateElem(const Sqlist& L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return i + 1;
        }//ѭ���ж���ֵ�Ƿ���e��Ȳ����ظ�λ��
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

    cout << "��ʼ��˳���" << endl;
    InitList(L);
    for (int i = 0; i < sizeof(a) / sizeof(ElemType); i++) {
        ListInsert(L, i + 1, a[i]);
    }

    ListTraverse(L);

    int pos = 3;
    cout << "��˳���ĵ�" << pos << "��λ�ò���Ԫ��e"<<endl;
    ListInsert(L, pos, e);
    ListTraverse(L);



    pos = 3;
    ElemType delelem;
    cout << "ɾ����" << pos << "��Ԫ�ز���������ֵ:" ;
    ListDelete(L, pos, delelem);
    cout<<delelem<<endl;
    
  

    cout << "��e��ͬ��Ԫ���ڵ�"<< LocateElem( L, e)<<"��λ��";
    cout << "���ҵ�������λi���Ҳ�������0" << endl;
    pos = LocateElem(L, e);
    cout << "'" << e << "'";
    cout << "��˳���ĵ�" << pos << "λ" << endl;

    cout << "˳���ĳ���Ϊ��" << ListLength(L) << endl;
    cout << "˳����Ƿ�Ϊ�գ�" << (ListEmpty(L) ? "��" : "��") << endl;

    DestroyList(L);

    return OK;
}

