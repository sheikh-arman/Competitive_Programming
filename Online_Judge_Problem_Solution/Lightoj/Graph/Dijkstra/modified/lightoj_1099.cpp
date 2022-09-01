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
ll prothom[5010];
ll ditio[5010];
ll n;
vector<pair< ll,ll >>edj[5010];
void dijkstra(ll source)
{
    priority_queue< pair<pair<ll,ll>,ll>, vector< pair<pair<ll,ll>,ll>>, greater< pair<pair<ll,ll>,ll>> >pq;
    pq.push({{0,0},source});
    for(int i=0; i<=n; i++)
    {
        prothom[i]=LONG_MAX;
        ditio[i]=LONG_MAX;
    }
    while(!pq.empty())
    {
        pair<pair<ll,ll>,ll> pa=pq.top();
        pq.pop();
        ll node=pa.second;
        ll cost1=pa.first.first;
        ll cost2=pa.first.second;
        // cout<<node<<" "<<cost1<<" "<<cost2<<" ttt\n";
        for(auto i:edj[node])
        {
            ll child=i.first;
            ll cst=i.second;
            //cout<<child<<" "<<prothom[child]<<" "<<cst+cost1<<" "<<ditio[child]<<" ck\n";
            if(prothom[child]>cost1+cst)
            {
                ditio[child]=prothom[child];
                prothom[child]=cost1+cst;
                // cout<<child<<" "<<prothom[child]<<" "<<ditio[child]<<" pro\n";
                pq.push({{prothom[child],ditio[child]},child});
            }
            else if(prothom[child]<cost1+cst&&cost1+cst<ditio[child])
            {
                ditio[child]=cost1+cst;
                //cout<<child<<" "<<prothom[child]<<" "<<ditio[child]<<" di\n";
                pq.push({{prothom[child],ditio[child]},child});
            }
            if(prothom[child]<cost2+cst&&cost2+cst<ditio[child])
            {
                ditio[child]=cost2+cst;
                pq.push({{prothom[child],ditio[child]},child});
            }
        }

    }
}
int main()
{
   // freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll m;
        cin>>n>>m;
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
        dijkstra(1);
        if(n==1)ditio[n]=prothom[n];
        cout<<"Case "<<test<<": "<<ditio[n]<<"\n";
    }
    return 0;
}
