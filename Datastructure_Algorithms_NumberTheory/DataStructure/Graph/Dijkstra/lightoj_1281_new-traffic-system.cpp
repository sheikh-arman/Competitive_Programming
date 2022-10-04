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
ll n,d;
ll dis[10010][12];
vector<pair<pair<ll,ll>,ll>>edj[1010];
void dijkstra(ll source)
{
    for(ll i=0; i<=10000; i++)
    {
        for(ll j=0; j<=d; j++)
        {
            dis[i][j]=INT_MAX;
        }
    }
    dis[source][0]=0;
    priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater< pair<ll,ll> > >pq;
    pq.push({0,source});
    while(!pq.empty())
    {
        //ll cost=pq.top().first;
        ll node=pq.top().second;
        pq.pop();
        ll siz=edj[node].size();
        for(ll j=0; j<=d; j++)
        {
            if(dis[node][j]==INT_MAX)continue;
            for(ll i=0; i<siz; i++)
            {
                ll child=edj[node][i].first.first;
                ll cost=edj[node][i].first.second;
                ll type=edj[node][i].second;
                if(dis[node][j]+cost<dis[child][j+type]&&dis[node][j]+cost<dis[child][j])
                {
                    dis[child][j+type]=dis[node][j]+cost;
                    if(j+type<=d)
                    {
                        pq.push({dis[child][j+type],child});
                    }
                }
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
        ll k,m;
        cin>>n>>m>>k>>d;
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            edj[u].PB({{v,w},0});
        }
        for(ll i=0; i<k; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            edj[u].PB({{v,w},1});
        }
        dijkstra(0);
        ll ans=INT_MAX;
        for(ll i=0; i<=d; i++)
        {
            ans=min(ans,dis[n-1][i]);
        }
        if(ans>=INT_MAX)
        {
            cout<<"Case "<<test<<": Impossible\n";
        }
        else
        {
            cout<<"Case "<<test<<": "<<ans<<"\n";
        }
    }
    return 0;
}





