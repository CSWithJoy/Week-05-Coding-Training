#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=200000;

using namespace std;

int t,n,u,v,ans,l[maxn+10],r[maxn+10],U[maxn+10],V[maxn+10];

void dfs(int cur,int left,int right){
    if(cur==n){
        ans=max(ans,max(left,right));
        //printf("%d\n",ans);
        return ;
    }
    int u=U[cur],v=V[cur];
    if(l[u]&&!r[u]&&!r[v]&&!l[v]) {
        r[v]=1;
        dfs(cur+1,left,right+1);
        r[v]=0;
    } else if(!l[u]&&!r[u]&&r[v]&&!l[v]){
        l[u]=1;
        dfs(cur+1,left+1,right);
        l[u]=0;
    } else if(l[v]&&!r[v]&&!r[u]&&!l[u]) {
         r[u]=1;
         dfs(cur+1,left,right+1);
         r[u]=0;
    } else if(!l[v]&&!r[v]&&r[u]&&!l[u]){
        l[v]=1;
        dfs(cur+1,left+1,right);
        l[v]=0;
    }
    else if((l[u]&&r[v]&&!l[v]&&!r[u])||(l[v]&&r[u]&&!l[u]&&!r[v])) dfs(cur+1,left,right);
      else if(!l[u]&&!r[u]&&!l[v]&&!r[v]) {
              l[v]=1,r[u]=1;
             dfs(cur+1,left+1,right+1);
             l[v]=0,r[u]=0;
             l[u]=1,r[v]=1;
             dfs(cur+1,left+1,right+1);
             l[u]=0,r[v]=0;

      }
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(l,0,sizeof(l)),memset(r,0,sizeof(r)),memset(U,0,sizeof(U)),memset(V,0,sizeof(V));
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d%d",&U[i],&V[i]);
        ans=-inf;
        l[U[0]]=1,r[V[0]]=1;
        dfs(1,1,1);
        printf("Case %d: %d\n",h,ans);
    }
    return 0;
}
