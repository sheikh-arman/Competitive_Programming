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
int main()
{
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll sumx=0,squarex=0;
        ll sumy=0,squarey=0;
        ll n,q;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a,b;
            cin>>a>>b;
            sumx+=a;
            sumy+=b;
            squarex+=(a*a);
            squarey+=(b*b);
            if(sumx>=mod)sumx%=mod;
            if(sumy>=mod)sumy%=mod;
            if(squarex>=mod)squarex%=mod;
            if(squarey>=mod)squarey%=mod;
        }
        cin>>q;
        ll ans=0;
        for(ll i=0; i<q; i++)
        {
            ll a,b;
            cin>>a>>b;
            ll resx=n*((a*a)%mod);
            if(resx>=mod)resx%=mod;
            resx+=squarex;
            resx-=((2*((a*sumx)%mod))%mod);
            while(resx<0)resx+=mod;
            ll resy=n*((b*b)%mod);
            if(resy>=mod)resy%=mod;
            resy+=squarey;
            resy-=((2*((b*sumy)%mod))%mod);
            while(resy<0)resy+=mod;
            ans+=(resx+resy);
            if(ans>=mod)ans%=mod;
        }
        cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
    return 0;
}






