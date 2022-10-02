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
ll parent[1010],last;
vector<pair<ll,pair<ll,ll>> >V;
vector<pair<ll,ll>>edj[1010];
bitset<1010>color;
vector<ll>node_list;
bool bellman(ll source,ll n,ll m)
{
    for(ll i=0; i<n; i++)
    {
        weight[node_list[i]]=INT_MAX;
    }
    weight[source]=0;
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
            if(weight[u]<INT_MAX)
            {
                if(weight[u]+w<weight[v])
                {
                    weight[v]=weight[u]+w;
                    parent[v]=u;
                    cc=0;
                }
            }
        }
        if(cc==1)
        {
            return 1;
        }
    }
    return 0;
}
stack<ll>stk;
void dfs(ll node)
{
    color[node]=true;
    for(auto i:edj[node])
    {
        if(color[i.first]==false)
        {
            color[i.first]=true;
            dfs(i.first);
        }
    }
    stk.push(node);
}
void go(ll node)
{
    node_list.PB(node);
    color[node]=true;
    for(auto i:edj[node])
    {
        if(color[i.first]==false)
        {
            color[i.first]=true;
            go(i.first);
        }
    }

}
int main()
{
    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);
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
            edj[u].PB({v,w});
        }
        for(ll i=0; i<n; i++)
        {
            if(color[i]==false)
            {
                dfs(i);
            }
        }
        for(ll i=0; i<n; i++)
        {
            color[i]=0;
        }
        ll ans=1;
        while(!stk.empty())
        {
            ll i=stk.top();
            stk.pop();
            if(color[i]==false)
            {
                node_list.clear();
                go(i);
                V.clear();
                for(ll j:node_list)
                {
                    ll siz=edj[j].size();
                    for(ll k=0; k<siz; k++)
                    {
                        V.PB({edj[j][k].second,{j,edj[j][k].first}});
                    }
                }
                ll siz=node_list.size();
                if(siz>1)
                {
                    bool hi=bellman(i,siz,V.size());
                   // cout<<siz<<" : "<<hi<<" "<<i<<" t\n";
//                    for(ll j:node_list){
//                        cout<<j<<" ";
//                    }
//                    cout<<" fu\n";
                    if(hi==0)
                    {
                        cout<<"Case "<<test<<": ";
                        VST(node_list);
                        for(ll x=0; x<siz; x++)
                        {
                            if(x>0)cout<<" ";
                            cout<<node_list[x];
                        }
                        cout<<"\n";
                        ans=0;
                        break;
                    }
                }

            }
        }
        if(ans)
        {
            cout<<"Case "<<test<<": impossible\n";
        }
    }
    return 0;
}
