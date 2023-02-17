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
ll ind[20010];
vector<ll>edj[20010];
ll color[20010];
ll dfs(ll node)
{

    ll ans=0;
    color[node]=true;
    ll siz=edj[node].size();
    if(siz==0)return 1;
    for(ll i=0; i<siz; i++)
    {
        ll val=edj[node][i];
        if(color[val]==false)
        {
            color[val]=true;
            ans+=dfs(val);
        }
        else
        {
            ans+=1;
        }
    }
    return ans;
}
int main()
{
    freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=0;i<=n;i++){
            color[i]=false;
            edj[i].clear();
            ind[i]=0;
        }
        for(ll i=0; i<=n; i++)
        {
            ind[i]=0;
        }
        for(ll i=0; i<n-1; i++)
        {
            ll a,b;
            cin>>a>>b;
            edj[b].PB(a);
            ind[a]++;
        }
        ll ot=0,in=0;
        ll ans=0;
        for(ll i=0; i<n; i++)
        {
            if(ind[i]==0&&color[i]==false)
            {

                ans+=dfs(i);
                //cout<<i<<" "<<ans<<"\n";
            }
        }
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}




