#include"animals.h"
int main() {
    AnimalList A;
    InitList(A);
    string animalNames[] = { "Rat", "Ox", "Cat", "Cat", "Tiger", "Rabbit", "Dragon", "Cat", "Snake", "Horse", "Cat", "Goat", "Monkey", "Cat", "Rooster", "Dog", "Cat", "Pig", "Cat" };
    int size = sizeof(animalNames) / sizeof(animalNames[0]);

    // 1. ����С�����ǵĵ�������ӡ 
    cout << "С�����������ǣ�" << endl;
    for (int i = 0; i < size; i++) {
        CreateList_R(A, animalNames[i]);
        ListTraverse(A);
    }
    cout << endl;

    // 2. ɾ��è�ڵ㲢��ӡ
    RemoveCats(A);
    cout << "ɾ��è��ʮ����ФΪ:" << endl;
    ListTraverse(A);
    cout << endl;

    // 3. ����������ӡ
    RemoveCats(A);
    cout << "�����ʮ����Ф�����:" << endl;
    ListTraverse(A);
   
    return 0;
}