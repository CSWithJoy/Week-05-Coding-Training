/*
基础bfs,注意那三个字母是一个一个变而不是三个一起变。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,n,ans,fla;

string start,goal;

map<string,int> f;

set<string> flag;

string deal(string np,int i,int j,int k){
    string p=np;
    if(i==0) {
     if(p[0]>='a'&&p[0]<'z') p[0]+=1;
     else if(p[0]=='z') p[0]='a';
    }
    if(i==1) {
        if(p[0]>'a'&&p[0]<='z') p[0]-=1;
        else if(p[0]=='a') p[0]='z';
    }
    if(j==0) {
     if(p[1]>='a'&&p[1]<'z') p[1]+=1;
     else if(p[1]=='z') p[1]='a';
    }
    if(j==1) {
     if(p[1]>'a'&&p[1]<='z') p[1]-=1;
     else if(p[1]=='a') p[1]='z';
    }
    if(k==0) {
     if(p[2]>='a'&&p[2]<'z') p[2]+=1;
     else if(p[2]=='z') p[2]='a';
    }
    if(k==1) {
     if(p[2]>'a'&&p[2]<='z') p[2]-=1;
     else if(p[2]=='a') p[2]='z';
    }
  return p;
}

int bfs(){
 queue<string> que;
 que.push(start);
 flag.insert(start);
 while(!que.empty()){
        string p=que.front();que.pop();
        if(p==goal) return f[goal];
                string np=deal(p,1,-1,-1);
                if(flag.find(np)==flag.end()){
                f[np]=f[p]+1;
                flag.insert(np);
                que.push(np);
                }
                np=deal(p,0,-1,-1);
                if(flag.find(np)==flag.end()){
                f[np]=f[p]+1;
                flag.insert(np);
                que.push(np);
                }
                np=deal(p,-1,1,-1);
                if(flag.find(np)==flag.end()){
                f[np]=f[p]+1;
                flag.insert(np);
                que.push(np);
                }
                np=deal(p,-1,0,-1);
                if(flag.find(np)==flag.end()){
                f[np]=f[p]+1;
                flag.insert(np);
                que.push(np);
                }
                np=deal(p,-1,-1,1);
                if(flag.find(np)==flag.end()){
                f[np]=f[p]+1;
                flag.insert(np);
                que.push(np);
                }
                np=deal(p,-1,-1,0);
                if(flag.find(np)==flag.end()){
                f[np]=f[p]+1;
                flag.insert(np);
                que.push(np);
                }
 }
 return -1;
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        fla=0,f.clear(),flag.clear();
        cin>>start>>goal;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
                cin.clear();
                string a,b,c;
                cin>>a>>b>>c;
                for(size_t k=0;k<a.length();k++)
                        for(size_t j=0;j<b.length();j++)
                             for(size_t l=0;l<c.length();l++){
                                  string str;
                                  str+=a[k];
                                  str+=b[j];
                                  str+=c[l];
                                  //cout<<str<<endl;
                                  if(str==goal||str==start) fla=1;
                                  flag.insert(str);
                             }
        }
        if(fla==1) {printf("Case %d: -1\n",h);continue;}
        ans=bfs();
        if(ans==-1) printf("Case %d: -1\n",h);
        else printf("Case %d: %d\n",h,ans);
    }
    return 0;
}
