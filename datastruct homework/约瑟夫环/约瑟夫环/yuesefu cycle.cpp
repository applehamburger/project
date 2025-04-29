#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next; // 指向下一个结点的指针
};

Node* createLinkedList(int n) {
    Node* head, * p, * q;
    head = new Node;
    head->data = 1;
    head->next = NULL;
    q = head;
    for (int i = 0; i < n; ++i) {
        p = new Node;
        p->data = i + 1;
        q->next = p;
        q = p;
    }
    q->next = head->next; // 将尾结点连接到头结点形成循环链表
    delete head; // 头结点无实际意义，释放内存
    return q->next; // 返回第一个结点的指针
}

int findyuesefu(int n, int m) {
    Node* head = createLinkedList(n); // 创建循环链表
    Node* p = head, * q = head; // p指向要删除的结点，q指向p的上一个结点

    // 循环遍历链表直到只剩一个结点
    while (p->next != p) {
        // 找到第m个结点
        for (int i = 1; i < m; ++i) {
            q = p;
            p = p->next;
        }

        // 删除第m个结点
        q->next = p->next;
        cout << p->data << " "; // 打印自杀的顺序
        Node* r = p;
        p = p->next;
        delete r; // 释放内存
    }
    cout << endl;
    int yuesefu = p->data; // 最后一个自杀者的编号
    delete p; // 释放内存
    return yuesefu;
}

int main() {
    int n = 41, m = 3;
    int yuesefu = findyuesefu(n, m);
    cout << "The final survivor is " << yuesefu << endl;
    return 0;
}