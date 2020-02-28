
/*
    Sk arman Hossain
    University of Barisal

    Problem name : uva p12655 Trucks
    Algorithm : MST + LCA(sparse table)
 */
#include<bits/stdc++.h>
#define nl printf("\n");
#define PR pair<ll,ll>
#define sf1(n) scanf("%lld", &n)
#define sf2(n, m) scanf("%lld %lld",&n,&m)
#define sf3(n, m,k ) scanf("%lld %lld %lld",&n,&m,&k)
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
#define minus1 printf("-1\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
typedef long long int ll;
typedef unsigned long long int ull;
ll dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
ll dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
using namespace std;
#define N 100110
vector<PR>edj[N];
vector< pair<PR,ll> >edge;
bool color[N];
ll label[N];
ll distance[N];
ll sparse[N][25];
ll MIN[N][25];
ll parent[N],mst;
void dfs(ll node)
{
    color[node]=false;
    ll siz=edj[node].size();
    for(ll i=0; i<siz; i++)
    {
        ll tm=edj[node][i].ff;
        if(color[tm]==true)
        {
            color[tm]=false;
            label[tm]=label[node]+1;
            parent[tm]=edj[node][i].ss;
            MIN[tm][0]=edj[node][i].ss;
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
            MIN[i][j]=min(MIN[i][j-1],MIN[sparse[i][j-1]][j-1]);
        }
    }
}
ll mi=LONG_MAX,ma=-1;
void query(ll u,ll v)
{
    if(label[u]<label[v])
        swap(u,v);
    mi=parent[u];
    ll lg=0;
    for(lg=0; (1<<lg)<=label[u]; lg++)
    {

    }
    lg--;
    if(label[u]!=label[v])
    {
        for(ll i=lg; i>=0; i--)
        {
            if(label[u]-(1<<i)>=label[v])
            {
                mi=min(mi,MIN[u][i]);
                u=sparse[u][i];
            }
        }
    }
    if(u!=v)
    {
        for(ll i=lg; i>=0; i--)
        {
            if(sparse[u][i]!=-1&&sparse[u][i]!=sparse[v][i])
            {

                mi=min(mi,MIN[u][i]);
                mi=min(mi,MIN[v][i]);
                u=sparse[u][i];
                v=sparse[v][i];
            }
        }
        mi=min(mi,parent[u]);
        mi=min(mi,parent[v]);
    }
}
ll rep[N];
ll find_representative(ll n)
{
    if(rep[n]==n)
    {
        return rep[n];
    }
    else
    {
        return rep[n]=find_representative(rep[n]);
    }
}
void joint(ll p,ll q)
{
    ll u=find_representative(p);
    ll v=find_representative(q);
    rep[u]=v;
}
void MST(ll n,ll e)
{
    for(ll i=0; i<=n; i++)
    {
        rep[i]=i;
    }
    for(ll i=e-1; i>=0; i--)
    {
        if(find_representative(edge[i].ff.ss)!=find_representative(edge[i].ss))
        {
            joint(edge[i].ff.ss,edge[i].ss);
            edj[edge[i].ff.ss].PB({edge[i].ss,edge[i].ff.ff});
            edj[edge[i].ss].PB({edge[i].ff.ss,edge[i].ff.ff});
            mst++;
        }
    }
}
int main()
{

    // fast;
    //freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;ll n,e,m,qq;
    //sf1(tcase);
    while(sf3(n,e,qq)!=EOF)
    {
        edge.clear();
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            color[i]=true;
            label[i]=-1;
            for(ll j=0; j<22; j++)
            {
                sparse[i][j]=-1;
                MIN[i][j]=LONG_MAX;
            }
        }
        for(ll i=0; i<e; i++)
        {
            ll u,v,w;
            sf3(u,v,w);
            edge.PB({{w,u},v});
        }
        VST(edge);
        mst=0;
        MST(n,e);
        label[1]=0;
        parent[1]=1;
        dfs(1);
        pre_process(n);
        for(ll i=0; i<qq; i++)
        {
            ll u,v;
            mi=LONG_MAX;
            ma=-1;
            sf2(u,v);
            query(u,v);
            printf("%lld\n",mi);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


