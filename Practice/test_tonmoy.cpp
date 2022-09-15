#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

vector<ll> g[10007];
ll time_cnt,disc[10007],low[10007],leaf,chk[10007],vis[10007];
set<ll> cnt;
unsigned ll ans,comp;

void dfs(ll u,ll par)
{
    time_cnt++;
    disc[u]=low[u]=time_cnt;
    ll c=0;

    for(ll i=0; i<g[u].size(); i++)
    {
        ll v=g[u][i];
        if(!disc[v])
        {
            c++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);

            if((!u && c>1) || (u && disc[u]<=low[v]))
            {
                chk[u]=1;
            }
        }
        else if(v!=par)
        {
            low[u]=min(low[u],disc[v]);
        }
    }
}

void solve(ll u)
{
    vis[u]=1;
    comp++;

    for(ll i=0; i<g[u].size(); i++)
    {
        ll v=g[u][i];
        if(!vis[v])
        {
            if(chk[v]) cnt.insert(v);
            else
            {
                solve(v);
            }
        }
    }
}

int main()
{

    ll t,ii=0;
    scanf("%lli",&t);

    while(t--)
    {
        ll n,m;
        scanf("%lli %lli",&n,&m);

        time_cnt=leaf=0;
        ans=1;
        for(ll i=0; i<=n; i++)
        {
            g[i].clear();
            disc[i]=low[i]=0;
            chk[i]=0;
            vis[i]=0;
        }

        for(ll i=0; i<m; i++)
        {
            ll u,v;
            scanf("%lli %lli",&u,&v);
            g[u].pb(v);
            g[v].pb(u);
        }

        dfs(0,-1);

        for(ll i=0; i<n; i++)
        {
            if(!vis[i] && !chk[i])
            {
                //cout<<i<<endl;
                cnt.clear();
                comp=0;
                solve(i);
                if(cnt.size()==1)
                {
                    leaf++;
                    ans*=comp;
                }
            }
        }
        if(!leaf)
        {
            leaf=2;
            ans=(n*(n-1))/2;
        }

        printf("Case %lli: %lli %llu\n",++ii,leaf,ans);
    }

    return 0;
}
