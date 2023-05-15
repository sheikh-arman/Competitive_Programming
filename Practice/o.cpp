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
ll rep[20];
ll Find(ll node)
{
    return rep[node]==node?node:rep[node]=Find(rep[node]);
}
vector<pair<ll,ll>>edj[20];
ll color[20],sum=0;
void dfs(ll node)
{
    color[node]=1;
    for(auto k:edj[node])
    {
        if(color[k.second]==0)
        {
            sum+=k.first;
            color[k.second]=1;
            dfs(k.second);
        }
    }
}
int main()
{
    freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,c,m;
        cin>>n>>c>>m;
        c=min(c, n);
        for(ll i=0; i<=n; i++)
        {
            rep[i]=i;
        }
        vector<pair<pair<ll,ll>,ll>>V,V2,V3;
        for(ll i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            V.PB({{w,u},v});
        }
        ll ans=1000000000000000;
        VST(V);
        for(ll i=0; i<m; i++)
        {
            ll w=V[i].first.first;
            ll u=V[i].first.second;
            ll v=V[i].second;
            if(Find(u)!=Find(v))
            {
                V2.PB(V[i]);
                rep[Find(u)]=Find(v);
            }
        }
        ll siz=V2.size();
        for(ll i=0; i<(1<<siz); i++)
        {
            V3.clear();
            ll num=i;
            ll ck=0;
            while(num)
            {
                if(num%2)
                {
                    V3.PB(V2[ck]);
                }
                num/=2;
                ck++;
            }
            for(ll j=0; j<=n; j++)
            {
                edj[j].clear();
                color[j]=0;
            }
            for(auto k:V3)
            {
                ll w=k.first.first;
                ll u=k.first.second;
                ll v=k.second;
                edj[u].PB({w,v});
                edj[v].PB({w,u});
            }
            ll ma=0,cnt=0;
            for(ll j=0; j<n; j++)
            {
                if(color[j]==0)
                {
                    cnt++;
                    sum=0;
                    dfs(j);
                    ma=max(ma,sum);
                }
            }
            if(cnt==c)
                ans=min(ans,ma);
        }
        if(ans>=10000000000000)ans=-1;
        cout<<ans<<"\n";
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}






