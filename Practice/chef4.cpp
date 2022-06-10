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
bitset<100010>color;
vector<ll>prime;
void seive()
{
    prime.PB(2);
    for(ll i=3; i<=40010; i+=2)
    {
        if(color[i]==0)
        {
            prime.PB(i);
            for(ll j=i*i; j<=40010; j+=(i+i))
            {
                color[j]=1;
            }
        }
    }
}
ll nod(ll n)
{
    ll ans=1;
    for(ll i:prime)
    {
        if(i*i>n)
        {
            break;
        }
        ll cnt=1;
        while(n%i==0)
        {
            n/=i;
            cnt++;
        }
        ans*=cnt;
    }
    if(n>1)ans*=2;
    return ans;
}
int main()
{
    seive();
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll a,b;
        cin>>a>>b;
        if(a<b)swap(a,b);
        ll gcd=a-b;
        ll ans=nod(gcd);
        cout<<ans<<"\n";
    }
    return 0;
}




