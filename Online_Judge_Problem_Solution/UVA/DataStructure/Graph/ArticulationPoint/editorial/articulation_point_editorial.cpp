#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>edj[10010];
ll start[10010];
ll en[10010],cnt;
bitset<10010>color,ap;
void dfs_ap(ll node,ll parent)
{
    ll child=0;
    start[node]=cnt;
    en[node]=cnt++;
    ll siz=edj[node].size();
    color[node]=true;
    for(ll i=0; i<siz; i++)
    {
        ll tm=edj[node][i];
        if(color[tm]==false)
        {
            child++;
            color[tm]=true;
            dfs_ap(tm,node);
            en[node]=min(en[tm],en[node]);
            if (parent == -1 && child > 1)
            {
                   ap[node] = true;
            }
            if(parent != -1&& start[node]<=en[tm])
            {
                ap[node]=true;
            }
        }
        else if(tm!=parent)
        {
            en[node]=min(start[tm],en[node]);
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll n,m,q;
    while(cin>>n>>m>>q&&(n||m||q))
    {
        for(ll i=0; i<=n; i++)
        {
            color[i]=false;
            edj[i].clear();
            en[i]=start[i]=LONG_MAX;
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[v].push_back(u);
            edj[u].push_back(v);
        }
        cnt=1;
        dfs_ap(1,-1);

        cout<<"Articulation points are: ";
        for(ll i=1; i<=n; i++)
        {
            if(ap[i])
              cout<<i<<" ";
        }
        cout<<"\n";


    }

}
