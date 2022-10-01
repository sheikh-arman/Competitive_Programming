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
ll mem[1010][1010],n;
vector<pair<ll,ll> >V;
ll mod=1e9+7;
ll dp(ll i,ll sum)
{
    if(sum<0)return 0;
    if(i>=n)return 1;
    //cout<<i<<" "<<sum<<" xx\n";

    if(mem[i][sum]!=-1)
    {
        return mem[i][sum];
    }
    ll ans=0;
    ans+=dp(i+1,sum-V[i].second);
    ans%=mod;
    ans+=dp(i+1,sum);
    ans%=mod;
    return mem[i][sum]=ans;
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
    if(a.first!=b.first)return a.first>b.first;
    else return a.first<b.first;
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
        V.clear();
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB({a,0});
        }
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V[i].second=a;
        }
//        VST(V);
//        reverse(V.begin(),V.end());
        sort(V.begin(),V.end(),cmp);
//        for(int i=0;i<n;i++){
//            cout<<V[i].first<<" "<<V[i].second<<" x\n";
//        }
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=n; j++)
            {
                mem[i][j]=-1;
            }
        }
        ll ans=0;
        for(ll i=0; i<n; i++)
        {
            if(V[i].first>=V[i].second)
            {
                ans+=dp(i+1,V[i].first-V[i].second);
                ans%=mod;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}





