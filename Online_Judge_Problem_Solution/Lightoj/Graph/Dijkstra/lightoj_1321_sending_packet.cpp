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
double dis[110];
//double probability[110];
vector<pair<ll,ll>>edj[110];
ll dijkstra(ll source)
{
    for(ll i=0; i<=100; i++)
    {
        dis[i]=0;
    }
    dis[source]=1;
    priority_queue< pair<double,ll> >pq;
    pq.push({1,source});
    while(!pq.empty())
    {
        pair<double,ll>tp=pq.top();
        pq.pop();
        ll node=tp.second;
        for(auto i:edj[node])
        {
            ll child=i.first;
            double cost=i.second/100.0;
            if(dis[node]*cost>dis[child])
            {
                dis[child]=dis[node]*cost;
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
        ll n,m,s,k;
        cin>>n>>m>>s>>k;
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            edj[u].PB({v,w});
            edj[v].PB({u,w});
        }
        dijkstra(0);
        double ans=(double)s/dis[n-1];
        ans*=(k*2);
        cout<<fixed<<setprecision(10)<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}






