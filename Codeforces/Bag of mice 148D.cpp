#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LIM 1000000000
#define two(i) (1LL<<(i))
typedef long long ll;
double mem[4][1001][1001];
ll W,B;
double rec(int w,int b, int state)
{
    if(w == 0)
        return 0;
    if(b==0)
        return (state != 2);
    

    double &ret = mem[state][w][b];
    if(ret+1>.00000001)
        return ret;

    if(state == 1)//princess
        ret = (w/(1.0*w+b))+(b/(1.0*w+b))*rec(w,b-1,2);
    else if(state == 2)//Dragon
        ret = (b/(1.0*w+b))*rec(w,b-1,3);
    else
        ret = (b/(1.0*w+b))*rec(w,b-1,1) + (w/(1.0*w+b))*rec(w-1,b,1);
    
    return ret;
}

int main()
{    
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    memset(mem,-1,sizeof(mem));
    cin>>W>>B;
    cout<<setprecision(10)<<rec(W,B,1)<<endl;  

    return 0;
}




