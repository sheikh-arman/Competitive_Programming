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
#define N 100010
int ar[N];
int start[N];
int en[N];
int lvl[N];
int sparse[N][20];
ll cnt,n;
vector<ll>edj[N];
void dfs(ll node,ll parent)
{
    start[node]=cnt++;
    for(ll i:edj[node])
    {
        if(parent!=i)
        {
            lvl[i]=lvl[node]+1;
            sparse[i][0]=node;
            dfs(i,node);
        }
    }
    en[node]=cnt++;
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
int main()
{
    freopen("input12.txt","r",stdin);
    freopen("output12.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cnt=1;
        cin>>n;
        for(int i=0; i<=n+1; i++)
        {
            edj[i].clear();
            memset(sparse[i],-1,sizeof(sparse[i]));
        }
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
        }
        for(ll i=0; i<n-1; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        lvl[1]=0;
        dfs(1,-1);
        sparse[1][0]=1;
        init();
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll u,v,x;
            cin>>u>>v>>x;
            ll lc=lca(u,v);
            ll ans=0;
            while(lc!=u)
            {
                ans+=abs(x-ar[u]);
                u=sparse[u][0];
            }
            while(lc!=v)
            {
                ans+=abs(x-ar[v]);
                v=sparse[v][0];
            }
            ans+=abs(x-ar[lc]);
            cout<<ans<<"\n";
        }
    }
    return 0;
}






