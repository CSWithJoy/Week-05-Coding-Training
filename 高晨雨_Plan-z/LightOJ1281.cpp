//有限制的最短路,边为有向边
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
#define INF  0x3fffffff
#define MAXN  30005
int t,n,m,k,d,u,v,w;
int inde = 0;
int head[10005]; //标记结点
int distant[10005][15]; //各个结点,第二维是用多少新路

struct edge{
    int v,w,x,next;
}edges[30005];//路线

void add_edge(int u1,int v1,int w1,int x1){
    edges[inde].v = v1;
    edges[inde].w = w1;
    edges[inde].x = x1;
    edges[inde].next = head[u1];
    head[u1] = inde++;
}

struct point{
    int sum,u;
};

void spfa()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= d; j++)
            distant[i][j] = INF;
    distant[0][0] = 0;
    point p;
    queue<point> Q;
    p.u = 0;
    p.sum = 0;
    Q.push(p);
    while(!Q.empty()){
        p = Q.front();Q.pop();
        for(int i = head[p.u];i!=-1;i=edges[i].next){
            int costRode = edges[i].w;
            int sumNewRode = p.sum+edges[i].x;
            int nextStartU = edges[i].v;
            point pp;
            pp.sum = sumNewRode;pp.u = nextStartU;
            if(costRode + distant[p.u][p.sum] < distant[nextStartU][sumNewRode]&&sumNewRode<=d){
                distant[nextStartU][sumNewRode] = costRode + distant[p.u][p.sum];
                Q.push(pp);
            }
        }
    }
}

int main(){
    cin>>t;
    for(int i = 1; i <= t;i++){
        cin>>n>>m>>k>>d;
        inde = 0;
        memset(head,-1,sizeof(head));
        while(m--)cin>>u>>v>>w,add_edge(u,v,w,0);
        while(k--)cin>>u>>v>>w,add_edge(u,v,w,1);
        spfa();
        int minn = INF;
        printf("Case %d: ",i);
        for(int j = 0; j <= d; j++){
            if(distant[n-1][j] < minn) minn = distant[n-1][j];
        }
        minn == INF?printf("Impossible\n"):printf("%d\n",minn);
    }
    return 0;
}
