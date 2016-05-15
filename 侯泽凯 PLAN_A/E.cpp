//居然是求最短路。。。看了题解才读懂题Orz，读了3天的题。。。
#include<bits/stdc++.h>
using namespace std;

int n, m, s, k;
int z=1;
double f[110][110];

void solve()
{
    for(int i = 0; i < n; i ++)
        f[i][i] = 1.0;

    for(int t = 0; t < n; t ++)
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                f[i][j] = max(f[i][j], f[i][t] * f[t][j]);

    double ans = f[0][n-1];

    double ex = (1.0 / ans) * (2.0 * k * s);

    printf("Case %d: %.10lf\n",z++, ex);
}

int main()
{
    int T;
    scanf("%d", &T);

    while(T --)
    {
        scanf("%d %d %d %d", &n, &m, &s, &k);

        int u, v, p;

        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                f[i][j] = 0.0;

        for(int i = 0; i < m; i ++)
        {
            scanf("%d %d %d", &u, &v, &p);
            f[u][v] = f[v][u] = p / 100.0;
        }

        solve();
    }
    return 0;
}