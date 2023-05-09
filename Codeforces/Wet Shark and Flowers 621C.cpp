#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define LIM 1000000000
#define two(i) (1LL<<(i))
typedef long long ll;
int n,a,b,ans,p;
int mem[101];
typedef pair<int,int> Pi;
vector<Pi>ar;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin>>n>>p;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        int cnt = b/p-(a-1)/p;
        ar.push_back(make_pair(b-a+1-cnt,cnt));
      //  cout<<b-a+1-cnt<<" "<<cnt<<endl;
    }
    double ans = 0;
    ar.push_back(ar[0]);
    ar.insert(ar.begin(),ar[0]);
    //cout<<"left No prime"<<endl;
    for(int i=1;i<=n;i++)
    {
        Pi left = ar[i-1];
        Pi cur = ar[i];
        ans+=(1.0*left.first)/(left.first+left.second) * (1.0*cur.second)/(cur.first+cur.second);
        left = ar[i+1];        
        ans+=(1.0*left.first)/(left.first+left.second) * (1.0*cur.second)/(cur.first+cur.second);
        //cout<<ans<<endl;
    }
    ans*=2000;
    double ans1 = 0;
    //cout<<"left prime"<<endl;
    for(int i=0;i<n;i++)
    {
        Pi left = ar[i+1];
        Pi cur = ar[i];
        ans1+=(1.0*left.second)/(left.first+left.second) * (1.0*cur.second)/(cur.first+cur.second);
       //cout<<ans1<<endl;
    }
    ans1*=2000;
    //cout<<ans<<" "<<ans1<<endl;
    cout<<setprecision(7)<<ans+ans1<<endl;
    return 0;
}




