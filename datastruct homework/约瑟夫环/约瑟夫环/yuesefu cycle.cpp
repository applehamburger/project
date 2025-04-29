#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next; // ָ����һ������ָ��
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
    q->next = head->next; // ��β������ӵ�ͷ����γ�ѭ������
    delete head; // ͷ�����ʵ�����壬�ͷ��ڴ�
    return q->next; // ���ص�һ������ָ��
}

int findyuesefu(int n, int m) {
    Node* head = createLinkedList(n); // ����ѭ������
    Node* p = head, * q = head; // pָ��Ҫɾ���Ľ�㣬qָ��p����һ�����

    // ѭ����������ֱ��ֻʣһ�����
    while (p->next != p) {
        // �ҵ���m�����
        for (int i = 1; i < m; ++i) {
            q = p;
            p = p->next;
        }

        // ɾ����m�����
        q->next = p->next;
        cout << p->data << " "; // ��ӡ��ɱ��˳��
        Node* r = p;
        p = p->next;
        delete r; // �ͷ��ڴ�
    }
    cout << endl;
    int yuesefu = p->data; // ���һ����ɱ�ߵı��
    delete p; // �ͷ��ڴ�
    return yuesefu;
}

int main() {
    int n = 41, m = 3;
    int yuesefu = findyuesefu(n, m);
    cout << "The final survivor is " << yuesefu << endl;
    return 0;
}