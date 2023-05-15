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
#define YES cout<<"Yes\n";
#define NO cout<<"No\n";
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
bitset<200010>color;
bitset<200010>color_diameter;
ll parent[200100];
ll label[200100];
ll diameter,diameter_node;
vector<ll>edj[200010];
void dfs(ll node)
{
    color[node]=1;
    for(ll i:edj[node])
    {
        if(color[i]==0)
        {
            color[i]=1;
            label[i]=label[node]+1;
            parent[i]=node;
            if(label[i]>diameter)
            {
                diameter=label[i];
                diameter_node=i;
            }
            dfs(i);
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
        ll n;
        cin>>n;
        for(ll i=0; i<n-1; i++)
        {
            ll a,b;
            cin>>a>>b;
            edj[a].PB(b);
            edj[b].PB(a);
        }
        dfs(1);
        color.reset();
        for(ll i=1; i<=n; i++)parent[i]=-1;
        diameter=0;
        label[diameter_node]=0;
        dfs(diameter_node);
        ll node=diameter_node;
        while(node!=-1)
        {
            color_diameter[node]=1;
            node=parent[node];
        }
        ll ck=1;
        for(ll i=1; i<=n; i++)
        {
            if(parent[i]==-1)continue;
            if(color_diameter[parent[i]]==0)
            {
                ck=0;
                break;
            }
        }
        if(ck)
        {
            YES;
            vector<ll>V,rev_V;
            node=diameter_node;
            ll cnt=0;
            while(node!=-1)
            {
                if(cnt==1)
                {
                    rev_V.PB(node);
                    for(ll i:edj[node])
                    {
                        if(color_diameter[i]==0)
                        {
                            V.PB(i);
                        }
                    }
                }
                else
                {
                    V.PB(node);
                    for(ll i:edj[node])
                    {
                        if(color_diameter[i]==0)
                        {
                            rev_V.PB(i);
                        }
                    }
                }
                cnt=1-cnt;
                node=parent[node];
            }
            reverse(rev_V.begin(),rev_V.end());
            for(ll i:rev_V)
            {
                V.PB(i);
            }
            for(ll i:V)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
        }
        else
        {
            NO;
        }
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}






