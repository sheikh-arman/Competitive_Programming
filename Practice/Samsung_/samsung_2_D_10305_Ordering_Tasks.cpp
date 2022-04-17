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
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
stack<ll>stk;
vector<ll>V,edj[110];
bitset<110>color;
void dfs(ll node,ll status)
{
    if(status==1)
    {
        V.PB(node);
    }
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dfs(i,status);
        }
    }
    if(status==0)
        stk.push(node);
}
int main()
{
    // freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; ; test++)
    {
        ll node,edge;
        cin>>node>>edge;
        for(ll i=0; i<=node; i++)
        {
            edj[i].clear();
        }
        if(!node&&!edge)
        {
            break;
        }
        for(ll i=0; i<edge; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
        }
        for(ll i=0; i<=node; i++)color[i]=false;
        while(!stk.empty())stk.pop();
        for(ll i=1; i<=node; i++)
        {
            if(color[i]==false)dfs(i,0);
        }
        for(ll i=0; i<=node; i++)color[i]=false;
        V.clear();
        while(!stk.empty())
        {
            ll tp=stk.top();
            stk.pop();
            // cout<<tp<<" x\n";
            if(color[tp]==false)
            {
                dfs(tp,1);
            }
        }
        for(ll i=0; i<node; i++)
        {
            if(i>0)
            {
                cout<<" ";
            }
            cout<<V[i];
        }
        cout<<"\n";
    }
    return 0;
}




