//水题
#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<sstream>

using namespace std;
string line;
int asd[10000];
int main()
{
    while(getline(cin,line))
    {
        int now;
        stack<int> st__;

        int flag = 1;
        istringstream in(line);
        while(in >>now)
        {
            //cout<<now<<endl;
            if(now < 0)
            {
                st__.push(now);
            }
            else
            {
                int sum=0;
                int temp;
                while(!st__.empty()&&(temp = st__.top())&&temp > 0)
                {
                    sum += temp;
                    st__.pop();
                }
                if(temp + now == 0 && sum < now)
                {
                    st__.top() = now;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
        }
        while(!st__.empty())
        {
            if(st__.top()>0)
                st__.pop();
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf(":-) Matrioshka!\n");
        }
        else
            printf(":-( Try again.\n");
    }
    return 0;
}
