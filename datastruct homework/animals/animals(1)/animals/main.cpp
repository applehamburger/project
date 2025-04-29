#include"animals.h"
int main() {
    AnimalList A;
    InitList(A);
    string animalNames[] = { "Rat", "Ox", "Cat", "Cat", "Tiger", "Rabbit", "Dragon", "Cat", "Snake", "Horse", "Cat", "Goat", "Monkey", "Cat", "Rooster", "Dog", "Cat", "Pig", "Cat" };
    int size = sizeof(animalNames) / sizeof(animalNames[0]);

    // 1. 创建小动物们的单链表并打印 
    cout << "小动物们现在是：" << endl;
    for (int i = 0; i < size; i++) {
        CreateList_R(A, animalNames[i]);
        ListTraverse(A);
    }
    cout << endl;

    // 2. 删除猫节点并打印
    RemoveCats(A);
    cout << "删除猫后十二生肖为:" << endl;
    ListTraverse(A);
    cout << endl;

    // 3. 整理链表并打印
    RemoveCats(A);
    cout << "整理后十二生肖变成了:" << endl;
    ListTraverse(A);
   
    return 0;
}