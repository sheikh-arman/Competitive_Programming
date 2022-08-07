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
ll mem[110][110][110];
vector<ll>V;
ll n;
ll mod=998244353;
ll dp(ll i,ll k,ll sum,ll mo)
{
    //cout<<i<<" "<<k<<" "<<sum<<" "<<mo<<" t\n";
    if(i>=n)
    {
        return (k==0&&sum==0);
    }
    if(mem[i][k][sum]!=-1)
    {
        return mem[i][k][sum];
    }
    ll ans=0;
    if(k>0)
        ans=dp(i+1,k-1,(sum+V[i])%mo,mo);
    if(ans>=mod)ans%=mod;
    ans+=dp(i+1,k,sum,mo);
    if(ans>=mod)ans%=mod;
    return mem[i][k][sum]=ans;
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
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        for(ll i=0; i<=n+1; i++)
        {
            for(ll j=0; j<=n+1; j++)
            {
                for(ll k=0; k<=n+1; k++)
                {
                    mem[i][j][k]=-1;
                }
            }
        }
        ll ans=0;
        for(ll i=1; i<=n; i++)
        {
            ans+=dp(0,i,0,i);
            //cout<<ans<<" hi\n";
            if(ans>=mod)ans%=mod;
            for(ll j=0; j<=n+1; j++)
            {
                for(ll k=0; k<=i; k++)
                {
                    for(ll f=0; f<=i; f++)
                    {
                        mem[j][k][f]=-1;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}





