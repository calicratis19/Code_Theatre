#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define two(i) (1LL<<(i))
typedef long long ll;
ll n,test,m,cas;
string l,r,range;

ll mem[2][2][52][52][52][52],casio[2][2][52][52][52][52];

//string str;
ll rec(int m, int pos, int mod, int digitMod, bool nonZero, bool isGreater, string str="" )
{
    if(pos<0)
    {
        return (mod == 0 && digitMod == 0 && nonZero);
    }
    ll &ret = mem[isGreater][nonZero][m][pos][mod][digitMod];
    ll &cs = casio[isGreater][nonZero][m][pos][mod][digitMod];
    if(~ret && (isGreater || cs==cas))
        return ret;
    
    cs = cas;
    ret = 0;
    for(int i=0;i<=(isGreater?9:(range[pos]-48));i++)
    {
        ret+=rec(m,pos-1,(mod*10+i)%m,(digitMod+i)%m,nonZero|i>0,isGreater|(i!=range[pos]-48),str);
        while(ret>=MOD)
            ret-=MOD;
    }
    return ret;
}
bool cal(string str)
{
    int mod = 0,mod1=0;
    for(int i=0;i<str.size();i++)
    {
        mod = (mod*10+str[i]-48)%m;
        mod1 =(mod1+str[i]-48)%m;
    }
    return (mod == 0 && mod1==0);
}

int main()
{    
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    memset(mem,-1,sizeof(mem));
    memset(casio,-1,sizeof(casio));

    cin>>test;

    while(test--)
    {
        cin>>l>>r>>m;
        cas++;
        range = l;
        reverse(range.begin(),range.end());
        int ret1 = rec(m,range.size()-1,0,0,0,0);
        cas++;
        range = r;
        reverse(range.begin(),range.end());
        int ret2 = rec(m,range.size()-1,0,0,0,0);


        ll ret = ret2-ret1+cal(l);
        while(ret<0)
            ret+=MOD;

        cout<<ret<<endl;

    }

    return 0;
}




