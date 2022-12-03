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
        ll n=100000,q=100000;
        cout<<n<<"\n";
        for(ll i=0; i<n; i++)
        {
            ll a=(rand()+125)%100000;
            a++;
            cout<<a<<" ";
        }
        cout<<"\n";
        vector<ll>V;
        V.PB(1);
        ll cnt=0;
        for(ll i=2; i<=n ; i++)
        {
            ll x=V[cnt];
            ll y=i;
            cout<<x<<" "<<y<<"\n";
            V.PB(i);
            if(i+1<=n)
            {
                x=V[cnt];
                y=i+1;
                cout<<x<<" "<<y<<"\n";
                V.PB(i+1);
            }
            i++;
            cnt++;
        }
        cout<<q<<"\n";
        for(ll i=0; i<q; i++)
        {
            ll a=(rand())%n;
            ll b=(rand())%n;
            a++;
            b++;
            ll x=(rand()+4312)%100000;
            x++;
            cout<<a<<" "<<n<<" "<<x<<"\n";
        }
    }
    return 0;
}

