//dijiecstra 裸题,终于可以基本默写了，虽然还是有参考
#include<iostream>
using namespace std;

#define inf 1<<29

int  mp[1005][1005];
int dis[1005];
bool vis[1005];
int n,t;

void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				mp[i][j]=0;
			else
				mp[i][j]=mp[j][i]=inf;
		}
	}
}

void dij()
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		dis[i]=mp[1][i];
	}

	for(int i=1;i<n;i++)
	{
		int minx=inf;
		int k=0;

		for(int j=1;j<=n;j++)
		{
			if(vis[j]==0&&dis[j]<minx)
			{
				minx=dis[j];
				k=j;
			}
		}
		if(k==0)return;
		vis[k]=1;

		for(int j=1;j<=n;j++)
		{
			if(vis[j]==0&&dis[j]>dis[k]+mp[k][j])
			{
				dis[j]=dis[k]+mp[k][j];
			}
		}
	}
}

int main()
{
	cin>>t>>n;
	init();

	for(int i=0;i<t;i++)
	{
		int s,e,v;
		cin>>s>>e>>v;
		if(mp[s][e]>v)
		{
			mp[s][e]=mp[e][s]=v;
		}
	}

	dij();
	cout<<dis[n]<<endl;
	return 0;
}
