/*
在v dis chosen为节点的图上求最短路
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
const int inf=0x3f3f3f3f;
struct Edge {
    int to, w, next;
    bool exist;
    Edge() {}
}edge[maxn*3];
struct Node {
    int u, dis, used;
    Node () {}
    Node (int u, int dis, int used):u(u), dis(dis), used(used) {}
    bool operator<(const Node &rhs) const {
        return dis>rhs.dis;
    }
};
int head[maxn], dis[maxn][11], cnt;
int n, m, k, d;
priority_queue<Node> que;

void init() {
    memset(head, 0xff, sizeof(head));
    cnt=0;
}
void addedge(int u, int v, int w, bool exist) {
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].exist=exist;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

int solve() {
    memset(dis, 0x3f, sizeof(dis));
    while (!que.empty()) que.pop();
    Node cur=Node(0, 0, 0);
    dis[0][0]=0;
    que.push(cur);

    while (!que.empty()) {
        cur=que.top();
        que.pop();
        if (cur.u==n-1) return cur.dis;
        int p=head[cur.u];
        while (p>=0) {
            int v=edge[p].to, len=edge[p].w;
            bool exist=edge[p].exist;
            p=edge[p].next;
            if (exist) {
                if (dis[v][cur.used]>dis[cur.u][cur.used]+len) {
                    dis[v][cur.used]=dis[cur.u][cur.used]+len;
                    que.push(Node(v, dis[v][cur.used], cur.used));
                }
            }else if (!exist&&cur.used<d) {
                if (dis[v][cur.used+1]>dis[cur.u][cur.used]+len) {
                    dis[v][cur.used+1]=dis[cur.u][cur.used]+len;
                    que.push(Node(v, dis[v][cur.used+1], cur.used+1));
                }
            }
        }
    }
    return inf;
}

int main() {
    int T, icase=1, ans;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for (int i=0;i<m;++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w, true);
        }
        for (int i=0;i<k;++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w, false);
        }
        ans=solve();
        printf("Case %d: ", icase++);
        if (ans==inf) puts("Impossible");
        else printf("%d\n", ans);
    }
    return 0;
}
