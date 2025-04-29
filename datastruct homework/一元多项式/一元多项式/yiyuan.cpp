#include <iostream>
#include <cmath>

using namespace std;

struct PolyNode {
    float coef; // 系数
    int expn; // 指数
    PolyNode* next;
};

// 创建新结点
PolyNode* newNode(float coef, int expn) {
    PolyNode* p = new PolyNode;
    p->coef = coef;
    p->expn = expn;
    p->next = nullptr;
    return p;
}

// 头插法创建多项式
void CreatePolyn_Head(PolyNode*& P) {
    P = newNode(0, 0); // 创建头结点
    PolyNode* r = P; // r始终指向尾结点
    int n;
    float c;
    int e;
    cout << "请输入项数：";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "请输入第" << i << "项的系数和指数：";
        cin >> c >> e;
        PolyNode* s = newNode(c, e);
        s->next = r->next;
        r->next = s;
        r = s;
    }
}

// 尾插法创建多项式
void CreatePolyn_Tail(PolyNode*& P) {
    P = newNode(0, 0); // 创建头结点
    PolyNode* r = P; // r始终指向尾结点
    int n;
    float c;
    int e;
    cout << "请输入项数：";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "请输入第" << i << "项的系数和指数：";
        cin >> c >> e;
        PolyNode* s = newNode(c, e);
        r->next = s;
        r = s;
    }
    r->next = nullptr;
}

// 有序插入多项式（升级版）
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

    if (p && expn == p->expn) { // 指数相同，系数相加
        p->coef += coef;
        if (p->coef == 0) { // 系数为0，删除该结点
            pre->next = p->next;
            delete p;
        }
    }
    else { // 插入新结点
        PolyNode* newNode = ::new PolyNode;
        newNode->coef = coef;
        newNode->expn = expn;
        newNode->next = p;
        pre->next = newNode;
    }
}

// 相加两个多项式
PolyNode* Add(PolyNode* Pa, PolyNode* Pb) {
    PolyNode* Pc = newNode(0, 0); // 创建结果多项式
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

    while (pa) { // 将剩余的结点加入到结果多项式中
        pc->next = newNode(pa->coef, pa->expn);
        pa = pa->next;
        pc = pc->next;
    }

    while (pb) { // 将剩余的结点加入到结果多项式中
        pc->next = newNode(pb->coef, pb->expn);
        pb = pb->next;
        pc = pc->next;
    }

    return Pc;
}

// 相减两个多项式
PolyNode* Sub(PolyNode* Pa, PolyNode* Pb) {
    PolyNode* Pc = newNode(0, 0); // 创建结果多项式
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

    while (pa) { // 将剩余的结点加入到结果多项式中
        pc->next = newNode(pa->coef, pa->expn);
        pa = pa->next;
        pc = pc->next;
    }

    while (pb) { // 将剩余的结点加入到结果多项式中
        pc->next = newNode(-pb->coef, pb->expn);
        pb = pb->next;
        pc = pc->next;
    }

    return Pc;
}

// 打印多项式
void Traverse(PolyNode* P) {
    if (P->next == nullptr) { // 多项式为空，直接输出0
        cout << "0";
    }
    else {
        PolyNode* p = P->next;
        if (p->expn == 0) { // 常数项特判
            cout << p->coef;
        }
        else {
            if (p->coef == -1) { // 系数为-1特判
                cout << "-";
            }
            else if (p->coef != 1) { // 系数不为1或-1时输出系数
                cout << p->coef;
            }

            if (p->expn == 1) { // 指数为1时直接输出x
                cout << "x";
            }
            else if (p->expn > 1) { // 指数大于1时输出x^%d
                cout << "x^" << p->expn;
            }

            p = p->next;
            while (p) {
                if (p->coef > 0) { // 系数大于0时输出+
                    cout << "+";
                }
                if (p->coef == -1) { // 系数为-1特判
                    cout << "-";
                }
                else if (p->coef != 1) { // 系数不为1或-1时输出系数
                    cout << p->coef;
                }

                if (p->expn == 1) { // 指数为1时直接输出x
                    cout << "x";
                }
                else if (p->expn > 1) { // 指数大于1时输出x^%d
                    cout << "x^" << p->expn;
                }

                p = p->next;
            }
        }
    }
    cout << endl;
}

// 反转多项式
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

// 求多项式在x处的值
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

    // 使用头插法创建多项式A
    cout << "用头插法创建多项式A：" << endl;
    CreatePolyn_Head(A);

    // 使用尾插法创建多项式B
    cout << "用尾插法创建多项式B：" << endl;
    CreatePolyn_Tail(B);

    // 显示多项式A、B
    cout << "多项式A：";
    Traverse(A);
    cout << "多项式B：";
    Traverse(B);

    // 计算多项式A、B的和并显示结果
    C = Add(A, B);
    cout << "多项式A+B的和：";
    Traverse(C);

    // 计算多项式A、B的差并显示结果
    D = Sub(A, B);
    cout << "多项式A-B的差：";
    Traverse(D);

    // 反转多项式A
    Reverse(A);
    cout << "反转多项式A后：";
    Traverse(A);

    // 求多项式A在x=2处的值
    cout << "多项式A在x=2处的值：" << Evaluate(A, 2) << endl;

    // 释放内存
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
