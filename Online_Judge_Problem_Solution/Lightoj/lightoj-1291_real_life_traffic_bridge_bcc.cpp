/*
    Sk arman Hossain
    University of Barisal

    Problem : Real Life Traffic
    Solution : bridge + bcc
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
vector<ll>edj[10010];
set<ll>bcc[10010];
vector< pair<ll,ll> >bridge;
ll start[10010];
ll en[10010],cnt;
bitset<10010>color;
ll rep[10010];
void dfs_bridge_find(ll node,ll parent)
{
    start[node]=en[node]=cnt++;
    ll siz=edj[node].size();
    color[node]=true;
    for(ll i=0; i<siz; i++)
    {
        ll tm=edj[node][i];
        if(color[tm]==false)
        {
            color[tm]=true;
            dfs_bridge_find(tm,node);
            en[node]=min(en[tm],en[node]);
            if(tm[en]>start[node]){
                bridge.push_back({tm,node});
                bridge.push_back({node,tm});
                bcc[tm].erase(bcc[tm].find(node));
                bcc[node].erase(bcc[node].find(tm));
            }
        }
        else if(tm!=parent)
        {
            en[node]=min(start[tm],en[node]);
        }
    }
}
ll set_rep(ll node, ll parent){
    color[node]=true;
    rep[node]=parent;
    for(ll i:bcc[node]){
        if(color[i]==false){
            color[i]=true;
            set_rep(i,parent);
        }
    }
}
ll deg[10010];
void init(ll n){
    for(ll i=0;i<=n;i++){
        edj[i].clear();
        bcc[i].clear();
        color[i]=false;
        rep[i]=0;
        deg[i]=0;
    }
    bridge.clear();
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
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);

            bcc[u].insert(v);
            bcc[v].insert(u);
        }
        dfs_bridge_find(0,-1);
        for(ll i=0;i<=n;i++){
            color[i]=false;
        }
        for(ll i=0;i<n;i++){
            if(color[i]==false)
            set_rep(i,i);
        }
        m=bridge.size();
        for(ll i=0;i<m;i++){
            ll a=rep[bridge[i].first];
            ll b=rep[bridge[i].second];
            deg[a]++;
            deg[b]++;
        }
        ll ans=0,cnt=0;
        for(ll i=0;i<n;i++){
           // cout<<i<<" "<<deg[i]<<" x\n";
            if(deg[i]==2){
                cnt++;
            }
        }
        ans=(cnt+1)/2;
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}





