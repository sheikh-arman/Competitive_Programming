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
ll mem[210][210];
ll mod=998244353;
ll dp(ll n,ll k)
{
    if(k>n)
    {
        return 0;
    }
    if(k==n||k==0)
    {
        return 1;
    }
    if(mem[n][k]>0)
    {
        return mem[n][k]%mod;
    }
    return mem[n][k]=(dp(n-1,k)+dp(n-1,k-1))%mod;
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
        if(n==2)
        {
            cout<<"1 0 1\n";
            continue;
        }
        if(n==4)
        {
            cout<<"3 2 1\n";
            continue;
        }
        ll val=dp(n,n/2);
        // cout<<val<<" x\n";

        if((n/2)%2==0)
        {
            ll po=pow(2,(n/2)-1);
            po%=mod;
            //val-=po;
            //if(val<0)val+=mod;
            ll alex=(val/2)+po;
            alex-=1;
            if(alex<0)alex+=mod;
            alex%=mod;
            ll bob=(val/2)-po;
            cout<<alex<<" "<<bob<<" 1\n";
        }
        if(1)
        {
            ll po=pow(2,(n/2)-1);
            po%=mod;
            val-=po;
            if(val<0)val+=mod;


            ll alex=(val/2)+po;
            alex%=mod;
            ll bob=(val/2)-1;
            if(bob<0)bob+=mod;
            cout<<alex<<" "<<bob<<" 1\n";
        }
    }
    return 0;
}






