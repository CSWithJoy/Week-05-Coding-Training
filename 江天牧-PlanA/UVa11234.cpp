//二叉树建树后，宽搜
#include <iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
const int maxn = 10005;
const int INF =0x3f3f3f3f;

using namespace std;
char line[maxn];
int next_l[maxn];
int next_r[maxn];
char value[maxn];
int cnt;//biao hao
int main()
{
    int T;
    cin >> T;
    //int TIME = 1;
    while(T--)
    {
        memset(next_l,-1,sizeof(next_l));
        memset(next_r,-1,sizeof(next_r));
        cnt = -1;
        scanf("%s",line);
        int le_line = strlen(line);
        stack<int> st__;
        for(int i = 0;i < le_line;i ++)//build
        {
            if(line[i]<='z' && line[i]>='a')
            {
                value[++cnt] = line[i];
                st__.push(cnt);
            }
            else
            {
                value[++cnt] = line[i];
                next_r[cnt] = st__.top();
                st__.pop();
                next_l[cnt] = st__.top();
                st__.pop();
                st__.push(cnt);
            }
        }//build
        queue<int> qu__;
        qu__.push(cnt);
        while(!qu__.empty())//find
        {
            int now = qu__.front();
            qu__.pop();
            if(next_l[now]!=-1)
            {
                qu__.push(next_l[now]);
                st__.push(next_l[now]);
            }
            if(next_r[now]!=-1)
            {
                qu__.push(next_r[now]);
                st__.push(next_r[now]);
            }
        }//find

        while(!st__.empty())
        {
            printf("%c",value[st__.top()]);
            st__.pop();
        }
        cout<<endl;
    }
    return 0;
}
