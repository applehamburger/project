#include"strlocate.h"

int main() {
	HString S;
	HString T;
	char s[MAXSIZE];
	char t[MAXSIZE];
	cout << "请输入主串S：" << endl;
	cin >> s;
	StrAssign(S, s);
	cout << "请输入子串T：" << endl;
	cin >> t;
	StrAssign(T, t);

	cout << "主串S为：" << endl;
	TraverseString(S);
	cout << "子串T为：" << endl;
	TraverseString(T);

	int pos;
	cout << "请输入从S的第几位开始查找: ";
	cin >> pos;
	if (index(S, T, pos) == 0)
		cout << "未找到该子串" << endl;
	else cout << "起始位置：" << index(S, T, pos)<< "  "<<"终止位置"<< index(S, T, pos)+T.length<<endl;

	return 0;
}