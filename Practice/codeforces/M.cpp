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
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        cin>>n>>k;
        ll odd=0,ev=0;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            if(a%2)
            {
                odd++;
            }
            else
            {
                ev++;
            }
        }
        ll cnt=n-k;
        ll ck=0;
        if(cnt%2)
        {
            ll b=cnt/2;
            ll a=b+1;
            if(odd<=b)
            {
                ck=1;
            }
            else if(a<=ev)
            {

            }
            else if(ev<=b)
            {
                if((ev+odd)%2)
                {

                }
                else
                {
                    ck=1;
                }
            }
        }
        else
        {
            ll b=cnt/2;
            ll a=b;
            if(odd<=b)
            {
                ck=1;
            }
            if(ev<=a)
            {
                if((ev+odd)%2)
                {

                }
                else
                {
                    ck=1;
                }
            }
        }
        if(ck)
        {
            cout<<"Daenerys\n";
        }
        else
        {
            cout<<"Stannis\n";
        }
    }
    return 0;
}




