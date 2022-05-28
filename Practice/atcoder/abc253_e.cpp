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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> policy_set;

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
ll n,m,k;
ll mem[5010];
ll cum[5010];
ll mod=998244353;
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n>>m>>k;
        for(ll j=0; j<=m; j++)
        {
            mem[j]=0;
        }
        for(ll j=1; j<=m+2; j++)
        {
            cum[j]=j;
        }
        for(ll i=1; i<n; i++)
        {
            for(ll j=1; j<=m; j++)
            {
                ll val=0;
                if(j-k>=1)
                {
                    val+=cum[j-k];
                }
                ll ma=min(m+1,j+k+(k==0));
                ll tm=cum[m]-cum[ma-1];
                while(tm<0)
                {
                    tm+=mod;
                }
                val+=tm%mod;
                mem[j]=val;
                mem[j]%=mod;
            }
            ll sum=0;
            for(ll j=1; j<=m; j++)
            {
                sum+=mem[j];
                sum%=mod;
                cum[j]=sum;
            }
        }
        ll ans=cum[m];
        cout<<ans<<"\n";
    }
    return 0;
}




