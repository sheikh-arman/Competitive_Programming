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
set<ll>bcc[10010];
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
void bridge(ll node,ll parent)
{
    color[node]=true;
    start[node]=cnt;
    en[node]=cnt++;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            bridge(i,node);
            start[node]=min(start[node],start[i]);
            if(en[node]<start[i])
            {
                ll a=node,b=i;
                if(a>b)swap(a,b);
                bcc[a].erase(bcc[a].find(b));
                bcc[b].erase(bcc[b].find(a));
            }
        }
        else
        {
            if(parent!=i)
                start[node]=min(start[node],en[i]);
        }
    }
}
vector<ll>bcc_list;
void dfs(ll node)
{
    bcc_list.PB(node);
    color[node]=true;
    for(ll i:bcc[node])
    {
        if(color[i]==false)
        {
            dfs(i);
        }
    }
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
        color.reset();
        ap.reset();
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            bcc[i].clear();
            edj[i].clear();
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[v].PB(u);
            edj[u].PB(v);
            bcc[u].insert(v);
            bcc[v].insert(u);
        }
        dfs_ap(0,-1);
        color.reset();
        bridge(0,-1);
        unsigned long long int ans=1;
        ll mi=0;
        color.reset();
        for(ll i=0; i<n; i++)
        {
            if(color[i]==false)
            {
                bcc_list.clear();
                dfs(i);
                cout<<i<<" :";
                if((ll)bcc_list.size()==1)
                {
                    if(ap[bcc_list[0]]==0)
                    {
                        mi++;
                        cout<<bcc_list[0]<<"\n";
                    }
                }
                else
                {
                    ll cnt=0;
                    for(ll j:bcc_list)
                    {
                        if(ap[j])
                        {
                            cnt++;
                        }
                        cout<<j<<" ";
                    }
                    cout<<" x\n";
                    if(cnt==1)
                    {
                        mi++;
                        ans*=(ll)bcc_list.size()-1;
                    }
                    else
                    {
                        if(cnt==0)
                        {
                            ans=(n*(n-1))/2;
                            mi=2;
                        }
                    }
                }
                cout<<mi<<" "<<ans<<" x\n";
            }
        }
        cout<<"Case "<<test<<": "<<mi<<" "<<ans<<"\n";
    }
    return 0;
}




