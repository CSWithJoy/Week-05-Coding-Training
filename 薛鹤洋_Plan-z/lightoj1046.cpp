/*
bfs 10*10的棋盘,可以每个棋子都跳一次。然后记录数据，一次可以跳很多次的棋子，每次跳一步都除以它可以跳的步数即可
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

typedef pair<int,int> P;

P start;

queue<P> q;

int t,m,n,ans,count_num;

char a[maxn+10][maxn+10];

int flag[maxn+10][maxn+10],cnt[maxn+1][maxn+1],fla[maxn+10][maxn+10],d[maxn+10][maxn+10];

int rider[maxn+10][maxn+10];

int dir[8][2]={{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};

void init(){
  ans=inf;
  count_num=0;
  memset(a,0,sizeof(a));
  memset(cnt,0,sizeof(cnt));
  memset(flag,0,sizeof(flag));
}

void bfs(){
  //printf("done\n");
  memset(d,0,sizeof(d));
  memset(fla,0,sizeof(fla));
  queue<P> que;
  que.push(start);
  flag[start.first][start.second]+=1;
  fla[start.first][start.second]=1;
  while(!que.empty()){
        P p=que.front();que.pop();
        for(int i=0;i<8;i++){
                int nx=p.first+dir[i][0],ny=p.second+dir[i][1];
                if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&!fla[nx][ny]){
                     fla[nx][ny]=1;
                     flag[nx][ny]+=1;
                     d[nx][ny]=d[p.first][p.second]+1;
                     que.push(P(nx,ny));
                }
        }
  }
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++){
        d[i][j]=(int)ceil(1.0*d[i][j]/rider[start.first][start.second]);
        cnt[i][j]+=d[i][j];
  }
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        init();
        scanf("%d%d",&m,&n);
        for(int i=1;i<=m;i++)
                for(int j=1;j<=n;j++) {
                scanf(" %c",&a[i][j]);
                if(a[i][j]!='.'){
                   rider[i][j]=a[i][j]-'0';
                   q.push(P(i,j));
                   count_num++;
                }
        }
        //printf("%d\n",q.size());
        for(int i=0;i<count_num;i++){
                start=q.front();
                q.pop();
                bfs();
        }
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++) {
                //printf("%d\n",flag[i][j]);
                if(flag[i][j]==count_num) {
                        ans=min(ans,cnt[i][j]);
                }
            }
        if(ans==inf) printf("Case %d: -1\n",h);
        else printf("Case %d: %d\n",h,ans);
    }
    return 0;
}
