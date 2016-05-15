/*
bfs水题
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=25;
char mp[maxn][maxn];
int ans, w, h;
int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
struct P {
  int x, y;
  P() {}
  P(int _x, int _y):x(_x), y(_y) {}
};
deque<P> que;

void bfs(int x, int y) {
  while (!que.empty()) que.pop_front();
  P cur=P(x, y);
  que.push_back(cur);
  while (!que.empty()) {
    cur=que.front();
    que.pop_front();
    ++ans;
    for (int k=0;k<4;++k) {
      int nx=cur.x+dx[k], ny=cur.y+dy[k];
      if (nx<0||ny<0||nx>=w||ny>=h||mp[ny][nx]!='.') continue;
      que.push_back(P(nx, ny));
      mp[ny][nx]='@';
    }
  }
}

int main() {
  int T, icase=1, sx, sy;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &w, &h);
    for (int i=0;i<h;++i) {
      scanf("%s", mp[i]);
      for (int j=0;j<w;++j) {
        if (mp[i][j]=='@') {
          sx=j, sy=i;
        }
      }
    }
    ans=0;
    bfs(sx, sy);
    printf("Case %d: %d\n", icase++, ans);
  }
  return 0;
}
