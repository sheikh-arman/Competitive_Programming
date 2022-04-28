//later
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
#define MAX 101010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};

vector<ll>edj[MAX+100];
vector<ll>rev_edj[MAX+100],connected;
stack<ll>stk;
bitset<MAX+100>color;
ll cnt_node[MAX+100];
ll rep[MAX+100];
void dfs(ll node,ll status)
{
    color[node]=true;
    if(status==0)
    {
        for(ll i:edj[node])
        {
            if(color[i]==false)
            {
                color[i]=true;
                dfs(i,status);
            }
        }
        stk.push(node);
    }
    else
    {
        connected.PB(node);
        for(ll i:rev_edj[node])
        {
            if(color[i]==false)
            {
                color[i]=true;
                dfs(i,status);
            }
        }
    }

}
void dp(ll node)
{
    node=rep[node];
    color[node]=true;
    ll total_node=0;
    for(ll i:edj[node])
    {
        i=rep[i];
        if(color[i]==false)
        {
            color[i]=true;
            dp(i);
        }
        if(node!=i)
            total_node=max(cnt_node[i],total_node);
    }
    cnt_node[node]+=total_node;
}

int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
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
            rev_edj[i].clear();
            cnt_node[i]=1;
            rep[i]=i;
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            rev_edj[v].PB(u);
        }
        while(!stk.empty())
        {
            stk.pop();
        }
        for(ll i=1; i<=n; i++)
        {
            if(color[i]==false)
            {
                dfs(i,0);
            }
        }
        for(ll i=0; i<=n; i++)
        {
            color[i]=false;
        }
        while(!stk.empty())
        {
            ll node=stk.top();
            stk.pop();
            if(color[node]==false)
            {
                connected.clear();
                dfs(node,1);
                ll parent=connected[0];
                ll siz=connected.size();
                for(ll i:connected)
                {
                    rep[i]=parent;
                    cnt_node[parent]=siz;
                }
                set<ll>st;
                for(ll i:connected)
                {
                    for(ll j:edj[i])
                    {
                        if(rep[i]!=rep[j])
                            st.insert(j);
                    }
                    edj[i].clear();
                }
                for(ll i:st)
                {
                    edj[parent].PB(i);
                }
            }
        }
        for(ll i=0; i<=n; i++)
        {
            color[i]=false;
        }
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll u;
            cin>>u;
            u=rep[u];
            if(color[u]==false)
            {
                dp(u);
            }
            cout<<cnt_node[u]<<"\n";
        }
    }
    return 0;
}





