/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define minus1 printf("-1\n");
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
#define mod 1000000007
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll dp[2000020];
ll extended_euclidean(ll a,ll b,ll& x,ll& y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1, y1;
    ll d=extended_euclidean(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}
int main()
{
    dp[0]=1;
    dp[1]=1;
    for(ll i=2; i<=2000000; i++)
    {
        dp[i]=((dp[i-1]%mod)*i)%mod;
    }
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        scanf("%lld%lld",&n,&m);
        m--;
        if(m==0)
        {
            printf("Case %lld: 1\n",test);
            continue;
        }
        n+=m;
        ll ans=dp[n];
        ll div=((dp[m]%mod)*(dp[n-m]%mod))%mod;
        ll x,y;
        ll gcd=extended_euclidean(div,mod,x,y);
        x=(x+mod)%mod;
        ans=((ans%mod)*(x%mod))%mod;
        printf("Case %lld: %lld\n",test,ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
