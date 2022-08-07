`/*
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
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>V,distinct;
        for(ll i=0; i<m; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        VST(V);
        for(ll i=0; i<m; i++)
        {
            if(V[i]==0)continue;
            for(ll j=i+1; j<m; j++)
            {
                if(V[j]%V[i]==0)
                {
                    V[j]=0;
                }
            }
        }
        for(ll i=0; i<m; i++)
        {
            if(V[i]>0&&V[i]<=n)
            {
                distinct.PB(V[i]);
            }
        }
        m=distinct.size();
        ll ans=0;
        for(ll i=1; i<(1<<m); i++)
        {
            ll cnt=0,pos=0;
            ll num=i,mul=1;
            while(num)
            {
                if(num%2)
                {
                    mul=(mul*distinct[pos])/__gcd(mul,distinct[pos]);
                    cnt++;
                }
                pos++;
                num/=2;
                if(mul>n)continue;
            }
            if(mul>n)continue;
            if(cnt%2)
            {
                ans+=(n/mul);
            }
            else
            {
                ans-=(n/mul);
            }
        }
        cout<<"Case "<<test<<": "<<n-ans<<"\n";
    }
    return 0;
}
/*
Special case
1
20 2
4 6
Ans: 13

*/


