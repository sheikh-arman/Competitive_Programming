/*
    Sk arman Hossain
    University of Barisal

    Problem : Lightoj 1231
    Solution : DP(Coin Change)
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) cin>>n
#define sf2(n, m) cin>>n>>m
#define sf3(n, m,k ) cin>>n>>m>>k
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define minus1 printf("-1\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 100000007
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<ll>V,V2,V3;
ll chache[110][10010],n,k,ar[110];
ll dp(ll i,ll val)
{
    if(i>=n)
    {
        if(val==k)
        {
            return 1;
        }
        else return 0;
    }
    if(chache[i][val]!=-1)
    {
        return chache[i][val];
    }
    ll ans=0;
    for(ll j=0; j<=ar[i]; j++)
    {
        if((V[i]*j)+val<=k)
        {
            ans+=dp(i+1,(V[i]*j)+val);
            ans%=mod;
        }
    }
    return chache[i][val]=ans%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        cin>>n>>k;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        for(ll i=0; i<n; i++)
        {
            cin>>ar[i];
        }
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=k; j++)chache[i][j]=-1;
        }
        ll ans=dp(0,0);
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



