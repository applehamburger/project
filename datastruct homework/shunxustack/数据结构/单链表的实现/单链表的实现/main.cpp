#include"Linklist.h"



int main() {



    LinkList L;



    IniList(L);



    for (int i = 1; i <= 5; i++)

    {

        ListInsert(L, 1, i);

    }



    cout << "��ʱ����Ϊ" << endl;

    ListTraverse(L);



    ListInsert(L, 6, 6);



    int pos1 = LocateElem(L, 5);

    cout << "5��λ���ǵ�" << "pos" << "λ" << endl;

    int pos2 = LocateElem(L, 6);

    cout << "6��λ���ǵ�" << "pos" << "λ" << endl;

    int pos3 = LocateElem(L, 2);

    cout << "2��λ���ǵ�" << "pos" << "λ" << endl;



    for (int i = 7; i <= 11; i++)

    {
        ListInsert(L, 2, i);

    }



    cout << "��ʱ��������" << endl;

    ListTraverse(L);



    int zhi1 = ListDelete(L, 1, e);

    cout << "��һ��Ԫ�ص�ֵΪ" << "zhi" << endl;

    int zhi2 = ListDelete(L, 1, e);

    cout << "��һ��Ԫ�ص�ֵΪ" << "zhi" << endl;



    cout << "��ʱ��������" << endl;

    ListTraverse(L);



    int zhi3 = ListDelete(L, 9, e);

    int length1 = ListLength(L);

    cout << "9��Ԫ�ص�ֵΪ" << "zhi" << endl;

    cout << "��ʱ������Ϊ" << "length" << endl;





    cout << "��ʱ��������" << endl;

    ListTraverse(L);



    ClearList(L);

        int length2 = ListLength(L);

    cout << "��պ�������Ϊ" << "length" << endl;





    if (ListInsert(L, 2, 10))

        cout << "�ɹ�����" << endl;

    else

        cout << "���벻�ɹ�" << endl;



    for (int i = 1; i <= 5; i++)

    {

        ListInsert(L, i, i);

    };



    cout << "��ʱ��������" << endl;

    ListTraverse(L);



    DestroyList(L);



    IniList(L);

    cout << "ͷ�巨����������" << endl;

    CreateList_H(L);



    cout << "��ʱ��������" << endl;

    ListTraverse(L);



    if (GetElem(L, 5, e))

        cout << "�����Ԫ����" << e << endl;

    else

        cout << "λ�ò��Ϸ�" << endl;



    DestroyList(L);



    IniList(L);

    cout << "β�巨����������" << endl;

    CreateList_R(L);



    cout << "��ʱ��������" << endl;

    ListTraverse(L);



    if (GetElem(L, 1, e))

        cout << "��һ��Ԫ����" << e << endl;

    else

        cout << "λ�ò��Ϸ�" << endl;



    DestroyList(L);



    return 0;

}

