/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution : scc
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
vector<ll>edj[20010];
vector<ll>rev_edj[20010];
set<ll>compressed_edj[20010];
ll indeg[20010];
ll outdeg[20010];
bitset<20010>color;
ll rep[20010],cnt;
stack<ll>stk;
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
    stk.push(node);
}
void set_rep(ll node,ll val)
{
    rep[node]=val;
    color[node]=true;
    for(ll i:rev_edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            set_rep(i,val);
        }
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cnt=1;
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            rev_edj[i].clear();
            compressed_edj[i].clear();
            indeg[i]=0;
            outdeg[i]=0;
            rep[i]=i;
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            rev_edj[v].PB(u);
        }
        for(ll i=0; i<=n; i++)
        {
            color[i]=false;
        }
        for(ll i=1; i<=n; i++)
        {
            if(color[i]==false)
            {
                dfs(i);
            }
        }
        for(ll i=0; i<=n; i++)color[i]=false;
        vector<ll>strong;
        while(!stk.empty())
        {
            ll node=stk.top();
            stk.pop();
            if(color[node]==false)
            {
                set_rep(node,node);
                strong.PB(node);
            }
        }
        for(ll i=1; i<=n; i++)
        {
            ll node=rep[i];
            for(ll j:edj[i])
            {
                ll child=rep[j];
                if(child!=node)
                {
                    compressed_edj[node].insert(child);
                }
            }
        }
        for(ll i:strong)
        {
            ll node=rep[i];
            outdeg[rep[i]]+=compressed_edj[rep[i]].size();
            for(ll j:compressed_edj[node])
            {
                indeg[rep[j]]++;
            }
            compressed_edj[node].clear();
        }
        ll in=0,ou=0;
        for(ll i:strong)
        {
            if(indeg[i]==0)in++;
            if(outdeg[i]==0)ou++;
        }
        ll ans=max(in,ou);
        if(n==1||(ll)strong.size()==1)ans=0;
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}

/*

4
4 4
1 2
2 3
3 1
4 1

6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 4

5 3
1 2
2 3
2 4

14 18
1 2
2 3
3 1
3 4
4 5
5 6
6 4
3 7
7 8
8 9
9 7
3 10
10 11
11 3
10 12
12 13
13 14
14 12


*/


