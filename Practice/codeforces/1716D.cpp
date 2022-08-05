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
ll ar[200010];
ll mem[200010][450];
ll mod=998244353;
ll dp(ll i,ll k)
{
    if(i==0)
    {
        //cout<<i<<" t\n";
        return 1;
    }
    if(i<0)
    {
        return 0;
    }
    if(mem[i][k]!=-1)
    {
        return mem[i][k];
    }
    ll ans=0;
    ans+=dp(i-k,k);
    if(ans>=mod)ans%=mod;
    ans1=dp(i-(k+k+1),k+1);
    mem[i]
    if(ans>=mod)ans%=mod;
    return mem[i][k]=ans;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        cin>>n>>k;
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=k; j++)
            {
                mem[i][j]=-1;
            }
        }
        for(ll i=1; i<=n; i++)
        {
            ll ans=dp(i,k);
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}




