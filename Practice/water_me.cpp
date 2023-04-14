#include<bits/stdc++.h>
using namespace std;
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef int ll;
#define PB push_back
vector<ll>linear;
vector<ll>edj[100010];
bitset<100010>color;
vector<ll>start(100010),en(100010);
ll cnt;
bitset<100010>ans;
void dfs(ll node)
{
    start[node]=cnt;
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dfs(i);
        }
    }
    en[node]=cnt++;
    linear.PB(node);
}
ll parent[100010];
ll find_parent(ll node)
{
    return (parent[node]==node?node:parent[node]=find_parent(parent[node]));
}
ll n;
void update(ll node,ll val)
{
    ll suru=find_parent(start[node]);
    while(val>0&&suru<n)
    {
        if(en[node]>=suru)
        {
            if(ans[suru]==0)
            {
                ans[suru]=1;
                val--;
            }
            parent[suru]=find_parent(suru+1);
            suru=parent[suru];
        }
        else
        {
            break;
        }
    }
}
int main()
{
    fast;
    freopen("1input.txt","r",stdin);
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        linear.clear();
        cin>>n;
        for(ll i=0; i<=n+1; i++)
        {
            color[i]=false;
            edj[i].clear();
            parent[i]=i;
            start[i]=0;
            en[i]=0;
            ans[i]=0;
        }
        for(ll i=0; i<n-1; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        for(ll i=0;i<=n;i++){
            sort(edj[i].begin(),edj[i].end());
        }
        cnt=0;
        dfs(1);

        for(ll i=1;i<=n;i++){
			cout<<start[i]<<" ";
		}
		cout<<"\n";
		for(ll i=1;i<=n;i++){
			cout<<en[i]<<" ";
		}
		cout<<"\n";

        ll q;
        cout<<"Case "<<test<<":\n";
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll query;
            cin>>query;
            if(query==1)
            {
                ll node,val;
                cin>>node>>val;
                update(node,val);
            }
            else
            {
                ll node;
                cin>>node;
                cout<<ans[en[node]]<<"\n";
            }
        }
    }
    return 0;
}