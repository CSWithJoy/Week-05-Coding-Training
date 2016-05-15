//怎么判断是关键
#include<bits/stdc++.h>
using namespace std;

int toy[10000010];
int t[10000010];
int cnt;

int jug()
{
	stack<int> s,sum;

    for(int i = 0; i < cnt; i++)
    {
        if(toy[i]<0)
        {
            if(s.size()>=1)
            {
                if(sum.top()<=abs(toy[i]))
                    return 0;

                int tmp = sum.top();
                tmp-=abs(toy[i]);
                sum.pop();
                sum.push(tmp);
            }
            s.push(toy[i]);
            sum.push(abs(toy[i]));
        }
        else
        {
            if(s.empty())
                return 0;
            if(abs(s.top())!=toy[i])
                return 0;

            s.pop();
            sum.pop();
        }
    }
    return 1;
}

int main()
{
	int num;
	char b;
	cnt=0;
	while(scanf("%d%c",&num,&b)!=EOF)
	{
		toy[cnt++]=num;
		if(b=='\n')
		{
			if(cnt%2==1)
			{
				printf(":-( Try again.\n");
			}
			else
			{
				if(jug()==1)
				{
					printf(":-) Matrioshka!\n");
				}
				else
				{
					printf(":-( Try again.\n");
				}
			}
			cnt=0;
		}
	}
	return 0;
}
