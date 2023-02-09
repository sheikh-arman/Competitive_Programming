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
vector<ll>edj[100010];
ll color[100010];
ll node_cnt[100100];
ll ans;
void dfs(ll node,ll parent){
    color[node]=1;
    node_cnt[node]=1;
    ll cnt=0;
    for(ll i:edj[node]){
        if(color[i]==false){
            color[i]=true;
            dfs(i,node);
            node_cnt[node]+=node_cnt[i];
            cnt+=node_cnt[i];
        }
    }
    for(ll i:edj[node]){
        if(i!=parent){
            ll tm1=node_cnt[i];
            ll tm2=cnt-tm1;
            ans+=tm1*tm2;
            cnt-=tm1;
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
        ll n;
        cin>>n;
        ans=0;
        for(ll i=1;i<=n;i++){
            edj[i].clear();
            color[i]=0;
            node_cnt[i]=0;
        }
        for(ll i=0;i<n-1;i++){
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
        }
        dfs(1,-1);
        cout<<"Case "<<test<<": "<<n-1<<" "<<ans<<"\n";
    }
    return 0;
}





