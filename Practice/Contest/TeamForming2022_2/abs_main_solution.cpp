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

#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 30010
int ar[N];
int start[N];
int en[N];
int lvl[N];
int sparse[N][20];
ll cnt,n;
int bit_cnt[200010];
ll bit[200010];
vector<ll>edj[N];
int flat[2*N];
bool stat[2*N];
void update(ll index,ll value)
{

    while(index<=200000)
    {
        bit[index]+=value;
        index+=(index & -index);
    }
}
ll query(ll index)
{
    ll value=0;
    while(index>0)
    {
        value+=bit[index];

        index-=(index&-index);
    }
    return value;
}
void update_cnt(ll index,ll value)
{
    while(index<=200000)
    {
        bit_cnt[index]+=value;
        index+=(index & -index);
    }
}
ll query_cnt(ll index)
{
    ll value=0;
    while(index>0)
    {
        value+=bit_cnt[index];
        index-=(index&-index);
    }
    return value;
}
ll ck=0;
void dfs(ll node,ll parent)
{
    ck++;
    if(ck>30000)return;
    //flat[cnt]=node;
    //start[node]=cnt++;
    for(ll i:edj[node])
    {
        if(parent!=i)
        {
            lvl[i]=lvl[node]+1;
            sparse[i][0]=node;
            cout<<node<<" "<<i<<" "<<parent<<" x\n";
            dfs(i,node);
        }
    }
   // flat[cnt]=node;
    //en[node]=cnt++;
}
void init()
{
    for(ll j=1; j<=17; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];
        }
    }
}
ll lca(ll u,ll v)
{
    if(lvl[u]<lvl[v])
        swap(u,v);
    ll lg=0;
    for(lg=0; (1<<lg)<=lvl[u]; lg++)
    {

    }
    lg--;
    if(lvl[u]!=lvl[v])
    {
        for(ll i=lg; i>=0; i--)
        {
            if(lvl[u]-(1<<i)>=lvl[v])
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
    return sparse[u][0];
}
ll k;
bool cmp(pair<pair<ll,ll>,pair<ll,ll> >a, pair< pair<ll,ll>,pair<ll,ll> > b)
{
    int block_a = a.first.first / k, block_b = b.first.first / k;
    if(block_a == block_b) return a.first.second < b.first.second;
    return block_a < block_b;
}
ll l = 1, r = 0, sum = 0, ans[10],total_cnt=0;
void Add(int x)
{
    ll node=flat[x];
    ll value=ar[node];
    if(stat[node]==0)
    {
        total_cnt+=1;
        sum+=value;
        update(value,value);
        update_cnt(value,1);
        stat[node]=1;
    }
    else
    {
        total_cnt-=1;
        sum-=value;
        update(value,-value);
        update_cnt(value,-1);
        stat[node]=0;
    }
}
void Remove( int x)
{
    ll node=flat[x];
    ll value=ar[node];
    if(stat[node]==0)
    {
        total_cnt+=1;
        sum+=value;
        update(value,value);
        update_cnt(value,1);
        stat[node]=1;
    }
    else
    {
        total_cnt-=1;
        sum-=value;
        update(value,-value);
        update_cnt(value,-1);
        stat[node]=0;
    }
}
int rep[N+10];
ll Find(ll node)
{
    return (rep[node]=node?node:rep[node]=Find(rep[node]));
}
vector< pair<pair<int,int>,pair<int,int> > >V;
int main()
{
    freopen("input12.txt","r",stdin);
    //freopen("output12.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cnt=1;
        cin>>n;
        for(ll i=0; i<=n; i++)rep[i]=i;
        assert(1<=n&&n<=100000);
        k=sqrt(2*n);
        for(int i=0; i<=n+1; i++)
        {
            edj[i].clear();
            memset(sparse[i],-1,sizeof(sparse[i]));
        }
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
            assert(1<=ar[i]&&ar[i]<=200000);
        }
        for(ll i=0; i<n-1; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
            //assert(Find(u)!=Find(v));
            rep[Find(u)]=Find(v);
        }
        lvl[1]=0;
        dfs(1,-1);
        sparse[1][0]=1;
        //init();
        V.clear();
        ll q;
        cin>>q;
        //q=1;
        for(ll i=0; i<q; i++)
        {
            ll u,v,x;
            cin>>u>>v>>x;

//            ll lc=lca(u,v);
//            if(start[v]<start[u])swap(v,u);
//            if(lc==u)
//            {
//                V.PB({{start[u],start[v]},{x,i}});
//            }
//            else
//            {
//                ans[i]+=abs(x-ar[lc]);
//                V.PB({{en[u],start[v]},{x,i}});
//            }
        }
        sort(V.begin(),V.end(), cmp);
        //        for(int i = 0; i < 0; i++)
//        {
//            while(l > V[i].first.first)
//            {
//                Add(--l);
//            }
//            while(r < V[i].first.second)
//            {
//                Add(++r);
//            }
//            while(l < V[i].first.first)
//            {
//                Remove(l++);
//            }
//            while(r > V[i].first.second)
//            {
//                Remove(r--);
//            }
//            ll x=V[i].second.first;
//            ll res=query(x);
//            ll res_cnt=query_cnt(x);
//            ll result=x*res_cnt;
//            result-=res;
//            res=sum-res;
//            res_cnt=total_cnt-res_cnt;
//            result+=res-(res_cnt*x);
//
//            ans[V[i].second.second]+=result;
//        }
//        for(ll i=0; i<q; i++)
//        {
//            cout<<ans[i]<<"\n";
//        }
        cout<<"x\n";
    }
    return 0;
}







