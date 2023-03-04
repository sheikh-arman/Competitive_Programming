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
    //freopen("input00.txt","r",stdin);
    //freopen("output00.txt","w",stdout);
    //fast;
    ll tcase=1;
   // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,q;
        cin>>n>>q;
        for(ll i=0;i<=n+1;i++){
            ar[i]=cum1[i]=cum2[i]=cum1_rev[i]=cum2_rev[i]=0;
        }
        for(ll i=1;i<=n;i++){
            cin>>ar[i];
        }
        for(ll i=1;i<=q;i++){
            ll x;
            cin>>x;
            ll ans=0;
            ll sum=0;
            for(ll j=x-1;j>=1;j--){
                sum+=abs(ar[j]-ar[j+1]);
                ans+=sum;
            }
            sum=0;
            for(ll j=x;j<n;j++){
                sum+=abs(ar[j]-ar[j+1]);
                ans+=sum;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}





