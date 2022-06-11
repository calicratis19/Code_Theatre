#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LIM 1000000000
#define two(i) (1LL<<(i))
typedef long long ll;
int mem[2001][2001];
int n,k,test;
vector<vector<int> > ar;
int rec(int pos, int num)
{
    if(num == 1 || pos == 0)        
        return 1;
    
    int &ret = mem[pos][num];
    if(~ret)
        return ret;
    ret = 0;
    for(int i=0;i<ar[num].size();i++)
    {
        ret+=rec(pos-1,ar[num][i]);
        if(ret>=MOD)
            ret-=MOD;        
    }
    return ret;
}

void genFact(int n)
{    
    ar.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        ar[i].push_back(i);
        for(int j=1;j<=i/2;j++)
        {
            if(i%j)
                continue;
            ar[i].push_back(j);
        }
    }
}


int main()
{    
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin>>n>>k;
    genFact(n);
    memset(mem,-1,sizeof(mem));
    int ret = 0;
    for(int i=1;i<=n;i++)
    {
        ret+=rec(k-1,i);
        if(ret>=MOD)
            ret-=MOD; 
    }
    cout<<ret<<endl;
    return 0;
}




