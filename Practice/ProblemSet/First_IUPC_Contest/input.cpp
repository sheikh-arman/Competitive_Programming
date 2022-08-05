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
    freopen("16input.txt","w",stdout);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    cout<<tcase<<"\n";
    ll cn=3;
    for(ll test=1; test<=tcase; test++)
    {
        ll n=(rand()+cn)%10001;
        ll q=(rand()+cn)%100001;
        n=1000;
        q=0;
        for(ll i=1;i<n;i++){
            for(ll j=i;j<=n;j++){
                q++;
            }
        }
        cout<<n<<" "<<q<<"\n";
        for(ll i=0;i<n;i++){
            ll a=(rand()+cn)%100000001;
            cout<<a<<" ";
        }
        cout<<"\n";
        ll cn2=23;
        ll x=(rand()+cn2)%100000001;
        for(ll i=1;i<n;i++){
            for(ll j=i;j<=n;j++){
                ll x=(rand()+cn2)%100000001;
                cn2+=1000;
                if((i+j)%2!=0){
                    ll pos=(rand()+cn)%(n+1);
                    cout<<"2 "<<pos<<" "<<x<<"\n";
                }
                else{
                    cout<<"1 "<<i<<" "<<j<<" "<<x<<"\n";
                }

            }
        }
        cn+=23;
    }
    return 0;
}




