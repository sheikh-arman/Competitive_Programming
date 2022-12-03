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
vector<pair<ll,ll>>edj[200010];
bitset<200010>color;
ll node_cnt[200010];
ll cnt=0;
ll mul=0,selected_root,total_sub_node;
vector<pair<ll,ll>>V_list;
ll mod=998244353;
void dfs(ll node,ll parent)
{
    color[node]=true;
    node_cnt[node]=1;
    for(auto j:edj[node])
    {
        ll i=j.first;
        if(color[i]==false)
        {
            color[i]=true;
            dfs(i,node);
            node_cnt[node]+=node_cnt[i];
        }
    }
    ll ans=1,sum=0;
    for(auto j:edj[node])
    {
        ll i=j.first;
        if(i!=parent)
        {
            sum+=node_cnt[i];
            ans*=node_cnt[i];
        }
    }
    if(parent!=-1)
    {
        ans*=(total_sub_node-sum);
    }
    if(ans<mul)
    {
        mul=ans;
        selected_root=node;
    }
}
ll result,total_node;
void dfs2(ll node,ll parent)
{
    //cout<<node<<" "<<parent<<" x\n";
    color[node]=true;
    node_cnt[node]=1;
    for(auto j:edj[node])
    {
        ll i=j.first;
        if(color[i]==false)
        {
            color[i]=true;
            dfs2(i,node);
            node_cnt[node]+=node_cnt[i];
        }
    }
    for(auto j:edj[node])
    {
        ll i=j.first;
        if(i!=parent)
        {
            ll tm=((node_cnt[i]*(total_node-node_cnt[i]))%mod)*j.second;
            tm%=mod;
            result+=tm;
            result%=mod;
        }
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll extra_sum=0,n;
        total_node=0;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll m;
            cin>>m;
            total_node+=m;
            ll visit;
            for(ll j=0; j<m-1; j++)
            {
                ll u,v,w;
                cin>>u>>v>>w;
                u+=extra_sum;
                v+=extra_sum;
                edj[u].PB({v,w});
                edj[v].PB({u,w});
                visit=u;
            }
            mul=LONG_LONG_MAX;
            total_sub_node=m;
            dfs(visit,-1);
            V_list.PB({m,selected_root});
            //cout<<selected_root<<" why?\n";
            extra_sum+=m;
        }
        VST(V_list);
        vector<ll>V;
        for(ll i=0; i<n-1; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        VST(V);
        reverse(V.begin(),V.end());
        ll tm_root=V_list[n-1].second;
        ll j=n-2;
        for(ll i:V)
        {

            ll new_node=V_list[j].second;
            j--;
            edj[new_node].PB({tm_root,i});
            edj[tm_root].PB({new_node,i});
        }
        ll start;
        for(ll i=1;; i++)
        {
            if((ll)edj[i].size()==1)
            {
                start=1;
                break;
            }
        }
        for(ll i=0; i<=200000; i++)
        {
            color[i]=0;
            node_cnt[i]=0;
        }
        dfs2(start,-1);
        cout<<result<<"\n";
    }
    return 0;
}





