#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LIM 5000000
#define two(i) (1LL<<(i))
typedef long long ll;
ll n,m,cas;

int main()
{    
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    cin>>m>>n;     
    double sum=0;
    for(int i=1;i<=m;i++)
        sum+=(pow((1.0*i)/m,n)-pow((1.0*i-1)/m,n))*i;
    
    cout<<setprecision(6)<<sum<<endl;
    return 0;
}




