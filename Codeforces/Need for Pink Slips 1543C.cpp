#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LIM 1000000000
#define two(i) (1LL<<(i))
typedef long long ll;

int test;
long double c,m,p,v;

long double dfs(long double c, long double m, long double p, int l)
{
    if(c<0.0000001 && m<0.0000001)
        return l;
    
    long double sum = p*l;
    double cc = max(0.0L,c-v);
    double mm = max(0.0L,m-v);
    double vv = c-cc;
    if(c>0.0000001)
    {
        if(m>.0000001)
            sum+=c*dfs(cc,m+vv/2,p+vv/2,l+1);
        else sum+=c*dfs(cc,0,p+vv,l+1);
    }

    vv = m-mm;
    if(m>.0000001)
    {
        if(c>.0000001)
            sum+=m*dfs(c+vv/2,mm,p+vv/2,l+1);
        else sum+=m*dfs(0,mm,p+vv,l+1);
    }

    return sum;

}


int main()
{    
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin>>test;  
    while(test--)
    {
        cin>>c>>m>>p>>v;
        cout<<setprecision(7)<<dfs(c,m,p,1)<<endl;
    }
    
    return 0;
}




