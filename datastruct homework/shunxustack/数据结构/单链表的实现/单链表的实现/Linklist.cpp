#include"Linklist.h"




// ��ʼ������
void IniList(LinkList& L) {
    L.head = nullptr;
}

// ��������ͷ�巨��
void CreateList_H(LinkList& L) {
    int value;
    cout << "����������Ԫ�أ��Կո�ָ�������666��������";

    while (cin >> value && value != 666) {
        ListNode* newNode = new ListNode(value);
        newNode->next = L.head;
        L.head = newNode;
    }
}


// ��������β�巨��
void CreateList_R(LinkList& L) {
    int value;
    ListNode* tail = nullptr;
    cout << "����������Ԫ�أ��Կո�ָ�������666��������";

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



// ��������
void ListTraverse(const LinkList& L) {
    cout << "����Ԫ�أ�";
    ListNode* p = L.head;

    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// ��ȡ�����i��Ԫ�ص�ֵ 
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

// ���������е�һ��ֵΪe��Ԫ�ص�λ��
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

// �������i��λ�ò���Ԫ��e
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

// ɾ�������i��λ�õ�Ԫ�أ�����ֵ�洢��e��
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

// �ж������Ƿ�Ϊ��
bool ListEmpty(const LinkList& L) {
    return L.head == nullptr;
}

// ������ĳ���
int ListLength(const LinkList& L) {
    ListNode* p = L.head;
    int length = 0;

    while (p != nullptr) {
        length++;
        p = p->next;
    }

    return length;
}

// �ͷ������ڴ�
void DestroyList(LinkList& L) {
    ListNode* p = L.head;

    while (p != nullptr) {
        ListNode* temp = p;
        p = p->next;
        delete temp;
    }

    L.head = nullptr;
}

// �ÿ�����
void ClearList(LinkList& L) {
    DestroyList(L);
}





