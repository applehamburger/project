#include"dancermatch.h"
int main() {
    
    Qelemtype name;
    LinkQueue FQ;
    InitQueue(FQ);
    LinkQueue MQ;
    InitQueue(MQ);
    int num;
    cout << "请输入女士舞者个数:";
    cin >> num;
    cout << "请输入女舞者姓名：";
    for (int i = 0; i < num; i++) {
        cin >> name;
        EnQueue(FQ, name);
    }

    cout << "请输入男士舞者个数:";
    cin >> num;
    cout << "请输入男舞者姓名：";
    for (int i = 0; i < num; i++) {
        cin >> name;
        EnQueue(MQ, name);
    }


    while(!QueueEmpty(FQ) && !QueueEmpty(MQ)) {
        DeQueue(FQ, name);
        cout << name << "和";
        DeQueue(MQ, name);
        cout << name << "是一对" << endl;

    }

    if (!QueueEmpty(FQ) && QueueEmpty(MQ)) {
        cout << "第一个没有舞伴的女士是：";
        GetHead(FQ, name);
    }

    if (QueueEmpty(FQ) && !QueueEmpty(MQ)) {
        cout << "第一个没有舞伴的男士是：";
        GetHead(MQ, name);
    }
	return 0;
}