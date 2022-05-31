#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
//DFS

ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
#define max_array_size 200010
vector<ll>edj[max_array_size];
bitset<max_array_size>color;
/// stack<ll>stk; //uncomment for top sort;
void dfs(ll node)
{
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dfs(i);
        }
    }
    /// stk.push(node);//uncomment for top sort
}
//bfs vector from dfs
void bfs(ll start)
{
    color[start]=true;
    queue<ll>node_list;
    node_list.push(start);
    while(!node_list.empty())
    {
        ll node=node_list.front();
        node_list.pop();
        for(ll i:edj[node])
        {
            if(color[i]==false)
            {
                color[i]=true;
                node_list.push(i);
            }
        }
    }
}
//DSU
ll rep[max_array_size];
ll cnt_node[max_array_size];
ll findRep(ll node)
{
    return rep[node]=(node==rep[node]?node:findRep(rep[node]));
}
void join(ll nodeu, ll nodev)
{
    ll rep_nodeu=findRep(nodeu);
    ll rep_nodev=findRep(nodev);
    if(rep_nodeu!=rep_nodev)
    {
        if(cnt_node[rep_nodeu]<cnt_node[rep_nodev])
        {
            swap(nodeu,nodev);
        }
        cnt_node[nodeu]+=cnt_node[nodev];
        cnt_node[nodev]=0;
        rep[nodev]=nodeu;
    }
}
//mst -> kruskal
vector<pair<ll, pair<ll,ll> >>kruskal_edj;
vector<pair<ll, pair<ll,ll> >>mst;
ll kruskal(ll node_size,ll edge_size)
{
    for(ll i=0; i<=node_size; i++)
    {
        rep[i]=i;
        cnt_node[i]=1;
    }
    sort(kruskal_edj.begin(),kruskal_edj.end());
    ll mst_sum=0;
    for(ll i=0; i<edge_size; i++)
    {
        ll u=kruskal_edj[i].second.first;
        ll v=kruskal_edj[i].second.second;
        u=findRep(u);
        v=findRep(v);
        if(u!=v)
        {
            if(cnt_node[u]<cnt_node[v])
            {
                swap(u,v);
            }
            cnt_node[u]+=cnt_node[v];
            cnt_node[v]=0;
            rep[v]=u;
            mst.PB(kruskal_edj[i]);
            mst_sum+=kruskal_edj[i].first;
        }
    }
}
//dijkstra OK
vector<pair<ll,ll> >dijkstra_edj[max_array_size];
ll shortest_weight[max_array_size];
void dijkstra(ll start, ll node_size)
{
    for(ll i=0; i<=node_size; i++)
    {
        shortest_weight[i]=LONG_LONG_MAX;
    }
    priority_queue< pair<ll,ll>, vector<pair<ll,ll>>,greater<pair<ll,ll> > >pq;
    pq.push({0, start});
    shortest_weight[start]=0;
    while(!pq.empty())
    {
        pair<ll,ll> current_node=pq.top();
        pq.pop();

        ll node=current_node.second;
        ll siz=dijkstra_edj[node].size();
        for(ll i=0; i<siz; i++)
        {
            ll child=dijkstra_edj[node][i].first;
            ll weight=dijkstra_edj[node][i].second;
            if(shortest_weight[child]>shortest_weight[node]+weight)
            {
                shortest_weight[child]=shortest_weight[node]+weight;
                pq.push({shortest_weight[child],child});
            }
        }
    }
}
//floyed warshal
ll floyed_weight[1010][1010];
#define INF 1000000000000000
void floyed(ll node)
{
    for (ll k = 1; k <=node; k++)
    {
        for (ll i = 1; i <= node; i++)
        {
            for (ll j = 1; j <= node; j++)
            {
                if (floyed_weight[i][j] > (floyed_weight[i][k] + floyed_weight[k][j])
                        && (floyed_weight[k][j] != INF
                            && floyed_weight[i][k] != INF))
                {
                    floyed_weight[i][j] = floyed_weight[i][k] + floyed_weight[k][j];
                }
            }
        }
    }
}
/// Articulation Point
vector<ll>edj[10010];
ll start[10010];
ll en[10010],cnt;
bitset<10010>color,ap;
void dfs_ap(ll node,ll parent)
{
    ll child=0;
    start[node]=cnt;
    en[node]=cnt++;
    ll siz=edj[node].size();
    color[node]=true;
    for(ll i=0; i<siz; i++)
    {
        ll tm=edj[node][i];
        if(color[tm]==false)
        {
            child++;
            color[tm]=true;
            dfs_ap(tm,node);
            en[node]=min(en[tm],en[node]);
            if (parent == -1 && child > 1)
            {
                ap[node] = true;
            }
            if(parent != -1&& start[node]<=en[tm])
            {
                ap[node]=true;
            }
        }
        else if(tm!=parent)
        {
            en[node]=min(start[tm],en[node]);
        }
    }
}
/// bridge
vector<ll>edj[100010];
vector<pair<ll,ll>>V;
bitset<100010>color;
ll start[100010],en[100010];
ll cnt;
void bridge(ll node,ll parent){
    color[node]=true;
    start[node]=cnt;
    en[node]=cnt++;
    for(ll i:edj[node]){
        if(color[i]==false){
            color[i]=true;
            bridge(i,node);
            start[node]=min(start[node],start[i]);
            if(en[node]<start[i]){
                    ll a=node,b=i;
            if(a>b)swap(a,b);
                V.push_back({a,b});
            }
        }
        else{
            if(parent!=i)
            start[node]=min(start[node],en[i]);
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
        ll n,sum=0;



    }
    return 0;
}
