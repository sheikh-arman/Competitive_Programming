/*
    Sk arman Hossain
    University of Barisal

    Problem : Second Minimum Spanning Tree
    Solution : Kruskal + LCA
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200010
ll rep[N];
ll Find(ll node)
{
    return (rep[node]==node?node:rep[node]=Find(rep[node]));
}
vector<pair<pair<ll,ll>,pair<ll,ll> > > V;
vector<pair<pair<ll,ll>,pair<ll,ll> > > unvisited_edge;
vector< pair<ll,ll> >edj[N];
ll ar[N],label[N];
ll sparse[N][22];
ll mx[N][22];
bitset<N>color;
void dfs(ll n)
{
    color[n]=true;
    ll siz=edj[n].size();
    for(ll i=0; i<siz; i++)
    {
        ll child=edj[n][i].first;
        if(color[child]==false)
        {
            label[child]=label[n]+1;
            color[child]=true;
            sparse[child][0]=n;
            mx[child][0]=edj[n][i].second;
            //cout<<sparse[child][0]<<" "<<mx[child][0]<<" x\n";
            dfs(child);
        }
    }
}
void lca(ll n)
{
    for(ll i=0; i<=n; i++)
    {
        color[i]=false;
        for(ll j=0; (1<<j)<=n; j++)
        {
            sparse[i][j]=-1;
            mx[i][j]=-1;
        }
    }
    label[1]=0;
    sparse[1][0]=1;
    dfs(1);
    for(ll j=1; (1<<j)<=n; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];
            mx[i][j]=max(mx[sparse[i][j-1]][j-1],mx[i][j-1]);
        }
    }
}
ll query(ll u,ll v)
{
    if(label[u]<label[v])swap(u,v);
    ll ma=mx[u][0];
    ll lg;
    for(lg=0; (1<<lg)<=label[u]; lg++);
    lg--;
    if(label[u]!=label[v])
    {
        for(ll i=lg; i>=0; i--)
        {
            if(label[u]-(1<<i)>=label[v])
            {
                ma=max(ma,mx[u][i]);
                u=sparse[u][i];

            }
        }
    }
    if(u==v)
    {
        return ma;
    }
    if(u!=v)
    {
        for(ll i=lg; i>=0; i--)
        {
            if(sparse[u][i]!=-1&&sparse[u][i]!=sparse[v][i])
            {
                ma=max(ma,mx[u][i]);
                ma=max(ma,mx[v][i]);
                u=sparse[u][i];
                v=sparse[v][i];

            }
        }
    }

    ma=max(ma,mx[u][0]);
    ma=max(ma,mx[v][0]);
    return ma;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,e;
    cin>>n>>e;
    for(ll i=0; i<=n; i++)rep[i]=i;
    for(ll i=0; i<e; i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        V.push_back({{w,u},{v,i}});
    }
    sort(V.begin(),V.end());
    ll sum=0;
    for(ll i=0; i<e; i++)
    {
        ll u=Find(V[i].first.second);
        ll v=Find(V[i].second.first);
        if(u!=v)
        {
            ar[V[i].second.second]=1;
            sum+=V[i].first.first;
            rep[u]=v;
            edj[V[i].first.second].push_back({V[i].second.first,V[i].first.first});
            edj[V[i].second.first].push_back({V[i].first.second,V[i].first.first});
        }
        else
        {
            unvisited_edge.push_back(V[i]);
        }
    }
    lca(n);
    for(ll i=0; i<e; i++)
    {
        if(ar[i]==1)
        {
            ar[i]=sum;
        }
    }
    ll ss=unvisited_edge.size();
    for(ll i=0; i<ss; i++)
    {
        ll tm=query(unvisited_edge[i].first.second,unvisited_edge[i].second.first);
        //cout<<tm<<" te\n";
        ar[unvisited_edge[i].second.second]=sum+(unvisited_edge[i].first.first-tm);
    }
    for(ll i=0; i<e; i++)
    {
        cout<<ar[i]<<"\n";
    }
    return 0;
}




