/*
水题
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

typedef pair<int,int> P;

int t,w,h,sx,sy,cnt,flag[maxn+10][maxn+10];

char a[maxn+10][maxn+10];

int bfs(){
   queue<P> que;
   que.push(P(sx,sy));
   while(!que.empty()){
        P p=que.front();que.pop();
        for(int i=0;i<4;i++){
                int nx=p.first+dir[i][0],ny=p.second+dir[i][1];
                if(nx>=1&&nx<=h&&ny>=1&&ny<=w&&!flag[nx][ny]&&a[nx][ny]=='.') {
                        cnt++,flag[nx][ny]=1,que.push(P(nx,ny));
                }
        }
   }
   return cnt+1;
}

int main()
{
    scanf("%d",&t);
    for(int icase=1;icase<=t;icase++){
        cnt=0,memset(flag,0,sizeof(flag));
        scanf("%d%d",&w,&h);
        for(int i=1;i<=h;i++)
                for(int j=1;j<=w;j++){
                        scanf(" %c",&a[i][j]);
                        if(a[i][j]=='@') sx=i,sy=j,flag[sx][sy]=1;
                }
       printf("Case %d: %d\n",icase,bfs());
    }
    return 0;
}
