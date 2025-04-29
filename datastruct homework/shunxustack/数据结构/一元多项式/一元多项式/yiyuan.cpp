#include <iostream>
#include <cmath>

using namespace std;

struct PolyNode {
    float coef; // ϵ��
    int expn; // ָ��
    PolyNode* next;
};

// �����½��
PolyNode* newNode(float coef, int expn) {
    PolyNode* p = new PolyNode;
    p->coef = coef;
    p->expn = expn;
    p->next = nullptr;
    return p;
}

// ͷ�巨��������ʽ
void CreatePolyn_Head(PolyNode*& P) {
    P = newNode(0, 0); // ����ͷ���
    PolyNode* r = P; // rʼ��ָ��β���
    int n;
    float c;
    int e;
    cout << "������������";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "�������" << i << "���ϵ����ָ����";
        cin >> c >> e;
        PolyNode* s = newNode(c, e);
        s->next = r->next;
        r->next = s;
        r = s;
    }
}

// β�巨��������ʽ
void CreatePolyn_Tail(PolyNode*& P) {
    P = newNode(0, 0); // ����ͷ���
    PolyNode* r = P; // rʼ��ָ��β���
    int n;
    float c;
    int e;
    cout << "������������";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "�������" << i << "���ϵ����ָ����";
        cin >> c >> e;
        PolyNode* s = newNode(c, e);
        r->next = s;
        r = s;
    }
    r->next = nullptr;
}

// ����������ʽ�������棩
void orderInsert(PolyNode*& P, float coef, int expn) {
    if (coef == 0) {
        return;
    }

    PolyNode* pre = P;
    PolyNode* p = P->next;
    while (p && expn < p->expn) {
        pre = p;
        p = p->next;
    }

    if (p && expn == p->expn) { // ָ����ͬ��ϵ�����
        p->coef += coef;
        if (p->coef == 0) { // ϵ��Ϊ0��ɾ���ý��
            pre->next = p->next;
            delete p;
        }
    }
    else { // �����½��
        PolyNode* newNode = ::new PolyNode;
        newNode->coef = coef;
        newNode->expn = expn;
        newNode->next = p;
        pre->next = newNode;
    }
}

// �����������ʽ
PolyNode* Add(PolyNode* Pa, PolyNode* Pb) {
    PolyNode* Pc = newNode(0, 0); // �����������ʽ
    PolyNode* pa = Pa->next;
    PolyNode* pb = Pb->next;
    PolyNode* pc = Pc;

    while (pa && pb) {
        if (pa->expn < pb->expn) {
            pc->next = newNode(pa->coef, pa->expn);
            pa = pa->next;
        }
        else if (pa->expn > pb->expn) {
            pc->next = newNode(pb->coef, pb->expn);
            pb = pb->next;
        }
        else {
            float sum = pa->coef + pb->coef;
            if (sum != 0) {
                pc->next = newNode(sum, pa->expn);
            }
            pa = pa->next;
            pb = pb->next;
        }
        pc = pc->next;
    }

    while (pa) { // ��ʣ��Ľ����뵽�������ʽ��
        pc->next = newNode(pa->coef, pa->expn);
        pa = pa->next;
        pc = pc->next;
    }

    while (pb) { // ��ʣ��Ľ����뵽�������ʽ��
        pc->next = newNode(pb->coef, pb->expn);
        pb = pb->next;
        pc = pc->next;
    }

    return Pc;
}

