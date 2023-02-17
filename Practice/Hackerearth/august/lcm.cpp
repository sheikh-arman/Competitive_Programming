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
map<pair<ll,ll>,vector<ll>>mp;
ll ma=1e17;
ll lc(ll a,ll b)
{
    ll gcd=__gcd(a,b);
    a/=gcd;
    b/=gcd;
    ll res=a*b*gcd;
    return res;
}
int main()
{
    for(ll i=3; i<=42; i++)
    {
        ll ck=1;
        for(ll j=1; ck; j++)
        {
            ll lcm=1;
            for(ll k=j; k<j+i; k++)
            {
                lcm=lc(lcm,k);
            }
            if(lcm>ma)
            {
                ck=0;
                break;
            }
            else
            {
                mp[ {i,lcm}].PB((j+i)-1);
            }
        }
    }
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll x,r,ans=0;
        cin>>x>>r;
        for(ll i=3; i<=42; i++)
        {
            vector<ll>V=mp[ {i,x}];
            ll siz=V.size();
            for(ll j=0; j<siz; j++)
            {
                if(V[j]<=r)ans++;
            }
            //if(cn>0&&cn<=r)ans++;
        }
        ll sq=sqrt(x);
        if(sq*(sq+1)==x&&(sq+1)<=r)ans++;
        cout<<ans<<"\n";
    }
    return 0;
}




