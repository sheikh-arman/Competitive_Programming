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
    freopen("input5.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n=100000;
        cout<<n<<"\n";
        ll val1=131;
        ll val2=1233;
        ll val3=1133;
        ll val4=1231;
        for(ll i=0; i<n; i++)
        {
            ll val=(rand()+val1)%100000;
            ll ck=(rand()+val4)%2;
            if(ck)
            {
                val-=100000;
            }
            cout<<val<<" ";
            val1*=27;
            val1%=100000;
        }
        cout<<"\n";
        ll q=100000;
        cout<<q<<"\n";
        for(ll i=0; i<q; i++)
        {
            ll l,r,x;
            l=(rand()+val2)%n;
            r=(rand()+val3)%n;
            l++;
            r++;
            if(l>r)swap(l,r);
            x=rand()%100000;
            ll ck=(rand()+val4)%2;
            if(ck)
            {
                x-=100000;
            }
            val2*=113;
            val3*=223;
            val4*=31;
            val2%=10000;
            val3%=10000;
            val4%=10000;
//            l=abs(l);
//            r=abs(r);
            cout<<l<<" "<<r<<" "<<x<<"\n";
        }
    }
    return 0;
}





