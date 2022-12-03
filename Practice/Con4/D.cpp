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
ll ar[100010];
ll toten[100010];
ll N=100000;
void totient()
{
    toten[1]=1;
    for(ll i=2; i<=N; i++)
    {
        toten[i]=i-1;
    }
    for (ll i = 2; i <= N; i++)
    {
        for (ll j = 2 * i; j <= N; j += i)
        {
            toten[j] -= toten[i];
        }
    }
}
int main()
{
    totient();
//    for(ll i=1; i<=100; i++)
//    {
//        cout<<toten[i]<<" x\n";
//    }
    for(ll i=1;i<=N;i++){
        for(ll j=i+i;j<=N;j+=i){
            ar[j]+=toten[j/i]*i;
            if(ar[j]>=mod){
                ar[j]%=mod;
            }
        }
    }
    for(ll i=1;i<=N;i++){
        ar[i]+=ar[i-1];
        if(ar[i]>=mod)ar[i]%=mod;
    }
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll a,b;
            cin>>a>>b;
            ll ans=ar[b]-ar[a-1];
            ans+=mod;
            ans%=mod;
            cout<<ans<<"\n";
        }



    }
    return 0;
}






