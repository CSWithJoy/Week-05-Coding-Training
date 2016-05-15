//水题
#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int p[150];
int ll[10000];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        int P;
        scanf("%d%d",&N,&P);
        for(int i = 0; i<P;i++)
            scanf("%d",&p[i]);
        memset(ll,0,sizeof(ll));
        for(int i = 0;i <P;i++)
        {
            for(int j = 0;j<=N;j+=p[i])
            {
                ll[j] = 1;
            }
        }
        for(int i = 6;i<=N+1;i+=7)
        {
            ll[i] = 0;
            ll[i+1] = 0;
        }
        int sum = 0;
        for(int i =1;i<=N;i++)
            sum += ll[i];
        cout<<sum<<endl;
    }
    return 0;
}
