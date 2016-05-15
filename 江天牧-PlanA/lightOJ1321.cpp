//求最小期望时间，只要沿最大通过概率的路径走就可以啦，最大的概率按贪心的原则就可以找到
#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int MAXN = 1005;
struct BIAN
{
    int u,v,next;
    double p;
    BIAN(){}
    BIAN(int a,int b,int c,int d):u(a),v(b),p((double)c/100),next(d){}
}bian[MAXN*MAXN];
int N;
int head[MAXN];
int vis[MAXN];
int cnt;
void init()
{
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
}
void LINK(int u, int v,int p)
{
    bian[cnt] = BIAN(u,v,p,head[u]);
    head[u] = cnt++;
}
double probabi[MAXN];

double DIJISTRA()
{
    memset(probabi,0,sizeof(probabi));
    probabi[0] = 1.0;
    /*vis[0] = 1;
    for(int i = head[0];i!=-1;i = bian[i].next)
    {
        int v = bian[i].v;
        probabi[v] = max(bian[i].p,probabi[v]);
    }*/
    while(true)
    {
        double max_p = 0.0;
        int u = -1;
        for(int i = 0;i < N;i++)
        {
            if(!vis[i] && probabi[i] > max_p)
            {
                u = i;
                max_p = probabi[i];
            }
        }
        //cout <<u<<endl;
        //cout<<max_p<<endl;
        if( u == -1)
            break;
        vis[u] = 1;
        for(int i = head[u];i!=-1;i = bian[i].next)
        {
            int v = bian[i].v;
            probabi[v] = max(probabi[u]*bian[i].p,probabi[v]);
        }
    }
    return probabi[N-1];
}
int main()
{
    int T;
    cin >> T;
    int TIME = 0;
    while(T--)
    {
        init();
        int M,S,K;
        scanf("%d%d%d%d",&N,&M,&S,&K);
        for(int i = 0; i< M;i++)
        {
            int temp_u,temp_v,temp_p;
            scanf("%d%d%d",&temp_u,&temp_v,&temp_p);
            LINK(temp_u,temp_v,temp_p);
            LINK(temp_v,temp_u,temp_p);
        }

        //cout <<PR<<endl;
        double tp = 1 / DIJISTRA() * (2 * (double)S * K);
        printf("Case %d: %.7lf\n",++TIME,tp);
    }
    return 0;
}
