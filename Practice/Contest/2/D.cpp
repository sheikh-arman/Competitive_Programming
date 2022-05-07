#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
#define MAX 100010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
ll label[MAX+10];
ll parent[MAX+10];
//vector<pair<ll,ll> >dijkstra_edj[max_array_size];
ll shortest_weight[MAX+10];
vector<ll>edj[MAX+10];
void dijkstra(ll start, ll node_size)
{
    for(ll i=0; i<=node_size; i++)
    {
        shortest_weight[i]=LONG_LONG_MAX;
    }
    priority_queue< pair<ll,ll>, vector<pair<ll,ll>>,greater<pair<ll,ll> > >pq;
    pq.push({label[start], start});
    shortest_weight[start]=0;
    while(!pq.empty())
    {
        pair<ll,ll> current_node=pq.top();
        pq.pop();
        ll node=current_node.second;
        ll siz=edj[node].size();
        for(ll i=0; i<siz; i++)
        {
            ll child=edj[node][i];
            ll weight=1;
            if(shortest_weight[child]>shortest_weight[node]+weight)
            {
                shortest_weight[child]=shortest_weight[node]+weight;
                parent[child]=node;
                pq.push({label[child],child});
            }
        }
    }
}
void bfs(ll start)
{
    label[start]=0;
    queue<ll>qu;
    qu.push(start);
    while(!qu.empty())
    {
        ll node=qu.front();
        qu.pop();
        for(ll i:edj[node])
        {
            if(label[i]==-1)
            {
                label[i]=label[node]+1;
                qu.push(i);
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
    //scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            label[i]=-1;
            edj[i].clear();
            label[i]=-1;
            parent[i]=-1;
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        ll temp=0;
        ll A,B,C;
        cin>>A>>B>>C;
        bfs(C);
        temp=label[A]+label[B];
        //cout<<temp<<" x\n";
        parent[A]=-1;
        dijkstra(A,n);
        ll ans=shortest_weight[B];
        ll mi=LONG_MAX;
        ll node=B;
        //cout<<ans<<" f\n";
        while(node!=-1)
        {
            // cout<<node<<" "<<label[node]<<" test\n";
            mi=min(mi,label[node]);
            node=parent[node];
        }
        // mi=min(mi,label[node]);
        //cout<<mi<<" x\n";
//        for(ll i=0; i<=n; i++)
//        {
//            label[i]=-1;
//        }
//        bfs(C);
//        mi=min(mi,label[B]);
        ans=min(ans+mi,temp);
        cout<<ans<<"\n";
    }
    return 0;
}




