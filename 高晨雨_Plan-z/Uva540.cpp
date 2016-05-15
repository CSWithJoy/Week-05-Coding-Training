//队列里的队列嵌套
#include<stdio.h>
#include<iostream>
#include<map>
#include<queue>
using namespace std;
#define MAX 1010
int main()
{
	int T,kase=0;
	while(scanf("%d",&T)!=EOF)
	{
		if(T==0) break;
		printf("Scenario #%d\n",++kase);
		map<int,int> team;//利用map存储小团体的队伍编号以及人员的对应关系
		for(int i=0;i<T;i++)
		{
			int n,x;
			cin>>n;
			while(n--)
			{
				cin>>x;
				team[x]=i;
			}
		}
		queue<int> q,qq[MAX];//q为整个队伍的团体队列，qq是小团体的内部队列
		for(;;)
		{
			int x;
			char str[10];
			scanf("%s",str);
			if(str[0]=='S') break;
			else if(str[0]=='D')
			{
				int t=q.front();
				printf("%d\n",qq[t].front());
				qq[t].pop();
				if(qq[t].empty()) q.pop();
			}
			else if(str[0]=='E')
			{
				cin>>x;
				int t=team[x];
				if(qq[t].empty()) q.push(t);
				qq[t].push(x);
			}
		}
		printf("\n");
	}
	return 0;
}
