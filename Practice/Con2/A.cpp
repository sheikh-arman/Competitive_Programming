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
vector<ll>edj[1000010];
ll in_deg[1000010];
ll ck;
ll color[1000010];
void dfs(ll node)
{
    color[node]=1;
    for(ll i:edj[node])
    {
        if(color[i]==0)
        {
            color[i]=1;
            dfs(i);
        }
        else if(color[i]==1)
        {
            ck=0;
        }
    }
    color[node]=2;
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
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            color[i]=0;
            in_deg[i]=0;
        }
        for(ll i=0; i<m; i++)
        {
            ll a,b;
            cin>>a>>b;
            edj[b].PB(a);
            in_deg[a]++;
        }
        ck=1;
        priority_queue< ll, vector<ll>,greater<ll> >pq;
        for(ll i=1; i<=n; i++)
        {
            if(in_deg[i]==0)
            {
                dfs(i);
                pq.push(i);
            }
        }
        for(ll i=1; i<=n; i++)
        {
            if(color[i]==0)
            {
                ck=0;
                break;
            }
        }
        if(ck)
        {
            vector<ll>V;
            while(!pq.empty())
            {
                ll node=pq.top();
                pq.pop();
                V.PB(node);
                ll siz=edj[node].size();
                for(ll i=0;i<siz;i++)
                {
                    in_deg[edj[node][i]]--;
                }
                for(ll i=0;i<siz;i++)
                {
                    if(in_deg[edj[node][i]]==0){
                        pq.push(edj[node][i]);
                    }
                    //in_deg[edj[node][i]]--;
                }
            }
            for(ll i=0; i<n; i++)
            {
                cout<<V[i]<<" ";
            }
            cout<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
    }
    return 0;
}





