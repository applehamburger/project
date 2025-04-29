#include "match.h"
#include <iostream>
using namespace std;


// ��ʼ��ջ
Status CreateStack(LinkStack& S) {
    S = NULL;
    return OK;
}

// ��ջ����
Status Push(LinkStack& S, ElemType e)
{
    StackNode* p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;

    return OK;
}

// ��ջ����
Status Pop(LinkStack& S, ElemType& e) {
    if (S == NULL)
        return ERROR;
    e = S->data;
    StackNode* p = S;
    S = S->next;
    delete p;
    return OK;
}

// ��ȡջ��Ԫ��
ElemType GetTop(LinkStack S) {
    if (S != NULL)
        return S->data;
}

Status Traverse(LinkStack S) {
    if (S == NULL) {
        cout << "ջ��" << endl;
        return ERROR;
    }
    StackNode* p = S;
    cout << "����ջ��Ԫ��Ϊ:";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;

    }
    cout << endl;
    return OK;
}

Status ClearStack(LinkStack& S) {
    StackNode* p;
    while (S) {
        p = S;
        S = S->next;
        delete p;
    }
    return OK;
}

Status DestroyStack(LinkStack& S) {
    ClearStack(S);
    S = NULL;
    return OK;
}

bool StackEmpty(LinkStack S) {
    return S == NULL;
}

Status  Matching(LinkStack S)
{
    ElemType ch, e;
    int flag = 1;
    CreateStack(S);

    cin >> ch;
    while (ch != '&' && flag)
    {
        switch (ch)
        {
        case '(': // ��Բ������ջ
        case '[': // ��������ջ
        case '{': // ��������ջ
            Push(S, ch);
            break;

        case ')': // ��Բ����ƥ����Բ����
            if (!StackEmpty(S) && GetTop(S) == '(')
                Pop(S, e);
            else
                flag = 0;
            break;

        case ']': // �ҷ�����ƥ��������
            if (!StackEmpty(S) && GetTop(S) == '[')
                Pop(S, e);
            else
                flag = 0;
            break;

        case '}': // �һ�����ƥ��������
            if (!StackEmpty(S) && GetTop(S) == '{')
                Pop(S, e);
            else
                flag = 0;
            break;
        }

        cin >> ch;
    }
    if (StackEmpty(S) && flag)
        return OK;
    else
        return ERROR;
}