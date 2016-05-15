/*
最短路问题的变型,变为求n个点中,从一个点到另一个点的最小花费,需要保存的参数有,当前的城市,剩余的油量
和当前的花费，一个重要的问题是，在i点,是否加油,加多少油。刚开始想的是,如果这个点能够更新到其他点
就不需要加油,不能才需要,后来看了大神的代码发现是错的,因为这个点已经出队了,以后再想加入在这个点加油的状态
就不行了, 所以每个点都至少要加1单位油。如果一单位不够使该点更新,就一直加到刚好可以更新,这样也是最合理的。
还有一种方法是每次都让剩余的油,到加满的油入队。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int c,t,n,m,q,s,x,y,z,des,ans;

struct edge {int to,cost;};

typedef pair<int,int> P;

typedef pair<P,int> DoubleP;

int V;

vector<edge> G[maxn+10];

int d[maxn+10][maxn+10],price[maxn+10];

int dijkstra(int s,int des){
  priority_queue<DoubleP,vector<DoubleP>,greater<DoubleP> > que;
  memset(d,inf,sizeof(d));
  d[s][0]=0;
   que.push(DoubleP(P(d[s][0],0),s));
   while(!que.empty()){
        DoubleP p=que.top();que.pop();
        int v=p.second,cost=p.first.first,left=p.first.second;
        if(d[v][left]<cost) continue;
        if(v==des) return d[v][left];
        for(size_t i=0;i<G[v].size();i++){
                edge e=G[v][i];
                if(e.cost<=left&&d[e.to][left-e.cost]>d[v][left]){
                        d[e.to][left-e.cost]=d[v][left];
                        que.push(DoubleP(P(d[e.to][left-e.cost],left-e.cost),e.to));
                }
        }
        if(left<c&&d[v][left+1]>d[v][left]+price[v]){
                d[v][left+1]=d[v][left]+price[v];
                que.push(DoubleP(P(d[v][left+1],left+1),v));
        }
   }
   return -1;
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        printf("Case %d:\n",h);
        scanf("%d%d",&n,&m);
        memset(price,0,sizeof(price)),memset(G,0,sizeof(G));
        for(int i=0;i<n;i++) scanf("%d",&price[i]);
        for(int i=0;i<m;i++){
                scanf("%d%d%d",&x,&y,&z);
                edge w;
                w.to=y,w.cost=z;
                G[x].push_back(w);
                w.to=x,w.cost=z;
                G[y].push_back(w);
        }
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
                scanf("%d%d%d",&c,&s,&des);
                ans=dijkstra(s,des);
                if(ans!=-1) printf("%d\n",ans);
                else printf("impossible\n");
        }
    }
    return 0;
}
