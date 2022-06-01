/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution : DFS + DSU
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 100005
#define PB push_back
vector<ll>edj[N+10];
bitset<N+10>color;
ll ar[N+10],rep[N+10],parent[N+10],Partition[N+10];
stack<ll>st;
void dfs(ll node)
{
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            ar[i]+=ar[node];
            dfs(i);
        }
    }
    st.push(node);
}
void segment(ll node,ll parent)
{
    rep[node]=parent;
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            segment(i,parent);
        }
    }
}
ll fin(ll n)
{
    return (rep[n]==n?n:rep[n]=fin(rep[n]));
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<n-1; i++)
        {
            ll a;
            cin>>a;
            edj[a].PB(i+2);
            parent[i+2]=a;
        }
        for(ll i=0; i<n-1; i++)
        {
            cin>>ar[i+2];
        }
        dfs(1);
        ll query;
        cin>>query;
        vector<pair<ll,ll>>V;
        for(ll i=1; i<=query; i++)
        {
            ll a,u;
            cin>>a>>u;
            V.PB({a,u});
            if(a==1)
            {
                Partition[u]=1;
            }
        }
        for(ll i=0; i<=n; i++)
        {
            rep[i]=i;
            color[i]=false;
        }
        while(!st.empty())
        {
            ll tm=st.top();
            st.pop();
            if(Partition[tm])
            {
                segment(tm,tm);
            }
        }
        segment(1,1);
        vector<pair<ll,ll> >ans;
        for(ll i=query-1; i>=0; i--)
        {
            ll a=V[i].first,u=V[i].second;
            if(a==1)
            {
                ll x=fin(parent[u]);
                ll y=fin(u);
                if(x!=y)rep[y]=x;
            }
            else
            {
                ans.PB({fin(u),abs(ar[u]-ar[fin(u)])});
            }
        }
        ll siz=ans.size();
        for(ll i=siz-1; i>=0; i--)
        {
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

