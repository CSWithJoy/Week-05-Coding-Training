//stack
#include<stdio.h>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
#define MAX 1000001
int a[MAX],num;
int solve()
{
	stack<int> s,sum;
	for(int i=0;i<num;i++)
	{
		if(a[i]<0)
		{
			if(s.size()>=1)
			{
				if(sum.top()<=abs(a[i]))
				{
					return 0;
				}
				int temp=sum.top();
				temp-=abs(a[i]);
				sum.pop();
				sum.push(temp);
			}
			s.push(a[i]);
			sum.push(abs(a[i]));
		}
		else
		{
			if(s.empty()) return 0;
			if(abs(s.top())!=a[i]) return 0;
			s.pop();
			sum.pop();
		}
	}
}
int main()
{
	num=0;
	int m;
	char ch;
	while(scanf("%d%c",&m,&ch)!=EOF)
	{
		a[num++]=m;
		if(ch=='\n')
		{
			if(num%2) printf(":-( Try again.\n");
			else
			{
				int flag=solve();
				if(flag)
					printf(":-) Matrioshka!\n");
				else
					printf(":-( Try again.\n");

			}
			num=0;
		}
	}
	return 0;
}
