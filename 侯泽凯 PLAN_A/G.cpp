//用数组建树会RE。。。
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct node{
    char data;
    node *lnode, *rnode;
};

int length;
char s[10010];

node* queue[10010];

void input(char ch,node *&L)
{
    L = (node*)malloc(sizeof(node));
    L->data = ch;

    if(ch>='a'&&ch<='z')
    {
        L->lnode = L->rnode = NULL;
        return;
    }

    else
    {
        input(s[--length],L->lnode);
        input(s[--length],L->rnode);
    }
}

void bfs(node *l)
{
    int front = 0;
    int rear = 1;
    int count = 0;

    queue[front] = l;

    while(front<rear)
    {
        if(queue[front]->rnode)
			queue[rear++] = queue[front]->rnode;

        if(queue[front]->lnode)
			queue[rear++] = queue[front]->lnode;

        s[count++] = queue[front++]->data;
    }

    for(int i=count-1; i>=0; i--)
    cout<<s[i];

    cout<<endl;
}

int main ()
{
    int t;
    node *l;

    cin>>t;
    getchar();

    while(t--)
    {
        gets(s);

        while(s[length])
			length++;

		input(s[--length],l);

        bfs(l);
    }
    return 0;
}
