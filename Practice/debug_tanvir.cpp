#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first
#define S second
#define pb push_back
#define mp make_pair


struct edge
{
    ll u,v,w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

#define mxn 20
ll par [mxn], vis[mxn];
vector<edge>e, new_e;
vector<pair<ll,ll>>g[mxn];

ll find(ll u)
{
    return par[u]==u ? u : find(par[u]);
}

void mst(ll n, ll xx)
{
    sort(e.begin(),e.end());

    for(ll i=0; i<=n; i++)
    {
        par[i]=i;
    }
    ll cnt=0, s=0;

    for(ll i=0; i<e.size(); i++)
    {
        ll u = find(e[i].u);
        ll v = find(e[i].v);
        if(u!=v)
        {
            par[u] = v;
            cnt++;
            new_e.push_back(e[i]);
            if(cnt==xx) break;
        }
    }
}


ll bfs(ll st)
{
    queue<pair<ll,ll>>q;
    q.push(make_pair(st,0ll));
    ll ans=0;
    vis[st]=1;
    while(!q.empty())
    {
        pair<ll,ll>u=q.front();
        q.pop();
        ans+=u.S;
        for(ll i=0; i<g[u.F].size(); i++)
        {
            pair<ll,ll> v = g[u.F][i];
            if(vis[v.F]==0)
            {
                vis[v.F]=1;
                q.push(v);
            }
        }
    }
    return ans;
}



pair<ll,ll> solve(ll k, ll n, ll p)
{

    ll i,j,ans=-1, comp=0;
    for(i=0; i<mxn; i++)
    {
        g[i].clear();
        vis[i]=0;
    }
    for(i=0; i<p; i++)
    {
        if(k&(1<<i)) continue;
        edge x = new_e[i];
        g[x.u].push_back(make_pair(x.v,x.w));
        g[x.v].push_back(make_pair(x.u,x.w));
    }
    for(i=0; i<n; i++)
    {
        if(vis[i]==0)
        {
            ll val=bfs(i);
            ans=max(ans,val);
            comp++;
        }
    }
    return mp(ans,comp);
}



int main()
{
    ll n,c,eg,i,j,k=0,ans=1e18;
    cin>>n>>c>>eg;
    for(i=0; i<=n; i++)
    {
        g[i].clear();
        vis[i]=0;
    }

    for(i=0; i<eg; i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edge x;
        x.u=u;
        x.v=v;
        x.w=w;
        e.push_back(x);

        g[x.u].pb(mp(x.v, x.w));
        g[x.v].pb(mp(x.u, x.w));
    }

    for(i=0; i<n; i++)
    {
        if(vis[i]==0)
        {
            bfs(i);
            k++;
        }
    }

    if(k>c)
    {
        cout<<-1<<endl;
        return 0;
    }

    mst(n, n-k);

    // for(i=0; i<new_e.size(); i++){
    //     cout<<new_e[i].u<<' '<<new_e[i].v<<' '<<new_e[i].w<<endl;
    // }

    ll bal=1<<(n-k);

    for(i=0; i < bal; i++)
    {
        pair<ll,ll> val = solve(i, n, n-k);
        if(val.S<=c)
        {
            ans=min(ans,val.F);
        }
    }

    if(ans >= (ll)1e18) ans=0;

    cout<<ans<<endl;

}


