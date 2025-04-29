#include"Huffman.h"
int FindWeight(char code[], char p[], int w[]) {
	if (strlen(code) == 0)return 0;
	int num = 1;//记录code中不同的字符个数
	p[0] = code[0];
	w[0]++;
	for (int i = 1; i < strlen(code); i++) {
		for (int j = 0; j < num; j++) {
			if (code[i] == p[j]) {
				//code[i]已经出现过，则其权值加1，并退出内循环
				w[j]++;
				break;
			}
			if (j == num - 1) {
				//code[i]未出现过，则录入p中，其权值变为1
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
	//构造哈夫曼树HT
	if (n <= 1)return;
	int m = 2 * n - 1;
	int s1 = 0, s2 = 0;
	HT = new HTNode[m];
	for (int i = 0; i < m ; i++) {//将1~m号单元中的双亲、左孩子、右孩子的下标初始化为0
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 0; i < n; i++) {//输入前n个单元中叶子结点的权值
		HT[i].weight = w[i];
	}
	//初始化结束，开始创建哈夫曼树
	for (int i = n ; i < m; i++) {//通过n-1次的选择、删除、合并来创建哈夫曼树
		Select(HT, i - 1, s1, s2);//在HT[k](1<=k<=i-1)中选择两个其双亲域为0且权值最小的结点，并返回他们在HT中的序号s1和s2
		HT[s1].parent = i;//得到新结点i，从森林中删除s1、s2，将s1和s2的双亲域由0改为i
		HT[s2].parent = i;
		HT[i].lchild = s1;//s1和s2分别作为i的左右孩子
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;//i的权值为左右孩子权值之和
	}
}

void Select(HuffmanTree& HT, int k, int &s1, int &s2) {
	int min1, min2;
	int i = 0;//遍历数组，初始下标为1
	while (HT[i].parent != 0 && i < k)//找到还没构建树的结点
		i++;
	min1 = HT[i].weight;
	s1 = i;
	i++;
	while (HT[i].parent != 0 && i < k)
		i++;
	//对找到的两个结点比较大小，min1为小的，min2为大的
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
	//两个结点和后续的所有未构建成树的结点做比较
	for (int j = i + 1; j <= k; j++) {
		if (HT[i].parent != 0)//如果有父结点，直接跳过，进行下一个
			continue;
		if (HT[j].weight < min1) {//如果比最小的还小，将min2=min1,min1赋值新的结点的下标
			min2 = min1;
			min1 = HT[j].weight;
			s2 = s1;
			s1 = j;
		}
		else if (HT[j].weight >= min1 && HT[j].weight < min2) {//如果介于两者之间，min2赋值为新的结点的位置下标
			min2 = HT[j].weight;
			s2 = j;
		}
	}
}
void CreateHuffmanCode(HuffmanTree HT, int n, int q[][10], int road[]) {
	//从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
	//HC = new char* [n + 1];//分配存储n个字符编码的编码表空间   
	//char* cd = new char[n];//分配临时存放每个字符编码的动态数组空间
	//cd[n - 1] = '\0';//编码结束符
	int HC[10];//存储字符的编码
	memset(HC, 0, sizeof(HC));
	int f = 0;//f指向当前结点c的双亲结点
	int c = 0;//c指向当前结点
	int x = 0;//HC字符串数组的指针
	for (int i = 0; i < n; i++) {//逐个字符求哈夫曼编码
		//int start = n - 1;   //start开始时指向最后，即编码结束符位置
		c = i;  //f指向结点c的双亲结点
		f = HT[c].parent;
		while (f != 0) {   //从叶子结点开始向上回溯，直到根结点
			//--start;//回溯一次start向前指一个位置
			if (HT[f].lchild == c) {
				HC[x] = 0;//结点c是f的左孩子，则生成代码0
				road[i]++;
			}
			else {
				HC[x] = 1;   //结点c是f的右孩子，则生成代码1
				road[i]++;
			}
			x++;
			c = f;
			f = HT[f].parent;  //继续向上回溯,向上寻找双亲结点
		}  
		for (int j = 0; j < x; j++) {
			q[i][j] = HC[x - j - 1];
		}
		x = 0;
		//求出第i个字符的编码
		//HC[i] = new char[n - start];    //为第i个字符编码分配空间
		//strcpy(HC[i], &cd[start]);   //将求得的编码从临时空间cd复制到HC的当前行中
	}
	//delete[]cd;   //释放临时空间 
	cout << "编码成功！" << endl;
}
void HuffmanDecode(int code2[], HuffmanTree& HT, char p[], int n) {
	int i = 0;
	int j = 2 * n - 2;   //根结点下标
	int x = 0;
	int count = 0;
	while (code2[i] == 1 || code2[i] == 0) {
		if (code2[i] == 1) {
			count++;
			x = HT[j].rchild;
			j = x;//更新根节点
			if (HT[x].rchild == 0) {//当前结点没有右孩子，说明位为叶子节点
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