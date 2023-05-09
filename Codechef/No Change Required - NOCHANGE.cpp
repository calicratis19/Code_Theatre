#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define LIM 1000000000
#define two(i) (1LL<<(i))
typedef long long ll;
int test, n,p;
vector<int>ar,ans;
bool rec(int sum, int i)
{
    if(i == ar.size())
        return false;
    if(sum%ar[i])
    {
        ans.push_back(sum/ar[i]+1);
        return true;
    }
    ans.push_back(sum/ar[i]-1);
    sum-=ar[i]*(sum/ar[i]-1);
    
    return rec(sum,i+1);
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin>>test;
    for(int i=1;i<=test;i++)
    {
        cin>>n>>p;
        ar.clear();
        ans.clear();
        ar.resize(n);
        while(n--)
            cin>>ar[n];
        if(rec(p,0))
        {
            cout<<"YES ";
            while(ans.size()<ar.size())
                ans.push_back(0);
            reverse(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}




