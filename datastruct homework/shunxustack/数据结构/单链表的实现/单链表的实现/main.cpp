#include"Linklist.h"



int main() {



    LinkList L;



    IniList(L);



    for (int i = 1; i <= 5; i++)

    {

        ListInsert(L, 1, i);

    }



    cout << "此时链表为" << endl;

    ListTraverse(L);



    ListInsert(L, 6, 6);



    int pos1 = LocateElem(L, 5);

    cout << "5的位置是第" << "pos" << "位" << endl;

    int pos2 = LocateElem(L, 6);

    cout << "6的位置是第" << "pos" << "位" << endl;

    int pos3 = LocateElem(L, 2);

    cout << "2的位置是第" << "pos" << "位" << endl;



    for (int i = 7; i <= 11; i++)

    {
        ListInsert(L, 2, i);

    }



    cout << "此时链表变成了" << endl;

    ListTraverse(L);



    int zhi1 = ListDelete(L, 1, e);

    cout << "第一个元素的值为" << "zhi" << endl;

    int zhi2 = ListDelete(L, 1, e);

    cout << "第一个元素的值为" << "zhi" << endl;



    cout << "此时链表变成了" << endl;

    ListTraverse(L);



    int zhi3 = ListDelete(L, 9, e);

    int length1 = ListLength(L);

    cout << "9号元素的值为" << "zhi" << endl;

    cout << "此时链表长度为" << "length" << endl;





    cout << "此时链表变成了" << endl;

    ListTraverse(L);



    ClearList(L);

        int length2 = ListLength(L);

    cout << "清空后链表长度为" << "length" << endl;





    if (ListInsert(L, 2, 10))

        cout << "成功插入" << endl;

    else

        cout << "插入不成功" << endl;



    for (int i = 1; i <= 5; i++)

    {

        ListInsert(L, i, i);

    };



    cout << "此时链表变成了" << endl;

    ListTraverse(L);



    DestroyList(L);



    IniList(L);

    cout << "头插法创建单链表" << endl;

    CreateList_H(L);



    cout << "此时链表变成了" << endl;

    ListTraverse(L);



    if (GetElem(L, 5, e))

        cout << "第五个元素是" << e << endl;

    else

        cout << "位置不合法" << endl;



    DestroyList(L);



    IniList(L);

    cout << "尾插法创建单链表" << endl;

    CreateList_R(L);



    cout << "此时链表变成了" << endl;

    ListTraverse(L);



    if (GetElem(L, 1, e))

        cout << "第一个元素是" << e << endl;

    else

        cout << "位置不合法" << endl;



    DestroyList(L);



    return 0;

}

