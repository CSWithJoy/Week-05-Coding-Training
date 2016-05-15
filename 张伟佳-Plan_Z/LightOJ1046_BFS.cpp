/*
最短路。发现最终所有骑士要到达的格子一定是给定的有骑士的某个格子。
注意最短的步数是步数stp/k向上取整。
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
const int inf=0x3f3f3f3f;
char mp[11][11];
int dx[8]={-1, 1, 2, 2, 1, -1, -2, -2}, dy[8]={-2, -2, -1, 1, 2, 2, 1, -1};
bool vis[11][11];
struct Node {
    int x, y, stp;
    Node () {}
    Node (int x, int y, int stp):x(x), y(y), stp(stp) {}
};
Node pts[maxn];
int tot, dis[11][11], m, n;

void bfs(int x, int y) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    Node cur=Node(x, y, 0);
    queue<Node> que;
    que.push(cur);
    vis[y][x]=true;
    dis[y][x]=0;

    while (!que.empty()) {
        cur=que.front();
        que.pop();
        for (int i=0;i<8;++i) {
            int nx=cur.x+dx[i], ny=cur.y+dy[i];
            if (nx<0||ny<0||nx>=n||ny>=m||vis[ny][nx]) continue;
            //printf("%d %d\n", nx, ny);
            vis[ny][nx]=true;
            dis[ny][nx]=cur.stp+1;
            que.push(Node(nx, ny, cur.stp+1));
        }
    }
}

int main() {
    int T, icase=1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d\n", &m, &n);
        for (int i=0;i<m;++i) gets(mp[i]);
        printf("Case %d: ", icase++);

        tot=0;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (mp[i][j]!='.') pts[tot++]=Node(j, i, 0);
            }
        }
        
        int ans=inf;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                int tmp=0;
                bfs(j, i);
                for (int k=0;k<tot;++k) {
                    int x=pts[k].x, y=pts[k].y;
                    if (dis[y][x]<inf) {
                        tmp+=(dis[y][x]+mp[y][x]-'0'-1)/(int)(mp[y][x]-'0');
                    }else {
                        tmp=inf;
                        break;
                    }
                }
                ans=min(ans, tmp);
            }
        }
        if (ans==inf) ans=-1;
        printf("%d\n", ans);
    }
    return 0;
}
