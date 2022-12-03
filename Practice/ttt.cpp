/*
    Sk arman Hossain
    University of Barisal

    Problem : https://lightoj.com/problem/ant-network
    Solution : BCC +  articulation point + bridge
    Date:
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> policy_set;

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
set<ll>articulation;
void dfs(ll node)
{
    cnt++;
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false&&ap[i]==false)
        {
            color[i]=true;
            dfs(i);
        }
        else if(ap[i]==true)
        {
            articulation.insert(i);
        }
    }
}
void init(ll n)
{
    color.reset();
    ap.reset();
    for(ll i=0; i<=n; i++)
    {
        edj[i].clear();
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

        ll n,m;
        cin>>n>>m;
        init(n);
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[v].PB(u);
            edj[u].PB(v);
        }
        dfs_ap(0,-1);
        color.reset();
        ll mi=0;
        unsigned long long int ans=1;
        for(ll i=0; i<n; i++)
        {
            if(color[i]==false&&ap[i]==false)
            {
                color[i]=true;
                cnt=0;
                articulation.clear();
                dfs(i);
                if((ll)articulation.size()==1)
                {
                    ans*=cnt;
                    mi++;
                }
            }
        }
        //cout<<mi<<" "<<ans<<""
        if(mi==0)
        {
            if(n==2)
            {
                mi=2;
                ans=1;
            }
            else
            {
                mi=2;
                ans=(n*(n-1))/2;
            }
        }
        cout<<"Case "<<test<<": "<<mi<<" "<<ans<<"\n";
    }
    return 0;
}





