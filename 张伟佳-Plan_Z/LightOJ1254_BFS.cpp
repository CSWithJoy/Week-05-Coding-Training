/*
在节点为v cost rest的图上求最短路。
其中v为节点编号，cost为花费，rest为剩余燃料
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
const int inf=0x3f3f3f3f;
int head[maxn], cnt=0, price[maxn];
struct Edge{
    int to, next, w;
    Edge () {}
};
struct Node {
    int c, r, v;
    Node () {}
    Node (int cost, int res, int vec):c(cost), r(res), v(vec) {}
    bool operator<(const Node & rhs) const {
        return c>rhs.c;
    }
};
Edge edge[2010];
int dis[maxn][maxn];
bool vis[maxn];
priority_queue<Node> que;

void init() {
    cnt=0;
    memset(head, 0xff, sizeof(head));
}
void addEdge(int u, int v, int w) {
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

int solve(int c, int s, int t) {
    while (!que.empty()) que.pop();
    memset(dis, 0x3f, sizeof(dis));
    Node cur;
    // init
    dis[s][0]=0;
    cur=Node(0, 0, s);
    que.push(cur);
    //
    while (!que.empty()) {
        cur=que.top();
        que.pop();
        if (cur.c>dis[cur.v][cur.r]) continue;
        if (cur.v==t) return dis[cur.v][cur.r];
        int p=head[cur.v];
        while (p>=0) {
            int to=edge[p].to, len=edge[p].w;
            p=edge[p].next;
            if (len>c) continue;
            if (cur.r>=len&&dis[to][cur.r-len]>dis[cur.v][cur.r]) {
                dis[to][cur.r-len]=dis[cur.v][cur.r];
                que.push(Node(dis[to][cur.r-len], cur.r-len, to));
            }
        }
        if (cur.r<c) {
            dis[cur.v][cur.r+1]=dis[cur.v][cur.r]+price[cur.v];
            que.push(Node(dis[cur.v][cur.r+1], cur.r+1, cur.v));
        }
    }
    return inf;
}

int main() {
    int T, icase=1;
    scanf("%d", &T);
    int n, m, q;
    while (T--) {
        init();
        scanf("%d%d", &n, &m);
        for (int i=0;i<n;++i) scanf("%d", price+i);
        for (int i=0;i<m;++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        scanf("%d", &q);
        printf("Case %d:\n", icase++);
        while (q--) {
            int c, s, t, ans;
            scanf("%d%d%d", &c, &s, &t);
            ans=solve(c, s, t);
            if (ans==inf) printf("impossible\n");
            else printf("%d\n", ans);
        }
    }
    return 0;
}
