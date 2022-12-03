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
ll dis[110][110],n,capacity;
ll ar[110];
vector<pair<ll,ll>>edj[110];
void dijkstra(ll source,ll d)
{
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=capacity; j++)
        {
            dis[i][j]=INT_MAX;
        }
    }
    priority_queue<pair<pair<ll,ll>,ll>, vector<pair<pair<ll,ll>,ll> >, greater<pair<pair<ll,ll>,ll>> >pq;
    dis[source][0]=0;
    pq.push({{0,source},0});
    while(!pq.empty())
    {
        pair<pair<ll,ll>,ll> tp=pq.top();
        pq.pop();
        ll node=tp.first.second;
        ll fuel=tp.second;
        //cout<<tp.first.first<<" "<<node<<" "<<fuel<<" x\n";
        if(node==d)continue;
        for(auto i:edj[node])
        {
            ll child=i.first;
            ll cost=i.second;
            if(fuel>=cost)
            {
                if(dis[child][fuel-cost]>dis[node][fuel])
                {
                    dis[child][fuel-cost]=dis[node][fuel];
                    pq.push({{dis[child][fuel-cost],child},fuel-cost});
                }
            }
        }
        if(fuel+1<=capacity)
        {
            if(dis[node][fuel]+ar[node]<dis[node][fuel+1])
            {
                dis[node][fuel+1]=dis[node][fuel]+ar[node];
                pq.push({{dis[node][fuel+1],node},fuel+1});
            }
        }
    }
}
int main()
{
    //freopen("1inputi.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll m;
        cin>>n>>m;
        for(ll i=0; i<n; i++)
        {
            cin>>ar[i];
            edj[i].clear();
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            edj[u].PB({v,w});
            edj[v].PB({u,w});
        }
        ll q;
        cin>>q;
        cout<<"Case "<<test<<":\n";
        for(ll i=0; i<q; i++)
        {
            ll s,d;
            cin>>capacity>>s>>d;
            dijkstra(s,d);
            ll ans=INT_MAX;
            for(ll j=0; j<=capacity; j++)
            {
                ans=min(ans,dis[d][j]);
            }
            if(ans==INT_MAX)
            {
                cout<<"impossible\n";
            }
            else
            {
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}





