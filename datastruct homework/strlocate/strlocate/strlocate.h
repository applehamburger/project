#pragma once
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;
typedef string Elemtype;

typedef struct{
	char* ch;
	int length;
}HString;

Status StrAssign(HString& S, const char* chars);
Status TraverseString(const HString& S);
int index(HString S, HString T, int pos);