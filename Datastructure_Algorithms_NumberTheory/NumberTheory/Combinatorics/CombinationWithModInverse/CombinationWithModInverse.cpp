/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
/// ncr
ll mod=1e9+7;
ll dp[1000020];
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
void init()
{
    dp[0]=1;
    dp[1]=1;
    for(ll i=2; i<=1000000; i++)
    {
        dp[i]=((dp[i-1]%mod)*i)%mod;
    }
}
ll ncr(ll n,ll r)
{
    ll ans=dp[n];
    ll div=((dp[r]%mod)*(dp[n-r]%mod))%mod;
    ll x,y;
    ll gcd=extended_euclidean(div,mod,x,y);
    x=(x+mod)%mod;
    ans=((ans%mod)*(x%mod))%mod;
    return ans;
}
int main()
{
    init();
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,sum=0;



    }
    return 0;
}






