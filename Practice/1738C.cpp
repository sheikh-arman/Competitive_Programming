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
ll mem[110][110][3];
ll dp1(ll od,ll ev,ll turn,ll sum1, ll sum2)
{
    if(od==0&&ev==0)
    {
        return 0;
    }
    if(mem[od][ev]!=-1)
    {
        return mem[od][ev][turn];
    }
    ll ans=1;
    sum1%=2;
    sum2%=2;
    if(turn==0)
    {
        if(od>0&&ev>0)
        {
            ll tm1=1+dp1(od-1,ev,1,sum1+1,sum2);
            ll tm2=dp1(od,ev-1,1,sum1+1,sum2);
            if((sum1+tm1)%2==0||(sum1+tm2)%2==0)
            {
                ans=0;
            }
        }
        else if(od>0)
        {
            ll tm1=1+dp1(od-1,ev,1,sum1+1,sum2);
            if((sum1+tm1)%2==0)
            {
                ans=0;
            }
        }
        else
        {
            ll tm2=dp1(od,ev-1,1,sum1+1,sum2);
            if((sum1+tm2)%2==0)
            {
                ans=0;
            }
        }
    }
    else
    {
        ans=0;
        if(od>0&&ev>0)
        {
            ll tm1=1+dp1(od-1,ev,1,sum1,sum2+1);
            ll tm2=dp1(od,ev-1,1,sum1,sum2+1);
            if((sum2+tm1)%2==1||(sum2+tm2)%2==1)
            {
                ans=0;
            }
        }
        else if(od>0)
        {
            ll tm1=1+dp1(od-1,ev,1,sum1+1,sum2);
            if((sum1+tm1)%2==0)
            {
                ans=0;
            }
        }
        else
        {
            ll tm2=dp1(od,ev-1,1,sum1+1,sum2);
            if((sum1+tm2)%2==0)
            {
                ans=0;
            }
        }
    }
    return mem[od][ev][type]=ans;
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
        ll even=0,odd=0;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            a+=INT_MAX;
            a%=2;
            if(a==0)even++;
            else odd++;
        }

    }
    return 0;
}






