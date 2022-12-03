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
ll label[100010];
ll parent[100010];
vector<ll>edj[100010];
bitset<100010>color;
void last_go(ll node)
{
    color[node]=true;
    if((ll)edj[node].size()==0)
    {
        label[node]=0;
        return;
    }
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            last_go(i);
        }
        if(label[i]+1>label[node])
        {
            label[node]=label[i]+1;
            parent[node]=i;
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
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
        }
        for(ll i=0; i<=n; i++)
        {
            label[i]=-1;
            color[i]=false;
            parent[i]=-1;
        }
        for(ll i=1; i<=n; i++)
        {

            if(color[i]==false)
            {
                last_go(i);
            }
        }
        vector<ll>V;
        ll ma=0,node=1;
        for(ll i=1; i<=n; i++)
        {
            if(label[i]>ma)
            {
                ma=label[i];
                node=i;
            }
        }
        vector<ll>ans;
        while(parent[node]!=-1)
        {
            ans.PB(node);
            node=parent[node];
        }
        ans.PB(node);
        cout<<ans.size()<<"\n";
        ll ck=0;
        for(ll i:ans)
        {
            if(ck)
            {
                cout<<" ";
            }
            cout<<i;
            ck=1;
        }
        cout<<"\n";
    }
    return 0;
}






