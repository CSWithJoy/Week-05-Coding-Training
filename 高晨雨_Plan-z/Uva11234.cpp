//已知二叉树后续遍历求层次遍历，大写当做操作符，小写当做数字
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
#define MAX 10010
int length;
char s[MAX];

struct node
{
	char data;
	node*lchild,*rchild;
};
node* queue[MAX];
void input (char ch,node *&L)
{
	L=(node*)malloc(sizeof(node));
	L->data=ch;
	if(ch>='a'&&ch<='z')
	{
		L->lchild=L->rchild=NULL;
		return;
	}
	else{
		input(s[--length],L->lchild);
		input(s[--length],L->rchild);
	}
}
void BFS(node*l)
{
	int front=0,rear=1,count=0;
	queue[front]=l;
	while(front<rear)
	{
		if(queue[front]->rchild) queue[rear++]=queue[front]->rchild;
		if(queue[front]->lchild) queue[rear++]=queue[front]->lchild;
		s[count++]=queue[front++]->data;
	}
	for(int i=count-1;i>=0;i--)
	{
		cout<<s[i];
	}
	cout<<endl;
}
int main()
{
	int T;
	node*l;
	cin>>T;
	getchar();
	while(T--)
	{
		gets(s);
		for(length=0;s[length];length++);
		input(s[--length],l);
		BFS(l);
	}
	return 0;
}
