/*
bfs水题
*/
#include <bits/stdc++.h>
using namespace std;
map<string, bool> vis;
string st, ed;
struct P {
  string str;
  int dep;
  P() {}
  P(string _str, int _dep):str(_str), dep(_dep) {}
};
deque<P> que;
 
void cal(string &str, int x, int pos) {
  str[pos]+=x;
  if (str[pos]>'z') {
    str[pos]='a';
  }else if (str[pos]<'a') {
    str[pos]='z';
  }
}
 
int bfs() {
  P cur=P(st, 0);
  while (!que.empty()) que.pop_front();
  if (vis[st]) return -1;
  que.push_back(cur);
  while (!que.empty()) {
    cur=que.front();
    que.pop_front();
    //printf("%s\n", cur.str.c_str());
    if (cur.str==ed) return cur.dep;
    for (int k=0;k<3;++k) {
      string nxt=cur.str;
      cal(nxt, 1, k);
      if (!vis[nxt]) {
        vis[nxt]=true;
        que.push_back(P(nxt, cur.dep+1));
      }
      nxt=cur.str;
      cal(nxt, -1, k);
      if (!vis[nxt]) {
        vis[nxt]=true;
        que.push_back(P(nxt, cur.dep+1));
      }
    }
  }
  return -1;
}
 
int main() {
  int T, icase=1, n;
  scanf("%d", &T);
  while (T--) {
    char in0[5], in1[5];
    scanf("%s%s", in0, in1);
    st.clear();
    st.assign(in0);
    st[3]='\0';
    ed.clear();
    ed.assign(in1);
    ed[3]='\0';
    scanf("%d", &n);
    vis.clear();
    while (n--) {
      char p[3][30];
      string tmp;
      scanf("%s%s%s", p[0], p[1], p[2]);
      int l0=strlen(p[0]), l1=strlen(p[1]), l2=strlen(p[2]);
      tmp.clear();
      for (int i=0;i<l0;++i) {
        for (int j=0;j<l1;++j) {
          for (int k=0;k<l2;++k) {
            tmp.clear();
            tmp+=p[0][i];
            tmp+=p[1][j];
            tmp+=p[2][k];
            vis[tmp]=true;
          }
        }
      }
    }
    printf("Case %d: %d\n", icase++, bfs());
  }
  return 0;
}
