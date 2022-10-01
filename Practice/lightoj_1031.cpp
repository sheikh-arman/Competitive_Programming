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
ll mem[110][110];
vector<ll>V;
ll dp(ll l, ll r,ll st)
{
    if(l>r)return 0;
    if(mem[l][r]!=-1)return mem[l][r];
    ll ans=0,sum=0;
    if(st==0)
    {
        for(ll i=l; i<=r; i++)
        {
            sum+=V[i];
            ll tm=sum-dp(i+1,r,0);
            ans=max(ans,tm);
        }
        sum=0;
        for(ll i=l; i>=r; i--)
        {
            sum+=V[i];
            ll tm=sum-dp(l,i-1,0);
            ans=max(ans,tm);
        }
    }
//    else
//    {
//        for(ll i=l; i<=r; i++)
//        {
//            sum+=V[i];
//            ll tm=sum-dp(i+1,r,0);
//            ans=max(ans,tm);
//        }
//        sum=0;
//        for(ll i=l; i>=r; i--)
//        {
//            sum+=V[i];
//            ll tm=sum-dp(l,i-1,0);
//            ans=max(ans,tm);
//        }
//    }
    return mem[l][r]=ans;
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
        ll n,sum=0;
        cin>>n;
        V.clear();
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=n; j++)
            {
                mem[i][j]=-1;
            }
        }
        ll ans=dp(0,n-1,0);
        cout<<ans<<"\n";
    }
    return 0;
}






