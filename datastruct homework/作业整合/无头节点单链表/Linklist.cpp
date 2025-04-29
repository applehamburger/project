#include "Linklist.h"
#include <iostream>
#include <string>
using namespace std;

// ����ڵ�
struct ListNode {
    string data; // �ڵ�����
    ListNode* next; // ָ����һ���ڵ��ָ��
};

// ����ṹ
struct List {
    ListNode* head; // ָ������ͷ�ڵ��ָ��
    int length; // ������
};

// ��ʼ������
void InitList(List* L) {
    L->head = new ListNode; // ����ͷ�ڵ�
    L->head->next = nullptr; // ͷ�ڵ��ָ��Ϊ��
    L->length = 0; // ����Ϊ0
}

// ͷ�巨��������
void CreateList_H(List* L) {
    string str;
    cout << "�������ַ�������#������" << endl;
    while (cin >> str && str != "#") {
        ListNode* newNode = new ListNode; // �����½ڵ�
        newNode->data = str; // �ڵ�����Ϊ������ַ���
        newNode->next = L->head->next; // �½ڵ�ָ��ԭͷ�ڵ�ָ��Ľڵ�
        L->head->next = newNode; // ͷ�ڵ�ָ���½ڵ�
        L->length++; // ���ȼ�1
    }
}

// β�巨��������
void CreateList_R(List* L) {
    string str;
    cout << "�������ַ�������#������" << endl;
    ListNode* tail = L->head; // βָ���ʼ��Ϊͷ�ڵ�
    while (cin >> str && str != "#") {
        ListNode* newNode = new ListNode; // �����½ڵ�
        newNode->data = str; // �ڵ�����Ϊ������ַ���
        newNode->next = nullptr; // �½ڵ�ָ��Ϊ��
        tail->next = newNode; // β�ڵ�ָ���½ڵ�
        tail = newNode; // βָ�����
        L->length++; // ���ȼ�1
    }
}

// ��������
void ListTraverse(List L) {
    ListNode* p = L.head->next; // ָ���һ���ڵ�
    while (p != nullptr) { // ��ָ�벻Ϊ��ʱ������ڵ����ݲ�����ָ��
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// ��ȡ��i���ڵ������
bool GetElem(List L, int i, string& e) {
    if (i < 1 || i > L.length) { // λ�ò��Ϸ�
        return false;
    }
    ListNode* p = L.head->next; // ָ���һ���ڵ�
    int j = 1; // ��������ʼ��Ϊ1
    while (j < i) { // ����ƶ�ָ�룬ֱ�������i���ڵ�
        p = p->next;
        j++;
    }
    e = p->data; // ȡ����i���ڵ������
    return true;
}

// ����Ԫ��e��λ��
int LocateElem(List L, string e) {
    ListNode* p = L.head->next; // ָ���һ���ڵ�
    int i = 1; // ��������ʼ��Ϊ1
    while (p != nullptr && p->data != e) { // ����ƶ�ָ�룬ֱ���ҵ�Ԫ��e�򵽴�����ĩβ
        p = p->next;
        i++;
    }
    if (p == nullptr) { // û���ҵ�Ԫ��e
        return 0;
    }
    return i;
}

// �ڵ�i��λ�ò���Ԫ��e
bool ListInsert(List* L, int i, string e) {
    if (i < 1 || i > L->length + 1) { // λ�ò��Ϸ�
        return false;
    }
    ListNode* p = L->head; // ָ��ͷ�ڵ�
    int j = 0; // ��������ʼ��Ϊ0
    while (j < i - 1) { // ����ƶ�ָ�룬ֱ�������i-1���ڵ�
        p = p->next;
        j++;
    }
    ListNode* newNode = new ListNode; // �����½ڵ�
    newNode->data = e; // �½ڵ�����Ϊ���������
    newNode->next = p->next; // �½ڵ�ָ���i���ڵ�
    p->next = newNode; // ��i-1���ڵ�ָ���½ڵ�
    L->length++; // ���ȼ�1
    return true;
}

// ɾ����i���ڵ㣬������ɾ���Ľڵ�����
bool ListDelete(List* L, int i, string& e) {
    if (i < 1 || i > L->length) { // λ�ò��Ϸ�
        return false;
    }
    ListNode* p = L->head; // ָ��ͷ�ڵ�
    int j = 0; // ��������ʼ��Ϊ0
    while (j < i - 1) { // ����ƶ�ָ�룬ֱ�������i-1���ڵ�
        p = p->next;
        j++;
    }
    ListNode* q = p->next; // ָ���i���ڵ�
    e = q->data; // ȡ����i���ڵ������
    p->next = q->next; // ��i-1���ڵ�ָ���i+1���ڵ�
    delete q; // �ͷŵ�i���ڵ�Ŀռ�
    L->length--; // ���ȼ�1
    return true;
}

// �ж������Ƿ�Ϊ��
bool ListEmpty(List L) {
    return L.length == 0;
}

// ��������
int ListLength(List L) {
    return L.length;
}

// �ͷ�����ռ�
void DestroyList(List* L) {
    ListNode* p = L->head; // ָ��ͷ�ڵ�
    while (p != nullptr) { // �ͷ�ÿһ���ڵ�Ŀռ�
        ListNode* q = p;
        p = p->next;
        delete q;
    }
    L->head = nullptr; // ͷָ����Ϊ��
    L->length = 0; // ������Ϊ0
}

// �ÿ�����
void ClearList(List* L) {
    ListNode* p = L->head->next; // ָ���һ���ڵ�
    while (p != nullptr) { // �ͷ�ÿһ���ڵ�Ŀռ�
        ListNode* q = p;
        p = p->next;
        delete q;
    }
    L->head->next = nullptr; // ͷ�ڵ�ָ���
    L->length = 0; // ������Ϊ0
}

// ����λ���İ�ֵ���ң�����ָ�룩
ListNode* Find(List L, string e) {
    ListNode* p = L.head->next; // ָ���һ���ڵ�
    while (p != nullptr && p->data != e) { // ����ƶ�ָ�룬ֱ���ҵ�Ԫ��e�򵽴�����ĩβ
        p = p->next;
    }
    return p;
}

// ����λ���İ�λ���ң�����ָ�룩
ListNode* Locate(List L, int i) {
    if (i < 1 || i > L.length) { // λ�ò��Ϸ�
        return nullptr;
    }
    ListNode* p = L.head->next; // ָ���һ���ڵ�
    int j = 1; // ��������ʼ��Ϊ1
    while (j < i) { // ����ƶ�ָ�룬ֱ�������i���ڵ�
        p = p->next;
        j++;
    }
    return p;
}

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