#pragma once
#include<iostream>
#define NULL 0
#define OK 1
using namespace std;

typedef struct LNode {
	int data;
	LNode* next;
}LNode, * LinkList;


void create(LinkList& L);

void print(LinkList L);

void reverseprint(LinkList L);

int maxvalue(LinkList L);
