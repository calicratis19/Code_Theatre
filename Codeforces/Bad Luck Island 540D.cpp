#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define LIM 1000000000
#define two(i) (1LL<<(i))
typedef long long ll;
int n;
double mem[101][101][101][3];
vector<long double>ar;


double rec(int r, int p, int s, int state)
{
    if(r<0 || p<0 || s<0)
        return 0;
    int cnt = (r==0) + (p==0) + (s==0);
    if(cnt==2)
        return 1;

    double &ret = mem[r][p][s][state];
    if(ret+1>.0000001)
        return ret;
    int pr = p * r;
    int sp = s * p;
    int rs = r * s;
    double tot = pr + sp + rs;
    if(state==0)//rock
        ret = rs/tot*rec(r,p,s-1,state) + sp/tot*rec(r,p-1,s,state) + (r>1)*(pr/tot)*rec(r-1,p,s,state);
    else if(state == 1)//paper
        ret = pr/tot*rec(r-1,p,s,state) + rs/tot*rec(r,p,s-1,state) + (p>1)*(sp/tot)*rec(r,p-1,s,state);
    else 
        ret = sp/tot*rec(r,p-1,s,state) + pr/tot*rec(r-1,p,s,state) + (s>1)*(rs/tot)*rec(r,p,s-1,state);

    return ret;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int r, p, s;    
    cin>>r>>s>>p;
    memset(mem,-1,sizeof(mem));
    cout<<setprecision(10)<<rec(r,p,s,0)<<" "<<rec(r,p,s,2)<<" "<<rec(r,p,s,1)<<endl;
    return 0;
}




