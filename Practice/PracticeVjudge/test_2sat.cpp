/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
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
vector<ll> edj[17010],rev_edj[17010],scc[17010];
stack<ll>stk;
bitset<17010>color;
ll rep[17010];
ll sat[17010];
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
void init(ll n)
{
    for(ll i=0; i<=2*n; i++)
    {
        edj[i].clear();
        rev_edj[i].clear();
        scc[i].clear();
        color[i]=false;
        sat[i]=0;
        rep[i]=0;
    }
}
void dfs2(ll node,ll parent)
{
    rep[node]=parent;
    //scc[parent].PB(node);
    color[node]=true;
    for(ll i:rev_edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dfs2(i,parent);
        }
    }
}
ll sat2(ll n)
{
    for(ll i=1; i<=2*n; i++)
    {
        if(color[i]==false)
        {
            dfs(i);
        }
    }
    for(ll i=0; i<=2*n; i++)
    {
        color[i]=false;
    }
    vector<ll>V;
    ll cnt=1;
    while(!stk.empty())
    {
        ll node=stk.top();
        stk.pop();
        if(color[node]==false)
        {
            dfs2(node,cnt);
            cnt++;
        }
    }
    for(ll i=1; i<=n; i+=1)
    {
        if(rep[i]==rep[i+n])
        {
            return 0;
        }
        sat[i]=(rep[i]>rep[i+n]);
    }
    return 1;
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
        ll m,n;
        cin>>m>>n;
        init(n);
        while(!stk.empty())stk.pop();
        for(ll i=0; i<m; i++)
        {

            ll a,b;
            cin>>a>>b;
            if(a>0&&b>0)
            {
                edj[a+n].PB(b);
                rev_edj[b].PB(a+n);

                edj[b+n].PB(a);
                rev_edj[a].PB(b+n);
            }
            else if(a>0&&b<0)
            {
                edj[a+n].PB(n-b);
                rev_edj[n-b].PB(a+n);
                edj[-b].PB(a);
                rev_edj[a].PB(-b);
            }
            else if(a<0&&b>0)
            {
                edj[-a].PB(b);
                rev_edj[b].PB(-a);
                edj[b+n].PB(n-a);
                rev_edj[n-a].PB(b+n);
            }
            else
            {
                edj[-a].PB(n-b);
                rev_edj[n-b].PB(-a);
                edj[-b].PB(n-a);
                rev_edj[n-a].PB(-b);
            }
        }
        ll ans=sat2(n);
        if(ans)
        {
            ll res=0;
            vector<ll>V;
            for(ll i=1; i<=n; i++)
            {
                if(sat[i]==1)
                {
                    res++;
                    V.PB(i);
                }
            }
            cout<<"Case "<<test<<": Yes\n";
            cout<<res;
            for(ll i=0; i<res; i++)
            {
                cout<<" "<<V[i];
            }
            cout<<"\n";
        }
        else
        {
            cout<<"Case "<<test<<": No\n";
        }
    }
    return 0;
}
/*
Implication Rule
a v !b  =  !a -> !b
           b -> a
a v b   =  !a -> b
           !b -> a
!a v !b =  a -> !b
           b -> !a
!a v b  =  a -> b
           !b -> !a

*/





