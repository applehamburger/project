#include"Huffman.h"
int FindWeight(char code[], char p[], int w[]) {
	if (strlen(code) == 0)return 0;
	int num = 1;//��¼code�в�ͬ���ַ�����
	p[0] = code[0];
	w[0]++;
	for (int i = 1; i < strlen(code); i++) {
		for (int j = 0; j < num; j++) {
			if (code[i] == p[j]) {
				//code[i]�Ѿ����ֹ�������Ȩֵ��1�����˳���ѭ��
				w[j]++;
				break;
			}
			if (j == num - 1) {
				//code[i]δ���ֹ�����¼��p�У���Ȩֵ��Ϊ1
				p[num] = code[i];
				w[num]++;
				num++;
				break;
			}
		}
	}
	return num;
}
void CreateHuffmanTree(HuffmanTree& HT, int n, int w[]) {
	//�����������HT
	if (n <= 1)return;
	int m = 2 * n - 1;
	int s1 = 0, s2 = 0;
	HT = new HTNode[m];
	for (int i = 0; i < m ; i++) {//��1~m�ŵ�Ԫ�е�˫�ס����ӡ��Һ��ӵ��±��ʼ��Ϊ0
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 0; i < n; i++) {//����ǰn����Ԫ��Ҷ�ӽ���Ȩֵ
		HT[i].weight = w[i];
	}
	//��ʼ����������ʼ������������
	for (int i = n ; i < m; i++) {//ͨ��n-1�ε�ѡ��ɾ�����ϲ���������������
		Select(HT, i - 1, s1, s2);//��HT[k](1<=k<=i-1)��ѡ��������˫����Ϊ0��Ȩֵ��С�Ľ�㣬������������HT�е����s1��s2
		HT[s1].parent = i;//�õ��½��i����ɭ����ɾ��s1��s2����s1��s2��˫������0��Ϊi
		HT[s2].parent = i;
		HT[i].lchild = s1;//s1��s2�ֱ���Ϊi�����Һ���
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;//i��ȨֵΪ���Һ���Ȩֵ֮��
	}
}

void Select(HuffmanTree& HT, int k, int &s1, int &s2) {
	int min1, min2;
	int i = 0;//�������飬��ʼ�±�Ϊ1
	while (HT[i].parent != 0 && i < k)//�ҵ���û�������Ľ��
		i++;
	min1 = HT[i].weight;
	s1 = i;
	i++;
	while (HT[i].parent != 0 && i < k)
		i++;
	//���ҵ����������Ƚϴ�С��min1ΪС�ģ�min2Ϊ���
	if (HT[i].weight < min1) {
		min2 = min1;
		s2 = s1;
		min1 = HT[i].weight;
		s1 = i;
	}
	else {
		min2 = HT[i].weight;
		s2 = i;
	}
	//�������ͺ���������δ���������Ľ�����Ƚ�
	for (int j = i + 1; j <= k; j++) {
		if (HT[i].parent != 0)//����и���㣬ֱ��������������һ��
			continue;
		if (HT[j].weight < min1) {//�������С�Ļ�С����min2=min1,min1��ֵ�µĽ����±�
			min2 = min1;
			min1 = HT[j].weight;
			s2 = s1;
			s1 = j;
		}
		else if (HT[j].weight >= min1 && HT[j].weight < min2) {//�����������֮�䣬min2��ֵΪ�µĽ���λ���±�
			min2 = HT[j].weight;
			s2 = j;
		}
	}
}
void CreateHuffmanCode(HuffmanTree HT, int n, int q[][10], int road[]) {
	//��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC��
	//HC = new char* [n + 1];//����洢n���ַ�����ı����ռ�   
	//char* cd = new char[n];//������ʱ���ÿ���ַ�����Ķ�̬����ռ�
	//cd[n - 1] = '\0';//���������
	int HC[10];//�洢�ַ��ı���
	memset(HC, 0, sizeof(HC));
	int f = 0;//fָ��ǰ���c��˫�׽��
	int c = 0;//cָ��ǰ���
	int x = 0;//HC�ַ��������ָ��
	for (int i = 0; i < n; i++) {//����ַ������������
		//int start = n - 1;   //start��ʼʱָ����󣬼����������λ��
		c = i;  //fָ����c��˫�׽��
		f = HT[c].parent;
		while (f != 0) {   //��Ҷ�ӽ�㿪ʼ���ϻ��ݣ�ֱ�������
			//--start;//����һ��start��ǰָһ��λ��
			if (HT[f].lchild == c) {
				HC[x] = 0;//���c��f�����ӣ������ɴ���0
				road[i]++;
			}
			else {
				HC[x] = 1;   //���c��f���Һ��ӣ������ɴ���1
				road[i]++;
			}
			x++;
			c = f;
			f = HT[f].parent;  //�������ϻ���,����Ѱ��˫�׽��
		}  
		for (int j = 0; j < x; j++) {
			q[i][j] = HC[x - j - 1];
		}
		x = 0;
		//�����i���ַ��ı���
		//HC[i] = new char[n - start];    //Ϊ��i���ַ��������ռ�
		//strcpy(HC[i], &cd[start]);   //����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�ǰ����
	}
	//delete[]cd;   //�ͷ���ʱ�ռ� 
	cout << "����ɹ���" << endl;
}
void HuffmanDecode(int code2[], HuffmanTree& HT, char p[], int n) {
	int i = 0;
	int j = 2 * n - 2;   //������±�
	int x = 0;
	int count = 0;
	while (code2[i] == 1 || code2[i] == 0) {
		if (code2[i] == 1) {
			count++;
			x = HT[j].rchild;
			j = x;//���¸��ڵ�
			if (HT[x].rchild == 0) {//��ǰ���û���Һ��ӣ�˵��λΪҶ�ӽڵ�
				cout << p[x];
				j = 2 * n - 2;
				count = 0;
			}
		}
		else if (code2[i] == 0) {
			count++;
			x = HT[j].lchild;
			j = x;
			if (HT[x].rchild == 0) {
				cout << p[x];
				j = 2 * n - 2;
				count = 0;
			}
		}
		i++;
	}
}
void print(int q[][10], char p[], int n) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		cout << p[i] << ":";
		while (q[i][j] != -1) {
			cout << q[i][j];
			j++;
		}
		j = 0;
		cout << endl;
	}
}
void print2(int q[][10], char code[]) {
	int j = 0;
	int len = strlen(code);
	for (int i = 0; i < len; i++) {
		while (q[i][j] != -1) {
			cout << q[i][j];
			j++;
		}
		j = 0;
	}
}