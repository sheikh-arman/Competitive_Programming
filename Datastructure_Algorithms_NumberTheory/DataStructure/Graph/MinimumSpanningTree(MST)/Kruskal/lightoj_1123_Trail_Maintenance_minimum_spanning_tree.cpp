/*
    Sk arman Hossain
    University of Barisal
    Problem name : Minimum Spanning Tree editorial
    Solution : Kruskal with DSU
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 2002
#define PB push_back
ll rep[N+10];
ll node_cnt[N+10];
ll path[210];
ll mat[210][210];
ll min_cost;
ll n,m,ck;
vector<ll>edj[210];
ll Find(ll n)
{
    return (rep[n]==n)?n:rep[n]=Find(rep[n]);
}
void dfs(ll node,ll parent)
{
    path[node]=parent;
    for(ll i:edj[node])
    {
        if(i!=parent)
        {
            dfs(i,node);
        }
    }
}
void joint(ll u,ll v,ll val)
{
    ll repu=Find(u);
    ll repv=Find(v);
    if(repu!=repv)
    {
        edj[u].PB(v);
        edj[v].PB(u);
        mat[u][v]=val;
        mat[v][u]=val;
        if(node_cnt[repu]>node_cnt[repv])
        {
            node_cnt[repu]+=node_cnt[repv];
            rep[repv]=repu;
            min_cost+=val;
            if(node_cnt[repu]==n)ck=1;
        }
        else
        {
            node_cnt[repv]+=node_cnt[repu];
            rep[repu]=repv;
            min_cost+=val;
            if(node_cnt[repv]==n)ck=1;
        }
    }
    else
    {
        if(mat[u][v]==INT_MAX)
        {
            dfs(u,-1);
            ll save_u,save_v;
            ll mx=0;
            ll tm_v=v;
            while(path[tm_v]!=-1)
            {
                if(mat[tm_v][path[tm_v]]>mx)
                {
                    mx=mat[tm_v][path[tm_v]];
                    save_u=tm_v;
                    save_v=path[tm_v];
                }
                tm_v=path[tm_v];
            }
            if(mx>val)
            {
                if(save_u>save_v)swap(save_u,save_v);
                min_cost-=mx;
                min_cost+=val;
                mat[u][v]=val;
                mat[v][u]=val;
                mat[save_u][save_v]=INT_MAX;
                mat[save_v][save_u]=INT_MAX;
                edj[u].PB(v);
                edj[v].PB(u);
                ll pos=0;
                ll siz=edj[save_u].size();
                for(ll i=0; i<siz; i++)
                {
                    if(edj[save_u][i]==save_v)
                    {
                        pos=i;
                        break;
                    }
                }
                edj[save_u].erase(edj[save_u].begin()+pos);
                siz=edj[save_v].size();
                for(ll i=0; i<siz; i++)
                {
                    if(edj[save_v][i]==save_u)
                    {
                        pos=i;
                        break;
                    }
                }
                edj[save_v].erase(edj[save_v].begin()+pos);
            }
        }
        else
        {
            if(val<mat[u][v])
            {
                min_cost-=mat[u][v];
                min_cost+=val;
                mat[u][v]=val;
                mat[v][u]=val;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);    cin.tie(0);cout.tie(0);
    // freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        min_cost=0;
        ck=0;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            node_cnt[i]=1;
            rep[i]=i;
            for(ll j=0; j<=n; j++)
            {
                mat[i][j]=INT_MAX;
            }
        }
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
        }
        vector<ll>ans;
        for(ll i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            if(u>v)swap(u,v);
            joint(u,v,w);
            if(ck==0)
            {
                ans.PB(-1);
            }
            else
            {
                ans.PB(min_cost);
            }
        }
        cout<<"Case "<<test<<":\n";
        for(ll i:ans)
        {
            cout<<i<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
