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
ll cnt_gcd[300010];
ll ar[300010];
bitset<300010>color;
vector<ll>edj[300010];
void dp_dfs(ll node)
{
    color[node]=true;
    ll gcd=ar[node];
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dp_dfs(i);
            gcd=__gcd(gcd,cnt_gcd[i]);
        }
    }
    cnt_gcd[node]=gcd;
}
ll ans=0,res=0;
void dfs_backtrack(ll node,ll parent)
{
    color[node]=false;
    ans-=cnt_gcd[node];
    for(ll i:edj[node])
    {
        if(i!=parent)
        ans+=cnt_gcd[i];
    }
    res=max(res,ans);
    for(ll i:edj[node])
    {
        if(color[i]==true)
        {
            color[i]=false;
            dfs_backtrack(i,node);
        }
    }
    ans+=cnt_gcd[node];
    for(ll i:edj[node])
    {
        if(i!=parent)
        ans-=cnt_gcd[i];
    }
    //res=max(res,ans);
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
        ll n;
        cin>>n;
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
            color[i]=false;
            edj[i].clear();
        }
        for(ll i=0; i<n-1; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        res=0;
        dp_dfs(1);
        ans=cnt_gcd[1];
        dfs_backtrack(1,1);
        cout<<res<<"\n";
    }
    return 0;
}





