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
ll mem[3010][3011][3];
ll n,m,r;
ll dp(ll i,ll j,ll status)
{
    if(i>n||j>m)
    {
        if(status==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    if(mem[i][j][status]!=-1)
    {
        return mem[i][j][status];
    }
    ll ans=0;
    if(status==0)
    {

        ans|=dp(i+(2*r)-1,j+(2*r)-1,1);

    }
    else
    {
        ans=1;
        ans&=dp(i+(2*r)-1,j+(2*r)-1,0);
    }
    return mem[i][j][status]=ans;
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

        cin>>n>>m>>r;
        //cout<<"Alice\n";return 0;
        if(n<r||m<r)
        {
            cout<<"Bob\n";
            return 0;
        }
        ll dif=abs(n-m);
        if(r>dif)
        {
            cout<<"Alice\n";
            return 0;
        }
        else
        {
            for(ll i=0; i<=n; i++)
            {
                for(ll j=0; j<=m; j++)
                {
                    for(ll k=0; k<2; k++)
                    {
                        mem[i][j][k]=-1;
                    }
                }
            }
            ll ans=dp(1,1,0);
            if(ans==1)
            {
                cout<<"Alice\n";
            }
            else
            {
                cout<<"Bob\n";
            }
        }
    }
    return 0;
}






