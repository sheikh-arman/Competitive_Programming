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
ll dis[10010];
ll dis_destination[10010];
vector<pair<ll,ll>>edj[10010],rev_edj[10010];
void dijkstra(ll source)
{
    for(ll i=0; i<=10000; i++)
    {
        dis[i]=INT_MAX;
    }
    priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, greater< pair<ll,ll> > >pq;
    pq.push({0,source});
    dis[source]=0;
    while(!pq.empty())
    {
        pair<ll,ll> pa=pq.top();
        pq.pop();
        ll node=pa.second;
        for(auto i:edj[node])
        {
            ll child=i.first;
            ll cost=i.second;
            if(dis[node]+cost<dis[child])
            {
                dis[child]=dis[node]+cost;
                pq.push({dis[child],child});
            }
        }
    }
}
void dijkstra_distination(ll source)
{
    for(ll i=0; i<=10000; i++)
    {
        dis[i]=INT_MAX;
    }
    priority_queue< pair<ll,ll>,vector< pair<ll,ll> >,greater< pair<ll,ll> > >pq;
    pq.push({0,source});
    dis[source]=0;
    while(!pq.empty())
    {
        pair<ll,ll> pa=pq.top();
        pq.pop();
        ll node=pa.second;
        for(auto i:rev_edj[node])
        {
            ll child=i.first;
            ll cost=i.second;
            if(dis[node]+cost<dis[child])
            {
                dis[child]=dis[node]+cost;
                pq.push({dis[child],child});
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
        ll n,m,s,t,val;
        cin>>n>>m>>s>>t>>val;
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            rev_edj[i].clear();
        }
        vector< pair<pair<ll,ll>,ll> >V;
        for(ll i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            V.PB({{u,v},w});
            edj[u].PB({v,w});
            rev_edj[v].PB({u,w});
        }
        dijkstra_distination(t);
        for(ll i=0; i<=n; i++)
        {
            dis_destination[i]=dis[i];
        }
        dijkstra(s);
        ll ans=-1;
        for(ll i=0; i<m; i++)
        {
            ll u=V[i].first.first;
            ll v=V[i].first.second;
            ll w=V[i].second;
            if(dis[u]+dis_destination[v]+w<=val)
            {
                ans=max(ans,w);
            }
        }
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}





