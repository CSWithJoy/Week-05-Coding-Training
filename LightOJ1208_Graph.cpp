/* 
极角排序，让边顺时针存入，将边转化成节点（转化的时候也只允许逆时针缠绕），在新图上用floyd求最小环。
*/

#include <bits/stdc++.h>
using namespace std;
template< class T > T sq(T x) { return x * x; }
#define PB(x) push_back(x)
#define ff first
#define ss second

const double eps=1e-9;
const double big=1e12;
const int inf=0x3f3f3f3f;
const int maxn=105;

typedef pair<int, int> point;
typedef struct { point u, v; double d; }segment;

segment s[maxn];
map<point, vector<int> > edge;
double dist[maxn][maxn];

inline double getdist(const point &a, const point &b) {
    return sqrt((double)sq(a.ff-b.ff)+(double)sq(a.ss-b.ss));
}

inline bool isleft(const point &a, const point &b, const point &c) {
    return (b.ff - a.ff) * (c.ss - a.ss) - (b.ss - a.ss) * (c.ff - a.ff) >= 0;
}

int main() {
    int T, icase=1, n;
    point bull;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &bull.ff, &bull.ss);
        edge.clear();
        for (int i=0;i<n;++i) {
            scanf("%d %d %d %d", &s[i].u.ff, &s[i].u.ss, &s[i].v.ff, &s[i].v.ss);
            if (!isleft(s[i].u, s[i].v, bull)) swap(s[i].u, s[i].v);
            s[i].d=getdist(s[i].u, s[i].v);
            edge[s[i].u].PB(i);
        }
        for (int i=0;i<n;++i) for (int j=0;j<n;++j) dist[i][j]=big;
        for (int u=0;u<n;++u) {
            for (int j=0;j<edge[s[u].v].size();++j) {
                int v=edge[s[u].v][j];
                if (isleft(s[u].u, s[u].v, s[v].v)) dist[u][v]=s[u].d+s[v].d;
                //if (dist[u][v]+eps<big) printf("%d %d %f\n", u, v, dist[u][v]);
            }
        }
        for (int k=0;k<n;++k) {
            for (int i=0;i<n;++i) {
                for (int j=0;j<n;++j) {
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        double ans=big;
        for (int i=0;i<n;++i) ans=min(ans, dist[i][i]);
        printf("Case %d: ", icase++);
        if (fabs(ans-big)<eps) printf("-1.0\n");
        else printf("%.8lf\n", ans);
    }
    return 0;
}
