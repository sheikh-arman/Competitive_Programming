/*
    Sk arman Hossain
    University of Barisal

    Problem name : codechef - CAGHS
    Solution : strongly connected component and top sort
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 100010
#define PB push_back
vector<ll>edj[N+10],trans_edj[N+10];
stack<ll>st;
bitset<N+10>color;
ll wei[N+10];
vector<ll>strong;
void dfs(ll node)
{
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dfs(i);
        }
    }
    st.push(node);
}
void dfs2(ll node)
{
    strong.PB(node);
    color[node]=true;
    for(ll i:trans_edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dfs2(i);
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            color[i]=false;
            edj[i].clear();
            trans_edj[i].clear();
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].push_back(v);
            trans_edj[v].push_back(u);
        }
        vector<ll>hos;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            wei[i]=a;
            if(a==0&&color[i]==false)
            {
                hos.PB(i);
            }
        }
        for(ll i:hos)
        {
            dfs(i);
        }
        vector<ll>V_cl,V;
        for(ll i=0; i<n; i++)
        {
            if(color[i]==false)
                V_cl.PB(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(ll i=0; i<n; i++)
        {
            if(color[i]==false)
            {
                dfs(i);
            }
        }
        for(ll i:V_cl)
        {
            color[i]=false;
        }
        while(!st.empty())
        {
            ll tm=st.top();
            st.pop();
            V.PB(tm);
            if(color[tm]==false)
            {
                strong.clear();
                dfs2(tm);
                ll mi=wei[strong[0]];
                for(ll j:strong)
                    mi=min(mi,wei[j]);
                for(ll j:strong)
                    wei[j]=mi;
            }
        }
        for(ll i:V_cl)
        {
            color[i]=false;
        }
        ll ans=0;
        for(ll i:V)
        {
            if(color[i]==false)
            {
                dfs(i);
                ans+=wei[i];
            }
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
