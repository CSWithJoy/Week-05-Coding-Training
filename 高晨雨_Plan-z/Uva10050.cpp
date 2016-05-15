//Water
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int day[101];
int flag[3651];
int main()
{
	int T;
	int days,n,sum;
	int x;
	cin>>T;
	while(T--)
	{
		cin>>days>>n;
		sum=0;
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;i++)
		{
			cin>>day[i];
			if(day[i]%7!=6&&day[i]%7!=0)
				flag[day[i]]=1;
		}
		for(int i=0;i<n;i++)
			for(int j=1;j<=days;j++)
			{
				if(j%day[i]==0&&j%7!=6&&j%7!=0)
					flag[j]=1;
			}
		for(int i=1;i<=days;i++) sum+=flag[i];
		cout<<sum<<endl;
	}
	return 0;
}
