#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define LIM 1000000000
#define two(i) (1LL<<(i))
typedef long long ll;
int n;
vector<long double>ar;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin>>n;
    ar.resize(n);
    for(int i=0;i<n;i++)
        cin>>ar[i];        
    sort(ar.rbegin(),ar.rend());

    long double ans=0,prod=1,sum=0;
    for(int i=0;i<n;i++)
    {
        prod*=(1-ar[i]);
        sum+=(ar[i]/(1-ar[i]));
        if(ar[i]==1)
            ans = 1;
       ans = max(ans, prod*sum);
    }
    cout<<setprecision(10)<<ans<<endl;
    return 0;
}




