#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LIM 1000000000
#define two(i) (1LL<<(i))
typedef long long ll;
ll n,x,t,test;

int main()
{    
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin>>test;
    while(test--)
    {
        cin>>n>>x>>t;
        ll k = min(n-1,t/x);

        ll l = max(0LL,((n-1)*x-t))/x+(((n-1)*x-t)%x!=0)+1;
        if((n-1)*x<t)
            l = 1;
        ll m = ((k-1)*k)/2;
        //cout<<k<<" "<<l<<" "<<m<<endl;
        cout<<l*k+m<<endl;    
    }
    
    return 0;
}




