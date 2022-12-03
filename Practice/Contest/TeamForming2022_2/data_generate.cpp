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
ll rep[100010];
ll Find(ll node)
{
    return (node==rep[node]?node:rep[node]=Find(rep[node]));
}
int main()
{
    //freopen("1input.txt","r",stdin);
    freopen("input12.txt","w",stdout);
    //fast;
    ll tcase=1;
    // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n=10000,q=100000;
        cout<<n<<"\n";
        for(ll i=0; i<=n; i++)
        {
            rep[i]=i;
        }
        ll tm1=42,tm2=542,tm3=41,tm4=98;
        for(ll i=0; i<n; i++)
        {
            ll a=(rand()+tm1)%100;
            a++;
            cout<<a<<" ";
            tm1*=21;
            tm1%=100;
            tm1++;
        }
        cout<<"\n";
        ll cnt=1;
        for(ll i=1; cnt<n ; i++)
        {
            ll a=(rand()+tm1)%n;
            ll b=(rand()+tm2)%n;
            a++;
            b++;
            if(Find(a)!=Find(b))
            {
                cnt++;
                rep[Find(a)]=Find(b);
                cout<<a<<" "<<b<<"\n";
            }
            tm1*=4;
            tm1%=n;
            tm1++;
            tm2*=8;
            tm2%=n;
            tm2++;
        }
        cout<<q<<"\n";
        for(ll i=0; i<q; i++)
        {
            ll a=(rand()+tm1)%n;
            ll b=(rand()+tm2)%n;
            ll x=(rand()+tm3)%100;
            x++;
            a++;
            b++;
            cout<<a<<" "<<b<<" "<<x<<"\n";
            tm1*=24;
            tm1%=n;
            tm1++;
            tm2*=42;
            tm2%=n;
            tm2++;
            tm3*=41;
            tm3%=n;
            tm3++;
        }
    }
    return 0;
}
