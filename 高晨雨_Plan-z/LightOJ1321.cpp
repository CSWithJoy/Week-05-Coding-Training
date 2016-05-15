//求0到n-1点的最大成功概率，状态转移方程：dp[i][j] = max(dp[i][j],dp[i][k] * dp[k][j])
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN = 110;
double dp[MAXN][MAXN];
int N,M,S,K;

void calcu(int kase) {
    for (int i = 0 ; i <= N ; i++) dp[i][i] = 1;
    for (int k = 0 ; k < N ; k++) {
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++)
                dp[i][j] = max(dp[i][j],dp[i][k] * dp[k][j]);
        }
    }
    double ans = dp[0][N - 1];
    ans = 1.0 / ans * 2.0 * K * S;
    printf("Case %d: %.8lf\n",kase++,ans);
}

int main() {
    int T,kase = 1;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d%d",&N,&M,&S,&K);
        memset(dp,0,sizeof(dp));
        for (int i = 0 ; i < M ; i++) {
            int u,v;
            double p;
            scanf("%d%d%lf",&u,&v,&p);
            dp[u][v] = dp[v][u] = max(dp[u][v],p / 100.0);
        }
        calcu(kase++);
    }
    return 0;
}
