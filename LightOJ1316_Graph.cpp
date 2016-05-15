/*
将经过的商店的信息压缩到integer当中，求最短路。
节点数量比较大，商店数量少，先用最短路单独计算从起点和各商店开始到
图上各点的最短路，这样预处理过后简化最短路复杂度。
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
const int inf=0x3f3f3f3f;
struct Edge {
    int to, w, next;
    Edge() {};
    Edge(int to, int w, int next):to(to), w(w), next(next) {}
}edge[20005];
struct Node {
    int state, u;
    Node() {}
    Node(int state, int u):state(state), u(u) {}
};
int cnt, head[maxn];
int n, m, s, dis[maxn][maxn];
int shop[16], dp[65536][16];
bool vis[maxn];

void init() {
    cnt=0;
    memset(head, 0xff, sizeof(head));
}
void addedge(int u, int v, int w) {
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void spfa(int st, int *dis) {
    memset(vis, false, sizeof(vis));
    queue<int> que;
    que.push(st);
    dis[st]=0;
    vis[st]=true;

    while (!que.empty()) {
        int u=que.front();
        que.pop();
        vis[u]=false;
        int p=head[u];
        while (p>=0) {
            int v=edge[p].to, len=edge[p].w;
            p=edge[p].next;
            if (dis[v]>dis[u]+len) {
                dis[v]=dis[u]+len;
                if (!vis[v]) {
                    que.push(v);
                    vis[v]=true;
                }
            }
        }
    }
}

int bitCnt(int x) {
    int ret=0;
    while (x) {
        ret+=x&1;
        x>>=1;
    }
    return ret;
}

void solve() {
    memset(dis, 0x3f, sizeof(dis));
    spfa(0, dis[0]);
    for (int i=0;i<s;++i) {
        spfa(shop[i], dis[shop[i]]);
    }
    if (dis[0][n-1]==inf) {
        puts("Impossible");
        return;
    }

    queue<Node> que;
    memset(dp, 0x3f, sizeof(dp));
    for (int i=0;i<s;++i) {
        dp[1<<i][i]=dis[0][shop[i]];
        que.push(Node(1<<i, i));
    }
    while (!que.empty()) {
        Node cur=que.front();
        que.pop();
        int u=cur.u, stt=cur.state;
        if (dp[stt][u]>=inf) continue;
        for (int i=0;i<s;++i) {
            if ((stt&(1<<i))==0&&dis[shop[u]][shop[i]]<inf) {
                if (dp[stt][u]+dis[shop[u]][shop[i]]<dp[stt|(1<<i)][i]) {
                    dp[stt|(1<<i)][i]=dp[stt][u]+dis[shop[u]][shop[i]];
                    que.push(Node(stt|(1<<i), i));
                }
            }
        }
    }

    int ans=-inf, mindis=inf;
    for (int i=0;i<s;++i) {
        if (dis[shop[i]][n-1]>=inf) continue;
        for (int j=0;j<(1<<s);++j) {
            int num=bitCnt(j);
            if (dp[j][i]>=inf) continue;
            if (num>ans) {
                ans=num;
                mindis=dis[shop[i]][n-1]+dp[j][i];
            }else if (num==ans) {
                if (mindis>dis[shop[i]][n-1]+dp[j][i]) {
                    mindis=dis[shop[i]][n-1]+dp[j][i];
                }
            }
        }
    }
    if (ans<0) puts("Impossible");
    else printf("%d %d\n", ans, mindis);
}

int main() {
    int T, icase=1;
    scanf("%d", &T);
    while (T--) {
        init();
        memset(shop, 0xff, sizeof(shop));
        scanf("%d%d%d", &n, &m, &s);
        for (int i=0;i<s;++i) {
            scanf("%d", shop+i);
        }
        for (int i=0;i<m;++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            //addedge(v, u, w);
        }
        printf("Case %d: ", icase++);
        solve();
    }
    return 0;
}
