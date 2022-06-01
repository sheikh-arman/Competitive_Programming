/// Merge Sort Tree
merge(seg[left].begin(), seg[left].end(), seg[right].begin(), seg[right].end(),back_inserter(seg[n]));

///LCA
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
/// MOS
#define maxn 31000
int a[maxn],Q,cnt[2001000],k;
struct query
{
    int l, r, id;
} q[2001000];
;
bool cmp(query &a, query &b)
{
    int block_a = a.l / k, block_b = b.l / k;
    if(block_a == block_b) return a.r < b.r;
    return block_a < block_b;
}
int l = 0, r = -1, sum = 0, ans[2001000];
void Add(int x)
{
    x = a[x];
    cnt[x]++;
    if(cnt[x] == 1) sum++;
}
void Remove(int x)
{
    x = a[x];
    cnt[x]--;
    if(cnt[x] == 0) sum--;
}
for(int i = 0; i < Q; i++)
{
    int x,y;
    sff(x,y);
    q[i].l=x-1;
    q[i].r=y-1;
    q[i].id = i;
}
sort(q, q+Q, cmp);
for(int i = 0; i < Q; i++)
{
    while(l > q[i].l) Add(--l);
    while(r < q[i].r) Add(++r);
    while(l < q[i].l) Remove(l++);
    while(r > q[i].r) Remove(r--);
    ans[q[i].id] = sum;
}
for(int i=0; i<Q; i++)
{
    printf("%d\n",ans[i]);
}

/// segment tree with lazy propagation lightoj multiple 3 problem
struct tree
{
    ll mod0,mod1,mod2,prop;
} s_tree[N*4];
ll query(ll n,ll b,ll e,ll i,ll j,ll carry)
{
    if(b>j||e<i)
    {
        return 0;
    }
    if(b>=i&&e<=j)
    {
        carry=carry%3;
        return carry;// dump
    }
    ll l=n*2;
    ll r=(n*2) + 1;
    ll mid=(e+b)/2;
    ll p=query(l,b,mid,i,j,carry+s_tree[n].prop);
    ll q=query(r,mid+1,e,i,j,carry+s_tree[n].prop);
    return p+q;
}
ll update(ll n,ll b,ll e,ll x,ll y)
{
    if(b>y||e<x)
    {
        return 0;
    }
    if(b>=x&&e<=y)
    {
        ll tmp=s_tree[n].mod0;
        s_tree[n].mod0=s_tree[n].mod2;
        s_tree[n].mod2=s_tree[n].mod1;
        s_tree[n].mod1=tmp;
        s_tree[n].prop+=1;
        //s_tree[n].prop=s_tree[n].prop%3;
        return s_tree[n].mod0;
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    update(l,b,mid,x,y);
    update(r,mid+1,e,x,y);
    s_tree[n].mod0=s_tree[l].mod0+s_tree[r].mod0;
    s_tree[n].mod1=s_tree[l].mod1+s_tree[r].mod1;
    s_tree[n].mod2=s_tree[l].mod2+s_tree[r].mod2;
    ll tm=s_tree[n].prop;
    tm%=3;
    if(tm==1)
    {
        ll tmp=s_tree[n].mod0;
        s_tree[n].mod0=s_tree[n].mod2;
        s_tree[n].mod2=s_tree[n].mod1;
        s_tree[n].mod1=tmp;
    }
    else if(tm==2)
    {
        ll tmp=s_tree[n].mod0;
        s_tree[n].mod0=s_tree[n].mod1;
        s_tree[n].mod1=s_tree[n].mod2;
        s_tree[n].mod2=tmp;
    }
    return s_tree[n].mod0;
}


