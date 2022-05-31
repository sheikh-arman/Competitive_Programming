merge(seg[left].begin(), seg[left].end(), seg[right].begin(), seg[right].end(),back_inserter(seg[n]));
#define N 200100
vector<ll>edj[N];
bool color[N];
ll label[N];
ll sparse[N][20];
ll parent[N];
void dfs(ll node)
{
    color[node]=false;
    ll siz=edj[node].size();
    for(ll i=0; i<siz; i++)
    {
        ll tm=edj[node][i];
        if(color[tm]==true)
        {
            color[tm]=false;
            label[tm]=label[node]+1;
            parent[tm]=node;
            sparse[tm][0]=node;
            dfs(tm);
        }
    }
}
void pre_process(ll n)
{
    for(ll j=1; (1<<j)<=n; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];
        }
    }
}
ll query(ll u,ll v)
{
    if(label[u]<label[v])swap(u,v);
    ll lg=0;
    for(lg=0; (1<<lg)<=label[u]; lg++);
    lg--;
    if(label[u]!=label[v])
    {
        for(ll i=lg; i>=0; i--)
        {
            if(label[u]-(1<<i)>=label[v])
            {
                u=sparse[u][i];
            }
        }
    }
    if(u==v)
    {
        return u;
    }
    for(ll i=lg; i>=0; i--)
    {
        if(sparse[u][i]!=-1&&sparse[u][i]!=sparse[v][i])
        {
            u=sparse[u][i];
            v=sparse[v][i];
        }
    }
    return parent[u];
}
ll nth_parent(ll u,ll nth)
{
    ll lg=0;
    for(lg=0; (1<<lg)<=label[u]; lg++);
    lg--;
    ll nth_parent_label=nth;
    if(label[u]!=nth_parent_label)
    {
        for(ll i=lg; i>=0; i--)
        {
            if(label[u]-(1<<i)>=nth_parent_label)
            {
                u=sparse[u][i];
            }
        }
    }
    return u;
}
