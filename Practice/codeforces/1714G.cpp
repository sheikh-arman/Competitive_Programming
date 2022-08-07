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

ll sparse[200010][22];
ll ar[200010];
ll br[200010];
ll label[200010];
ll parent[200010];
vector<ll>edj[200010];
bitset<200010>color;
void dfs(ll node)
{
    color[node]=true;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            parent[i]=node;
            sparse[i][0]=node;
            ar[i]+=ar[node];
            br[i]+=br[node];
            label[i]=label[node]+1;
            dfs(i);
        }
    }
}
void init(ll n)
{
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; (1<<j)<=n; j++)
        {
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];
        }
    }
}
ll nth_parent(ll u,ll nth)
{
    ll lg=0;
    for(lg=0; (1<<lg)<=label[u]; lg++)
    {

    }
    lg--;
    ll nth_parent_label=label[u]-nth;
    if(label[u]!=nth_parent_label)
    {
        for(ll i=lg; i>=0; i--)
        {
            if(label[u]-(1<<i)>=nth_parent_label)
            {
                u=sparse[u][i];
            }
        }
    }
    return u;
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
            color[i]=false;
            label[i]=0;
           // memset(sparse[i],-1,sizeof(sparse[i]));
        }
        for(ll i=2; i<=n; i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            edj[i].PB(a);
            edj[a].PB(i);
            ar[i]=b;
            br[i]=c;
        }
        dfs(1);
        init(n);
        for(ll i=2; i<=n; i++)
        {
            ll left=0,right=label[i];
            ll ans=right;
            ll lbl=label[i];
            while(left<=right)
            {
                ll mid=(left+right)/2;
                ll nth_prnt=nth_parent(i,lbl-mid);
                ll tm_sum=br[i]-(br[i]-(br[nth_prnt]));
                if(tm_sum<=ar[i])
                {
                    ans=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}




