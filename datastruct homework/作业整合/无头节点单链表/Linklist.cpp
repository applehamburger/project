#include "Linklist.h"
#include <iostream>
#include <string>
using namespace std;

// 链表节点
struct ListNode {
    string data; // 节点数据
    ListNode* next; // 指向下一个节点的指针
};

// 链表结构
struct List {
    ListNode* head; // 指向链表头节点的指针
    int length; // 链表长度
};

// 初始化链表
void InitList(List* L) {
    L->head = new ListNode; // 创建头节点
    L->head->next = nullptr; // 头节点的指针为空
    L->length = 0; // 长度为0
}

// 头插法创建链表
void CreateList_H(List* L) {
    string str;
    cout << "请输入字符串，以#结束：" << endl;
    while (cin >> str && str != "#") {
        ListNode* newNode = new ListNode; // 创建新节点
        newNode->data = str; // 节点数据为输入的字符串
        newNode->next = L->head->next; // 新节点指向原头节点指向的节点
        L->head->next = newNode; // 头节点指向新节点
        L->length++; // 长度加1
    }
}

// 尾插法创建链表
void CreateList_R(List* L) {
    string str;
    cout << "请输入字符串，以#结束：" << endl;
    ListNode* tail = L->head; // 尾指针初始化为头节点
    while (cin >> str && str != "#") {
        ListNode* newNode = new ListNode; // 创建新节点
        newNode->data = str; // 节点数据为输入的字符串
        newNode->next = nullptr; // 新节点指针为空
        tail->next = newNode; // 尾节点指向新节点
        tail = newNode; // 尾指针后移
        L->length++; // 长度加1
    }
}

// 遍历链表
void ListTraverse(List L) {
    ListNode* p = L.head->next; // 指向第一个节点
    while (p != nullptr) { // 当指针不为空时，输出节点数据并后移指针
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 获取第i个节点的数据
bool GetElem(List L, int i, string& e) {
    if (i < 1 || i > L.length) { // 位置不合法
        return false;
    }
    ListNode* p = L.head->next; // 指向第一个节点
    int j = 1; // 计数器初始化为1
    while (j < i) { // 向后移动指针，直到到达第i个节点
        p = p->next;
        j++;
    }
    e = p->data; // 取出第i个节点的数据
    return true;
}

// 查找元素e的位置
int LocateElem(List L, string e) {
    ListNode* p = L.head->next; // 指向第一个节点
    int i = 1; // 计数器初始化为1
    while (p != nullptr && p->data != e) { // 向后移动指针，直到找到元素e或到达链表末尾
        p = p->next;
        i++;
    }
    if (p == nullptr) { // 没有找到元素e
        return 0;
    }
    return i;
}

// 在第i个位置插入元素e
bool ListInsert(List* L, int i, string e) {
    if (i < 1 || i > L->length + 1) { // 位置不合法
        return false;
    }
    ListNode* p = L->head; // 指向头节点
    int j = 0; // 计数器初始化为0
    while (j < i - 1) { // 向后移动指针，直到到达第i-1个节点
        p = p->next;
        j++;
    }
    ListNode* newNode = new ListNode; // 创建新节点
    newNode->data = e; // 新节点数据为插入的数据
    newNode->next = p->next; // 新节点指向第i个节点
    p->next = newNode; // 第i-1个节点指向新节点
    L->length++; // 长度加1
    return true;
}

// 删除第i个节点，并返回删除的节点数据
bool ListDelete(List* L, int i, string& e) {
    if (i < 1 || i > L->length) { // 位置不合法
        return false;
    }
    ListNode* p = L->head; // 指向头节点
    int j = 0; // 计数器初始化为0
    while (j < i - 1) { // 向后移动指针，直到到达第i-1个节点
        p = p->next;
        j++;
    }
    ListNode* q = p->next; // 指向第i个节点
    e = q->data; // 取出第i个节点的数据
    p->next = q->next; // 第i-1个节点指向第i+1个节点
    delete q; // 释放第i个节点的空间
    L->length--; // 长度减1
    return true;
}

// 判断链表是否为空
bool ListEmpty(List L) {
    return L.length == 0;
}

// 求链表长度
int ListLength(List L) {
    return L.length;
}

// 释放链表空间
void DestroyList(List* L) {
    ListNode* p = L->head; // 指向头节点
    while (p != nullptr) { // 释放每一个节点的空间
        ListNode* q = p;
        p = p->next;
        delete q;
    }
    L->head = nullptr; // 头指针置为空
    L->length = 0; // 长度置为0
}

// 置空链表
void ClearList(List* L) {
    ListNode* p = L->head->next; // 指向第一个节点
    while (p != nullptr) { // 释放每一个节点的空间
        ListNode* q = p;
        p = p->next;
        delete q;
    }
    L->head->next = nullptr; // 头节点指向空
    L->length = 0; // 长度置为0
}

// 弱化位序后的按值查找（返回指针）
ListNode* Find(List L, string e) {
    ListNode* p = L.head->next; // 指向第一个节点
    while (p != nullptr && p->data != e) { // 向后移动指针，直到找到元素e或到达链表末尾
        p = p->next;
    }
    return p;
}

// 弱化位序后的按位查找（返回指针）
ListNode* Locate(List L, int i) {
    if (i < 1 || i > L.length) { // 位置不合法
        return nullptr;
    }
    ListNode* p = L.head->next; // 指向第一个节点
    int j = 1; // 计数器初始化为1
    while (j < i) { // 向后移动指针，直到到达第i个节点
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