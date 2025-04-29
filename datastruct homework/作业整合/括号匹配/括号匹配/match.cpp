#include "match.h"
#include <iostream>
using namespace std;


// ³õÊ¼»¯Õ»
Status CreateStack(LinkStack& S) {
    S = NULL;
    return OK;
}

// ÈëÕ»²Ù×÷
Status Push(LinkStack& S, ElemType e)
{
    StackNode* p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;

    return OK;
}

// ³öÕ»²Ù×÷
Status Pop(LinkStack& S, ElemType& e) {
    if (S == NULL)
        return ERROR;
    e = S->data;
    StackNode* p = S;
    S = S->next;
    delete p;
    return OK;
}

// »ñÈ¡Õ»¶¥ÔªËØ
ElemType GetTop(LinkStack S) {
    if (S != NULL)
        return S->data;
}

Status Traverse(LinkStack S) {
    if (S == NULL) {
        cout << "Õ»¿Õ" << endl;
        return ERROR;
    }
    StackNode* p = S;
    cout << "´ËÁ´Õ»ÖÐÔªËØÎª:";
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
        case '(': // ×óÔ²À¨ºÅÈëÕ»
        case '[': // ×ó·½À¨ºÅÈëÕ»
        case '{': // ×ó»¨À¨ºÅÈëÕ»
            Push(S, ch);
            break;

        case ')': // ÓÒÔ²À¨ºÅÆ¥Åä×óÔ²À¨ºÅ
            if (!StackEmpty(S) && GetTop(S) == '(')
                Pop(S, e);
            else
                flag = 0;
            break;

        case ']': // ÓÒ·½À¨ºÅÆ¥Åä×ó·½À¨ºÅ
            if (!StackEmpty(S) && GetTop(S) == '[')
                Pop(S, e);
            else
                flag = 0;
            break;

        case '}': // ÓÒ»¨À¨ºÅÆ¥Åä×ó»¨À¨ºÅ
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