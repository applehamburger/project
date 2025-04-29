#include"strlocate.h"



Status StrAssign(HString& S, const char* chars) {
    int len = 0;
    const char* p = chars;

    // 计算字符串的长度
    while (*p != '\0') {
        len++;
        p++;
    }

    // 分配内存
    S.ch = new char[len];

    if (S.ch == NULL) {
        return ERROR;
    }

    // 复制字符串
    for (int i = 0; i < len; i++) {
        S.ch[i] = chars[i];
    }

    // 设置字符串长度
    S.length = len;

    return OK;
}

Status TraverseString(const HString& S) {
    if (S.ch == NULL) {
        return ERROR; // 空串，遍历失败
    }

    for (int i = 0; i < S.length; i++) {
        cout << S.ch[i] ;
    }
    cout << endl;

    return OK;
}

int index(HString S, HString T, int pos) {
	int i = pos-1; int j = 0;
	while (i < S.length && j < T.length) {
		if(S.ch[i]==T.ch[j])
		{
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= T.length)
		return(i - T.length+1);
	else return 0;
}