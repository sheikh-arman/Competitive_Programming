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
vector<ll>edj[10010];
set<ll>bcc[10010];
ll start[10010],en[10010],color[10010];
ll cnt=1;
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
            if(en[tm]>start[node]){
                bcc[node].erase(bcc[node].find(tm));
                bcc[tm].erase(bcc[tm].find(node));
            }
        }
        else if(tm!=parent)
        {
            en[node]=min(start[tm],en[node]);
        }
    }
}
ll ck,cn=0;
void dfs(ll node){
    cn++;
    for(ll i:bcc[node]){
        if(color[i]==0){
            if(color[node]==1){
                color[i]=2;
            }
            else{
                color[i]=1;
            }
            dfs(i);
        }
        else{
            if(color[i]==color[node]){
                ck=1;
            }
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
        ll n,m;
        cin>>n>>m;
        cnt=1;
        for(ll i=0;i<n;i++){
            bcc[i].clear();
            edj[i].clear();
            color[i]=0;
        }
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
            bcc[u].insert(v);
            bcc[v].insert(u);
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(color[i]==0){
                dfs_bridge_find(i,-1);
            }
        }
        for(ll i=0;i<n;i++){
            color[i]=0;
        }
        for(ll i=0;i<n;i++){
            if(color[i]==0){
                //cout<<i<<" x\n";
                ck=0;
                cn=0;
                color[i]=1;
                dfs(i);
                if(ck)ans+=cn;
            }
        }
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}





