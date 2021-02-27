/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
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
#define VST(v) sort(v.begin(),v.end())
#define VSTr(v) sort(v.begin(),v.end(),greater<long long int>())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define T(n) printf("test %d\n",n)
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
double PI = 2 * acos(0.0);
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
const ll mod=1e9+7;
using namespace std;
ll SET(ll NUM,ll POS)
{
    return NUM | (1<<POS);
}
bool isOn(ll NUM,ll POS)
{
    return (bool)(NUM & (1<<POS));
}
ll arr[200010],n;
int subsetXOR(ll value)
{
    ll max_ele = arr[0];
    for (int i=1; i<n; i++)
        if (arr[i] > max_ele)
            max_ele = arr[i];
    ll m = (1 << (ll)(log2(max_ele) + 1) ) - 1;
    if( value > m  )
        return 0;
    ll dp[n+1][m+1];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
    for (int i=1; i<=n; i++)
        for (int j=0; j<=m; j++)
            dp[i][j] = ((dp[i-1][j]%mod) + (dp[i-1][j^arr[i-1]]%mod))%mod;
    return dp[n][value];
}

int main()
{
    //fast;
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<ll>V;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        VST(V);
        ll cnt=0;
        for(ll i=0; i<n; i++)
        {
            ll j=i+1,cn=1;
            while(j<n)
            {
                if(V[i]!=V[j])
                {
                    break;
                }
                j++;
                cn++;
            }
            arr[cnt++]=cn;
            i=j-1;
        }
        ll ans=0;
        n=cnt;
        ll value=0;
        ans=subsetXOR(value);
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
