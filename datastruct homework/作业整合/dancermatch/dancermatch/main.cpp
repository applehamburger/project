#include"dancermatch.h"
int main() {
    
    Qelemtype name;
    LinkQueue FQ;
    InitQueue(FQ);
    LinkQueue MQ;
    InitQueue(MQ);
    int num;
    cout << "������Ůʿ���߸���:";
    cin >> num;
    cout << "������Ů����������";
    for (int i = 0; i < num; i++) {
        cin >> name;
        EnQueue(FQ, name);
    }

    cout << "��������ʿ���߸���:";
    cin >> num;
    cout << "������������������";
    for (int i = 0; i < num; i++) {
        cin >> name;
        EnQueue(MQ, name);
    }


    while(!QueueEmpty(FQ) && !QueueEmpty(MQ)) {
        DeQueue(FQ, name);
        cout << name << "��";
        DeQueue(MQ, name);
        cout << name << "��һ��" << endl;

    }

    if (!QueueEmpty(FQ) && QueueEmpty(MQ)) {
        cout << "��һ��û������Ůʿ�ǣ�";
        GetHead(FQ, name);
    }

    if (QueueEmpty(FQ) && !QueueEmpty(MQ)) {
        cout << "��һ��û��������ʿ�ǣ�";
        GetHead(MQ, name);
    }
	return 0;
}