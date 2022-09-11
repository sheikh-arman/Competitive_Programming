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
ll arx[3010];
ll ary[3010];
ll ans_x[3010];
ll ans_y[3010];
ll mod=1000000007;
int main()
{
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        for(ll i=0; i<=3000; i++)
        {
            arx[i]=0;
            ary[i]=0;
            ans_x[i]=0;
            ans_y[i]=0;
        }
        ll n,q;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a,b;
            cin>>a>>b;
            arx[a]++;
            ary[b]++;
        }
        for(ll i=0; i<=3000; i++)
        {
            ll res=0;
            for(ll j=0; j<=3000; j++)
            {
                ll tm=abs(i-j);
                tm*=tm;
                if(tm>=mod)tm%=mod;
                tm*=arx[j];
                res+=tm;
                if(res>=mod)res%=mod;
            }
            ans_x[i]=res;
        }
        for(ll i=0; i<=3000; i++)
        {
            ll res=0;
            for(ll j=0; j<=3000; j++)
            {
                ll tm=abs(i-j);
                tm*=tm;
                if(tm>=mod)tm%=mod;
                tm*=ary[j];
                res+=tm;
                if(res>=mod)res%=mod;
            }
            ans_y[i]=res;
        }
        ll ans=0;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll a,b;
            cin>>a>>b;
            ans+=ans_x[a]+ans_y[b];
            if(ans>=mod)
                ans%=mod;
        }
        cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
    return 0;
}





