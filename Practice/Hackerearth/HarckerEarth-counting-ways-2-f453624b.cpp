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
ll mod=1e9+7;
ll dp[1010][1010];
ll cumx[1010][1010];
ll cumy[1010][1010];
ll cumd[1010][1010];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m,k;
        cin>>n>>m>>k;

        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=m; j++)
            {
                dp[i][j]=0;
                cumx[i][j]=0;
                cumy[i][j]=0;
                cumd[i][j]=0;
            }
        }
        dp[1][1]=1;
        cumx[1][1]=1;
        cumy[1][1]=1;
        cumd[1][1]=1;
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=m; j++)
            {
                if(i==1&&j==1)continue;
                ll ans=cumx[i-1][j];
                if(i>k)
                {
                    ans-=cumx[(i-1)-k][j];
                    while(ans<0)ans+=mod;
                }
                ll ans_col=cumy[i][j-1];
                if(j>k)
                {
                    ans_col-=cumy[i][(j-1)-k];
                    while(ans_col<0)ans_col+=mod;
                }

                ll ans_dia=cumd[i-1][j-1];
                if(j>k&&i>k)
                {
                    ans_dia-=cumd[(i-1)-k][(j-1)-k];
                    while(ans_dia<0)ans_dia+=mod;
                }
                dp[i][j]=ans+ans_col+ans_dia;
                if(dp[i][j]>=mod)
                    dp[i][j]%=mod;

                cumx[i][j]=dp[i][j]+cumx[i-1][j];
                if(cumx[i][j]>=mod)cumx[i][j]%=mod;

                cumy[i][j]=dp[i][j]+cumy[i][j-1];
                if(cumy[i][j]>=mod)cumy[i][j]%=mod;

                cumd[i][j]=dp[i][j]+cumd[i-1][j-1];
                if(cumd[i][j]>=mod)cumd[i][j]%=mod;
            }
        }
        ll ans=dp[n][m]%mod;
        cout<<ans<<"\n";
    }
    return 0;
}





