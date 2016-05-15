/*
“敌人的敌人是朋友”，对二分图dfs时，奇数层和偶数层一定属于不同的部。
统计每个二分图的两部的大小，取大的那方求和，得出最大可能的帮派人数。
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=20005;
vector<int> edge[maxn];
bool vis[maxn], mp[maxn];

void dfs(int dep, int u, int &tot, int &blk) {
  int sz=edge[u].size();
  ++tot;
  if (dep&1) ++blk;
  for (int i=0;i<sz;++i) {
    if (vis[edge[u][i]]) continue;
    vis[edge[u][i]]=true;
    dfs(dep+1, edge[u][i], tot, blk);
  }
}

int main() {
  int T, icase=1, n, ans;
  scanf("%d", &T);
  while (T--) {
    memset(mp, false, sizeof(mp));
    scanf("%d", &n);
    for (int i=0;i<maxn;++i) edge[i].clear();
    for (int i=0;i<n;++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      --x, --y;
      edge[x].push_back(y);
      edge[y].push_back(x);
      mp[x]=mp[y]=true;
    }
    ans=0;
    memset(vis, false, sizeof(vis));
    for (int i=0;i<maxn;++i) {
      int tot=0, blk=0;
      if (!mp[i]||vis[i]) continue;
      vis[i]=true;
      dfs(0, i, tot, blk);
      //printf("%d %d\n", tot, blk);
      ans+=max(tot-blk, blk);
    }
    printf("Case %d: %d\n", icase++, ans);
  }
  return 0;
}
