//模拟队列嵌套
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int z=1;
	int t;
	while(cin>>t,t)
	{
		cout<<"Scenario #"<<z++<<endl;

		map<int,int>team;

		for(int i=0;i<t;i++)
		{
			int teamsize;
			cin>>teamsize;
			for(int j=0;j<teamsize;j++)
			{
				int teamnum;
				cin>>teamnum;
				team[teamnum]=i;
			}
		}

		string op;
		queue<int>big;
		queue<int>every[1050];

		while(cin>>op)
		{
			if(op=="STOP")break;
			if(op=="ENQUEUE")
			{
				int num;
				cin>>num;
				int f=team[num];

				if(every[f].empty())
				{
					big.push(f);
				}
				every[f].push(num);
			}
			else if(op=="DEQUEUE")
			{
				int id=big.front();
				cout<<every[id].front()<<endl;
				every[id].pop();
				if(every[id].empty())
				{
					big.pop();
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
