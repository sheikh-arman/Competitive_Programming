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
#define MAX 300010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
ll mem[MAX+10];
vector<ll>edj[MAX+10];
vector<ll>edj2[MAX+10];
ll cnt[MAX+10];
bitset<MAX+10>color;
ll dfs(ll node)
{
    cnt[node]=1;
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            edj2[node].PB(i);
            color[i]=true;
            dfs(i);
            cnt[node]+=cnt[i];
        }
    }
}
ll dp(ll node)
{
    if(mem[node]!=-1)
    {
        return mem[node];
    }
    ll siz=edj2[node].size();
    ll ans=0;
    if(siz==1)
    {
        ans=cnt[edj2[node][0]]-1;
    }
    else if(siz==2)
    {
        ans=(cnt[edj2[node][0]]-1)+dp(edj2[node][1]);
        ll ans2=(cnt[edj2[node][1]]-1)+dp(edj2[node][0]);
        ans=max(ans,ans2);
    }
    return mem[node]=ans;

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
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            edj2[i].clear();
            mem[i]=-1;
            cnt[i]=0;
            color[i]=false;
        }
        for(ll i=0; i<n-1; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        dfs(1);
        for(int i=0; i<=n; i++)
        {
            edj[i].clear();
        }
        ll ans=dp(1);
        cout<<ans<<"\n";
    }
    return 0;
}





