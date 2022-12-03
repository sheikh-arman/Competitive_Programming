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

ll mod=1000000007;
ll big_mod(ll n,ll p)
{
    if(p==0)
    {
        return 1LL;
    }
    if(p==1)
    {
        return n;
    }
    if(p%2==0)
    {
        ll tm=big_mod(n,p/2);
        ll val=((tm%mod)*(tm%mod))%mod;
        return val;
    }
    else
    {
        ll val=((big_mod(n,p-1)%mod)*(n%mod))%mod;
        return val;
    }
}
ll extended_euclidean(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        ll val=big_mod(n,m);
        //cout<<val<<" x\n";
        ll x,y;
        ll g = extended_euclidean(n, mod, x, y);
        while(x<0)x+=mod;
        ll sub=(val*x)%mod;
        ll ans=val-sub;
        while(ans<0)ans+=mod;
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}






