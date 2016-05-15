//团队队列模拟建一个总队列来存团队顺序，在建些小队列来模拟团体内部情况
#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
const int maxall = 1000005;
const int maxt = 1005;
using namespace std;
int wh_team[maxall];
bool is_team_inque[maxt];


int main()
{
    int TIME = 0;
    int N;
    while(~scanf("%d",&N)&&N)
    {
        queue<int> qu__[maxt];
        queue<int> qu_team;
        memset(is_team_inque,0,sizeof(is_team_inque));
        while(N--)//du ru
        {
            int n;
            scanf("%d",&n);
            while(n--)
            {
                int now;
                scanf("%d",&now);
                wh_team[now] = N;
            }
        }//du ru
        printf("Scenario #%d\n",++TIME);
        char command[10];
        while(scanf("%s",command) && command[0] != 'S')
        {
            if(command[0] == 'E')//E
            {
                int now;
                scanf("%d",&now);
                int team = wh_team[now];
                qu__[team].push(now);
                if(!is_team_inque[team])
                {
                    qu_team.push(team);
                    is_team_inque[team] = 1;
                }
            }//E
            else//D
            {
                int team = qu_team.front();
                printf("%d\n",qu__[team].front());
                qu__[team].pop();
                if(qu__[team].empty())
                {
                    qu_team.pop();
                    is_team_inque[team] = 0;
                }
            }//D
        }//sc
        printf("\n");
    }
    return 0;
}
