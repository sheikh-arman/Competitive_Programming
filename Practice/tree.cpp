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
ll ans=0,total=0;
vector< pair< pair<ll,ll>,ll > >edj[200010];
ll cnt_node[200010];
bitset<200010>color,color2;
ll mod=1e9+7;
void dfs(ll node)
{
    color[node]=true;
    cnt_node[node]=1;
    for(auto i:edj[node])
    {
        ll child=i.first.first;
        ll type=i.first.second;
        ll w=i.second;
        if(type==1)
        {
            if(color[child]==false)
            {
                color[child]=true;
                dfs(child);
                cnt_node[node]+=cnt_node[child];
            }
        }
    }
}
void dfs2(ll node)
{
    color2[node]=true;
    for(auto i:edj[node])
    {
        ll child=i.first.first;
        ll type=i.first.second;
        ll w=i.second;
        if(type==1)
        {
            if(color2[child]==false)
            {
                color2[child]=true;
                ll val1=total-cnt_node[child];
                ll val2=cnt_node[child];
                ans+=((val2*val1)%mod)*w;
                ans%=mod;
                dfs2(child);
            }
        }
    }
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
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            color[i]=0;
            color2[i]=0;
        }
        for(ll i=1; i<n; i++)
        {
            ll a,b,type,w;
            cin>>a>>b>>type>>w;
            edj[a].PB({{b,type},w});
            edj[b].PB({{a,type},w});
        }
        ans=0;
        for(ll i=1; i<=n; i++)
        {
            if(color[i]==false)
            {

                dfs(i);
                total=cnt_node[i];
                dfs2(i);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}





