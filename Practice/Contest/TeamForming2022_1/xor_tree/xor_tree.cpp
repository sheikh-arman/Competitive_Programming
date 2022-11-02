
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
ll ar[100010];
vector<ll>edj[100010];
ll xo,ans;
ll cnt;
ll rep[1000010];
ll Find(ll node){
    return (rep[node]==node?node:rep[node]=Find(rep[node]));
}
void dfs(ll node,ll tm,ll parent)
{

    tm^=ar[node];
    ans=max(ans,tm^xo);
    for(ll i:edj[node])
    {
        if(parent!=i)
        {
            dfs(i,tm,node);
        }
    }
}
int main()
{
    //freopen("input10.txt","r",stdin);
    //freopen("output10.txt","w",stdout);
    //fast;
    ll tcase=1;
    // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cnt=0;
        ll n;
        cin>>n;
        for(ll i=0;i<=n;i++)rep[i]=i;
        assert(1<=n&&n<=100000);
        xo=0;
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
            assert(0<=ar[i]&&ar[i]<=10000000000);
            xo^=ar[i];
        }
        for(ll i=0; i<n-1; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
            assert(Find(u)!=Find(v));
            rep[Find(u)]=Find(v);
        }
        ans=xo;
        dfs(1,0,-1);
        cout<<ans<<"\n";
    }
    return 0;
}





