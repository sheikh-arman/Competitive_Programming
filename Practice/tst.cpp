#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll start[N],ending[N],w;
bitset<N>bt;
vector<ll>g[N];
ll arr[N],s=0,t[3*N];
void dfs(ll i)
{
    bt[i]=1;
    start[i]=s;
    sort(g[i].begin(),g[i].end());
    for(auto j:g[i])
    {
        if(bt[j]==0) dfs(j);
    }
    ending[i]=s++;
    //v.push_back(i);
}
void init(ll n,ll b,ll e)
{
    if(b==e)
    {
        t[n]=1;
        return;
    }
    ll mid=(b+e)/2;
    init(2*n,b,mid);
    init(2*n+1,mid+1,e);
    t[n]=t[2*n]+t[2*n+1];
    return ;
}
void update(ll n,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b) return ;
    if(w<=0 || t[n]==0) return ;
    if(b>=i && e<=j && w>=t[n])
    {
        w-=t[n];
        t[n]=0;
        return;
    }
    ll mid=(b+e)/2;
    update(2*n,b,mid,i,j);
    update(2*n+1,mid+1,e,i,j);
    t[n]=t[2*n]+t[2*n+1];
    return;
}
ll query(ll n,ll b,ll e,ll i)
{
    //cout<<n<<" "<<t[n]<<endl;
    if(i<b || i>e) return 0;
    if(b==i && e==i) return t[n]^1;
    if(i>=b && i<=e && t[n]==0) return 1;
    ll mid=(b+e)/2;
    ll p=0,q=0;
    p=query(2*n,b,mid,i);
    q=query(2*n+1,mid+1,e,i);
    //cout<<p<<" "<<q<<" "<<n<<endl;
    return p|q;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    int l=tt;
    while(tt--)
    {
        s=1;
        cout<<"Case "<<l-tt<<":\n";
        ll n,i,j,s2=0;
        cin>>n;
        set<ll>st;
        for(i=1; i<=n; i++) st.insert(i);
        for(i=0; i<=n; i++)
        {
            bt[i]=0;
            g[i].clear();
        }
        for(i=1; i<n; i++)
        {
            ll u,v;
            cin>>u>>v;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        s=1;
        dfs(1);
        init(1,1,n);
        ll q;
        cin>>q;
        while(q--)
        {
            ll x,y;
            cin>>x>>y;
            if(x==1)
            {
                cin>>w;
                ll r=start[y],r2=ending[y];
                update(1,1,n,r,r2);
            }
            else
            {
                cout<<query(1,1,n,ending[y])<<"\n";
            }
        }
    }
    return 0;
}
