#include"Linklist.h"




// 初始化链表
void IniList(LinkList& L) {
    L.head = nullptr;
}

// 创建链表（头插法）
void CreateList_H(LinkList& L) {
    int value;
    cout << "请输入链表元素（以空格分隔，输入666结束）：";

    while (cin >> value && value != 666) {
        ListNode* newNode = new ListNode(value);
        newNode->next = L.head;
        L.head = newNode;
    }
}


// 创建链表（尾插法）
void CreateList_R(LinkList& L) {
    int value;
    ListNode* tail = nullptr;
    cout << "请输入链表元素（以空格分隔，输入666结束）：";

    while (cin >> value && value != 666) {
        ListNode* newNode = new ListNode(value);

        if (L.head == nullptr) {
            L.head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}



// 遍历链表
void ListTraverse(const LinkList& L) {
    cout << "链表元素：";
    ListNode* p = L.head;

    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// 获取链表第i个元素的值 
bool GetElem(const LinkList& L, int i, int& e) {
    if (i <= 0) {
        return false;
    }

    ListNode* p = L.head;
    int count = 1;

    while (p != nullptr && count < i) {
        p = p->next;
        count++;
    }

    if (p == nullptr) {
        return false;
    }

    e = p->data;
    return true;
}

// 查找链表中第一个值为e的元素的位置
int LocateElem(const LinkList& L, const int& e) {
    ListNode* p = L.head;
    int index = 1;

    while (p != nullptr) {
        if (p->data == e) {
            return index;
        }

        p = p->next;
        index++;
    }

    return -1;
}

// 在链表第i个位置插入元素e
bool ListInsert(LinkList& L, int i, const int& e) {
    if (i <= 0) {
        return false;
    }

    ListNode* p = L.head;
    int count = 1;

    while (p != nullptr && count < i - 1) {
        p = p->next;
        count++;
    }

    if (p == nullptr) {
        return false;
    }

    ListNode* newNode = new ListNode(e);
    newNode->next = p->next;
    p->next = newNode;

    return true;
}

// 删除链表第i个位置的元素，并将值存储在e中
bool ListDelete(LinkList& L, int i, int& e) {
    if (i <= 0 || L.head == nullptr) {
        return false;
    }

    ListNode* p = L.head;
    int count = 1;

    if (i == 1) {
        L.head = p->next;
        e = p->data;
        delete p;
        return true;
    }

    while (p->next != nullptr && count < i - 1) {
        p = p->next;
        count++;
    }

    if (p->next == nullptr) {
        return false;
    }

    ListNode* temp = p->next;
    p->next = temp->next;
    e = temp->data;
    delete temp;

    return true;
}

// 判断链表是否为空
bool ListEmpty(const LinkList& L) {
    return L.head == nullptr;
}

// 求链表的长度
int ListLength(const LinkList& L) {
    ListNode* p = L.head;
    int length = 0;

    while (p != nullptr) {
        length++;
        p = p->next;
    }

    return length;
}

// 释放链表内存
void DestroyList(LinkList& L) {
    ListNode* p = L.head;

    while (p != nullptr) {
        ListNode* temp = p;
        p = p->next;
        delete temp;
    }

    L.head = nullptr;
}

// 置空链表
void ClearList(LinkList& L) {
    DestroyList(L);
}





