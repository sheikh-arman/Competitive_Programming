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
ll weight[1010];
vector<pair<ll,pair<ll,ll>> >V;
vector<ll>edj[1010];
bitset<1010>color;
vector<ll>node_list;
void go(ll node)
{
    node_list.PB(node);
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            go(i);
        }
    }
}
bool bellman(ll n,ll m)
{
    for(ll i=0; i<=n; i++)
    {
        weight[i]=INT_MAX;
    }
    bool ck=0;
    for(ll i=0; i<n; i++)
    {
        ll cc=1;
        for(ll j=0; j<m; j++)
        {
            pair<ll,pair<ll,ll>> pa=V[j];
            ll w=pa.first;
            ll u=pa.second.first;
            ll v=pa.second.second;
            if(weight[v]+w<weight[u])
            {
                weight[u]=weight[v]+w;
                cc=0;
            }
        }
        if(cc==1)
        {
            return 1;
        }
    }
    node_list.clear();
    for(ll j=0; j<m; j++)
    {
        pair<ll,pair<ll,ll>> pa=V[j];
        ll w=pa.first;
        ll u=pa.second.first;
        ll v=pa.second.second;
        if(weight[v]+w<weight[u])
        {
            weight[u]=weight[v]+w;
            if(color[u]==false)
            {
                go(u);
            }
        }
    }
    return 0;
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
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            color[i]=0;
        }
        for(int i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            edj[v].PB(u);
            V.PB({w,{u,v}});
        }
        ll ans=bellman(n,m);
        if(ans)
        {
            cout<<"Case "<<test<<": impossible\n";
        }
        else
        {
            cout<<"Case "<<test<<": ";
            VST(node_list);
            ll siz=node_list.size();
            for(ll i=0; i<siz; i++)
            {
                if(i>0)cout<<" ";
                cout<<node_list[i];
            }
            cout<<"\n";
        }
    }
    return 0;
}