// �����������ʽ
PolyNode* Sub(PolyNode* Pa, PolyNode* Pb) {
    PolyNode* Pc = newNode(0, 0); // �����������ʽ
    PolyNode* pa = Pa->next;
    PolyNode* pb = Pb->next;
    PolyNode* pc = Pc;

    while (pa && pb) {
        if (pa->expn < pb->expn) {
            pc->next = newNode(pa->coef, pa->expn);
            pa = pa->next;
        }
        else if (pa->expn > pb->expn) {
            pc->next = newNode(-pb->coef, pb->expn);
            pb = pb->next;
        }
        else {
            float sub = pa->coef - pb->coef;
            if (sub != 0) {
                pc->next = newNode(sub, pa->expn);
            }
            pa = pa->next;
            pb = pb->next;
        }
        pc = pc->next;
    }

    while (pa) { // ��ʣ��Ľ����뵽�������ʽ��
        pc->next = newNode(pa->coef, pa->expn);
        pa = pa->next;
        pc = pc->next;
    }

    while (pb) { // ��ʣ��Ľ����뵽�������ʽ��
        pc->next = newNode(-pb->coef, pb->expn);
        pb = pb->next;
        pc = pc->next;
    }

    return Pc;
}

// ��ӡ����ʽ
void Traverse(PolyNode* P) {
    if (P->next == nullptr) { // ����ʽΪ�գ�ֱ�����0
        cout << "0";
    }
    else {
        PolyNode* p = P->next;
        if (p->expn == 0) { // ����������
            cout << p->coef;
        }
        else {
            if (p->coef == -1) { // ϵ��Ϊ-1����
                cout << "-";
            }
            else if (p->coef != 1) { // ϵ����Ϊ1��-1ʱ���ϵ��
                cout << p->coef;
            }

            if (p->expn == 1) { // ָ��Ϊ1ʱֱ�����x
                cout << "x";
            }
            else if (p->expn > 1) { // ָ������1ʱ���x^%d
                cout << "x^" << p->expn;
            }

            p = p->next;
            while (p) {
                if (p->coef > 0) { // ϵ������0ʱ���+
                    cout << "+";
                }
                if (p->coef == -1) { // ϵ��Ϊ-1����
                    cout << "-";
                }
                else if (p->coef != 1) { // ϵ����Ϊ1��-1ʱ���ϵ��
                    cout << p->coef;
                }

                if (p->expn == 1) { // ָ��Ϊ1ʱֱ�����x
                    cout << "x";
                }
                else if (p->expn > 1) { // ָ������1ʱ���x^%d
                    cout << "x^" << p->expn;
                }

                p = p->next;
            }
        }
    }
    cout << endl;
}

// ��ת����ʽ
void Reverse(PolyNode*& P) {
    PolyNode* p, * q, * r;
    p = P->next;
    q = nullptr;
    P->next = nullptr;
    while (p) {
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    P->next = q;
}

// �����ʽ��x����ֵ
float Evaluate(PolyNode* P, float x) {
    float sum = 0;
    PolyNode* p = P->next;
    while (p) {
        sum += p->coef * pow(x, p->expn);
        p = p->next;
    }
    return sum;
}

int main() {
    PolyNode* A, * B, * C, * D;

    // ʹ��ͷ�巨��������ʽA
    cout << "��ͷ�巨��������ʽA��" << endl;
    CreatePolyn_Head(A);

    // ʹ��β�巨��������ʽB
    cout << "��β�巨��������ʽB��" << endl;
    CreatePolyn_Tail(B);

    // ��ʾ����ʽA��B
    cout << "����ʽA��";
    Traverse(A);
    cout << "����ʽB��";
    Traverse(B);

    // �������ʽA��B�ĺͲ���ʾ���
    C = Add(A, B);
    cout << "����ʽA+B�ĺͣ�";
    Traverse(C);

    // �������ʽA��B�Ĳ��ʾ���
    D = Sub(A, B);
    cout << "����ʽA-B�Ĳ";
    Traverse(D);

    // ��ת����ʽA
    Reverse(A);
    cout << "��ת����ʽA��";
    Traverse(A);

    // �����ʽA��x=2����ֵ
    cout << "����ʽA��x=2����ֵ��" << Evaluate(A, 2) << endl;

    // �ͷ��ڴ�
    PolyNode* p;
    while (A) {
        p = A;
        A = A->next;
        delete p;
    }
    while (B) {
        p = B;
        B = B->next;
        delete p;
    }
    while (C) {
        p = C;
        C = C->next;
        delete p;
    }
    while (D) {
        p = D;
        D = D->next;
        delete p;
    }

    return 0;
}
