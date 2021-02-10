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

#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll bigmod(ll base,ll power,ll mod)
{
    if(power==1)
    {
        return base;
    }
    if(power==0)
    {
        return 1;
    }
    if(power%2==0)
    {
        ll p=bigmod(base,power/2,mod);
        return ((p%mod)*(p%mod))%mod;
    }
    else
    {
        return (bigmod(base,power-1,mod)*base)%mod;
    }
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    scanf("%lld",&tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<ll>V;
        ll n,m,k;
        //cin>>n>>k>>m;
        scanf("%lld%lld%lld",&n,&k,&m);
        for(ll i=0; i<n; i++)
        {
            ll a;
            //cin>>a;
            scanf("%lld",&a);
            V.PB(a);
        }
        ll ans=0;
        ll frequency=(bigmod(n%m,k-1,m)*(k%m))%m;
        for(ll i=0; i<n; i++)
        {
            ans+=((V[i]%m)*(frequency%m))%m;
            ans%=m;
        }
       // cout<<"Case "<<test<<": "<<ans<<endl;
        printf("Case %lld: %lld\n",test,ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



