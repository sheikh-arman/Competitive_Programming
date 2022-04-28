#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
ll dis[110][110];
vector<ll>V;
ll mem[110][110][110],n;
ll dp(ll l,ll r,ll current)
{
    if(l>=r)
    {
        if(l>r)
        {
            return 0;
        }
        else
        {

            return abs(V[current]-V[l])*(n-1);
        }
    }
    if(mem[l][r][current]!=-1)
    {
        return mem[l][r][current];
    }
    ll tm_ans=LONG_MAX;
    for(ll i=l; i<=r; i++)
    {
        ll cost=abs(V[current]-V[i]);
        ll node_partition1=(r-l)+1;
        ll node_partition2=n-node_partition1;
        ll res=(cost*node_partition1*node_partition2)+(dp(l,i-1,i)+dp(i+1,r,i));
        tm_ans=min(tm_ans,res);
    }
    //cout<<l<<" "<<r<<" "<<current<<" "<<tm_ans<<" x\n";
    return mem[l][r][current]=tm_ans;
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
        cin>>n;
        V.clear();
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            // cout<<a<<" ";
        }
        //cout<<" in\n";
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=n; j++)
            {
                for(ll k=0; k<=n; k++)
                {
                    mem[i][j][k]=-1;
                }
            }
        }
        ll ans=LONG_MAX;
        for(ll i=0; i<n; i++)
        {
            ans=min(ans,dp(0,i-1,i)+dp(i+1,n-1,i));
            // cout<<ans<<" ans\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}




