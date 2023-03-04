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
ll ar[1000010];
ll cum1[1000010];
ll cum1_rev[1000010];
ll cum2[1000010];
ll cum2_rev[1000010];
int main()
{
    //freopen("input21.txt","r",stdin);
    //freopen("output21.txt","w",stdout);
    //fast;
    ll tcase=1;
   // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,q;
        cin>>n>>q;
        assert(n>=1&&n<=100000&&q>=1&&q<=100000);
        for(ll i=0;i<=n+1;i++){
            ar[i]=cum1[i]=cum2[i]=cum1_rev[i]=cum2_rev[i]=0;
        }
        for(ll i=1;i<=n;i++){
            cin>>ar[i];
            assert(1<=ar[i]&&ar[i]<=1000000);
        }
        ll sum=0;
        for(ll i=2;i<=n;i++){
            sum+=abs(ar[i]-ar[i-1]);
            cum1[i-1]=sum;
        }
        sum=0;
        for(ll i=n-1;i>=1;i--){
            sum+=abs(ar[i]-ar[i+1]);
            cum1_rev[i]=sum;
        }
        sum=0;
        for(ll i=1;i<=n;i++){
            sum+=cum1[i];
            cum2[i]=sum;
        }
        sum=0;
        for(ll i=n;i>=1;i--){
            sum+=cum1_rev[i];
            cum2_rev[i]=sum;
        }
        for(ll i=1;i<=q;i++){
            ll x;
            cin>>x;
            assert(x>=1&&x<=n);
            ll tm1=cum2[n-1]-cum2[x-1];

            tm1-=(n-x)*cum1[x-1];

            ll tm2=(cum2_rev[1]-cum2_rev[x]);
            tm2-=(x-1)*cum1_rev[x];
            ll ans=tm1+tm2;
            cout<<ans<<"\n";
        }
    }
    return 0;
}





