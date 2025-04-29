#include"search.h"
Status InitList(SSTable &ST) {
	ST.elem = new ElemType[MAXSIZE];//�����СΪMAXSIZE���ڴ�ռ�
	if (!ST.elem) {
		cout << "ʧ��" << endl;
		return ERROR;
	}
	//����ʧ�����˳�
	ST.length = 0;
	return OK;
}

void CreateST(SSTable& ST, int n) {
    if (n > MAXSIZE) {
        cout << "����Ԫ�����������������" << endl;
        return;
    }
    cout << "������Ԫ��" << endl;
    for (int i = 0; i < n; i++) {
        cin >> ST.elem[i].key; 
        ST.length++; //���ӳ��ȼ�����  
    }
}

int Search_Seq(SSTable ST, KeyType key) {
	//��˳���ST��˳�������ؼ��ֵ���key������Ԫ��
	//���ҵ�����ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0
	int i;
	ST.elem[ST.length].key = key;//�ڱ�  ��ȥ���ҹ��̵���ÿһ����Ҫ����������Ƿ�������           �������ڸ��±괦
	//�Ӻ���ǰ��
	for (i = 0; ST.elem[i].key != key; i++);
	return i;//�Ҳ���ʱiΪ0
}
int SeqSearch(SSTable ST, KeyType x, int loc) {
	//�����ݱ�ST.elem[1]...ST.elem[n]�в�����ؼ���ֵ
	//�����ֵxƥ���Ԫ�أ������������ڱ��е�λ��
	//����loc���ڱ��п�ʼ����λ��
	if (loc > ST.length)return 0;//����ʧ��
	else if (ST.elem[loc].key == x)return loc;//���ҳɹ�
	else return SeqSearch(ST, x, loc + 1);
}
void bubble_sort(SSTable& ST, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (ST.elem[j + 1].key < ST.elem[j].key)
			{
				int temp = ST.elem[j].key;
				ST.elem[j].key = ST.elem[j + 1].key;
				ST.elem[j + 1].key = temp;
			}
		}
	}
}
void Traverse(SSTable ST) {
	for (int i = 0; i < ST.length; i++) {
		cout << ST.elem[i].key;
		cout << " ";
	}
}
int Search_Bin(SSTable ST, KeyType key) {
	int low = 1, high = ST.length, mid;//�������ֵ
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == ST.elem[mid].key)
			return mid;//�ҵ�����Ԫ��
		else if (key < ST.elem[mid].key)
			high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}
int BinSearch(SSTable ST, KeyType x, int low, int high) {
	int mid = 0;
	if (low <= high) {
		mid = (low + high) / 2;
		if (ST.elem[mid].key < x)
			mid = BinSearch(ST, x, mid + 1, high);
		else if (ST.elem[mid].key > x)
			mid = BinSearch(ST, x, low, mid - 1);
		else
			return mid;
	}
}