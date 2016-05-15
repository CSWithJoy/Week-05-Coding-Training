//模拟水题
#include<bits/stdc++.h>
using namespace std;

int vis[3700];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,num,len,cnt=0;
		memset(vis,0,sizeof(vis));
		cin>>len;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>num;
			int k=num;
			while(k<=len)
			{
				if(k%7==0||(k+1)%7==0)
				{
					k+=num;
					continue;
				}

				if(vis[k]==0)
				{
					vis[k]=1;
					cnt++;
				}
				k+=num;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
