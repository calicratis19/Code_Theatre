#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define LIM 1000000000
#define two(i) (1LL<<(i))
typedef long long ll;


ll nItem,n,k;
ll giftChoice[1000001],freq[1000001];
vector<vector<ll> > itemOnKids;


ll pwr(ll x, ll y)
{
    ll ans = 1;
    while(y)
    {
        if(y&1)
            ans = (ans*x)%MOD;
        y>>=1;
        x = (x*x)%MOD;
    }
    return ans;
}


int main()
{    
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin>>n; 
    itemOnKids.resize(1000001); 
    nItem=0;
    for(int i=0;i<n;i++)
    {
        cin>>giftChoice[i];        
        for(int j=0;j<giftChoice[i];j++)
        {
            cin>>k;
            freq[k]++;
            itemOnKids[k].push_back(i);
            nItem=max(nItem,k);
        }
    }
    ll totDeno=1;
    vector<ll>vNomin,vDeno;
    for(int i=1;i<=nItem;i++)
    {
        ll deno = 1,nomin=0;
        for(int j=0;j<itemOnKids[i].size();j++)
        {
            ll kid = itemOnKids[i][j];
            deno = (deno*1LL*giftChoice[kid])%MOD;
            //cout<<deno<<" "<<kid<<" "<<giftChoice[kid]<<endl;
        }
        //cout<<"----------"<<endl;
        for(int j=0;j<itemOnKids[i].size();j++)
        {
            ll kid = itemOnKids[i][j];
            ll m = (1LL*deno*pwr(giftChoice[kid],MOD-2))%MOD;
            nomin = (nomin+m)%MOD;
            //cout<<nomin<<" "<<kid<<" "<<giftChoice[kid]<<" "<<m<<" "<<power(giftChoice[kid],MOD-2)<<endl;
        }

        nomin = (nomin*freq[i])%MOD;
        deno = (((deno*n)%MOD)*n)%MOD;
        ll gcd = __gcd(nomin,deno);
        nomin/=gcd;
        deno/=gcd;
        //cout<<"++++"<<nomin<<"/"<<deno<<" "<<freq[i]<<endl;
        vNomin.push_back(nomin);
        vDeno.push_back(deno);
        totDeno = (totDeno*deno)%MOD;
    }
   // cout<<"******"<<totDeno<<endl;

    ll ans = 0,nomin=0;
    for(int i=0;i<vNomin.size();i++)
    {
        nomin=(nomin+(vNomin[i]*((totDeno*pwr(vDeno[i],MOD-2))%MOD))%MOD)%MOD;
        //cout<<nomin<<" "<<totDeno<<" "<<vNomin[i]<<" "<<power(vNomin[i],MOD-2)<<endl;
    }

    cout<<(nomin*pwr(totDeno,MOD-2))%MOD<<endl;
    
    return 0;
}




