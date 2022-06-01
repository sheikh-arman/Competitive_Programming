#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define mp pair<ll,ll>
#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d %d",&n,&m)
#define sfl(n) scanf("%lld", &n)
#define sfu(n) scanf("%llu", &n)
#define sffl(n, m) scanf("%lld %lld",&n,&m)
#define prn(n) printf("%d\n",n)
#define pf(n) printf("%d ",n)
#define pfl(n) printf("%lld ",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int>v,v2,v3,cost,wet;
vector<int> :: iterator it1,it2;
int dp[1002][32];
int n,mw;
int knap(int pos,int w)
{
    int profit1,profit2;
    if(pos==n)
    {
        return 0;
    }
    if(dp[pos][w]!=-1)
        return dp[pos][w];
    if(wet[pos]+w<=mw)
    {
        profit1=cost[pos]+knap(pos+1,wet[pos]+w);
    }
    else
        profit1=0;
    profit2=knap(pos+1,w);
    dp[pos][w]=max(profit1,profit2);
    return dp[pos][w];
}
int main()
{
    ///freopen("input.txt","r",stdin);
    ///while(1){
    int t,x;
    sf(t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        cost.clear();
        wet.clear();
        sf(n);
        for(int i=0; i<n; i++)
        {
            int a,b;
            sff(a,b);
            cost.pb(a);
            wet.pb(b);
        }
        sf(x);
        for(int i=0; i<x; i++)
        {
            sf(mw);
            memset(dp,-1,sizeof(dp));
            ans+=knap(0,0);
        }
        printf("%d\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


