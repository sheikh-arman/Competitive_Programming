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
#define N 200010
vector<ll>block;
ll ar[N],len;
void sqrt_decompose(ll n)
{
    len = (ll) sqrt (n + .0) + 1;
    block.resize(len);
    for (int i=0; i<n; ++i)
    {
        block[i / len] += ar[i];
    }
}
ll sqrt_query(ll l,ll r)
{
    ll sum = 0;
    int c_l = l / len,   c_r = r / len;
    if (c_l == c_r)
    {
        for (int i=l; i<=r; ++i)
        {
            sum += ar[i];
        }
    }
    else
    {
        for (int i=l, ending=(c_l+1)*len-1; i<=ending; ++i)
        {
            sum += ar[i];
        }
        for (int i=c_l+1; i<=c_r-1; ++i)
        {
            sum += block[i];
        }
        for (int i=c_r*len; i<=r; ++i)
        {
            sum += ar[i];
        }
    }
    return sum;
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
        ll n,sum=0;



    }
    return 0;
}





