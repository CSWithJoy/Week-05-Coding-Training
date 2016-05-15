/*
最短路，就是数学期望需要稍微求一下（等比数列那一套）。
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
struct Edge {
    int to, w, next;
    Edge () {}
    Edge (int to, int w, int next):to(to), w(w), next(next) {}
}edge[20005];
int head[maxn], cnt;
int n, m, k, s;
double expct[maxn];
bool vis[maxn];

void init() {
    memset(head, 0xff, sizeof(head));
    cnt=0;
}
void addedge(int u, int v, int w) {
    edge[cnt]=Edge(v, w, head[u]);
    head[u]=cnt++;
}

void spfa() {
    memset(vis, false, sizeof(vis));
    for (int i=0;i<n;++i) expct[i]=0.0;
    queue<int> que;
    
    expct[0]=1.0;
    vis[0]=true;
    que.push(0);
    while (!que.empty()) {
        int u=que.front();
        que.pop();
        vis[u]=false;
        //printf("%d\n", u);

        int p=head[u];
        while (p>=0) {
            int v=edge[p].to;
            double prob=(double)edge[p].w/100.0;
            p=edge[p].next;
            if (expct[v]<expct[u]*prob) {
                expct[v]=expct[u]*prob;
                if (!vis[v]) {
                    vis[v]=true;
                    que.push(v);
                }
            }
        }
    }
}

int main() {
    int T, icase=1;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d%d%d%d", &n, &m, &k, &s);
        for (int i=0;i<m;++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        spfa();
        double p=expct[n-1];
        //printf("%lf\n", p);
        printf("Case %d: %lf\n", icase++, 2*k/p*s);
    }
    return 0;
}
