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
vector<ll>V,cnt;
ll mem[100010],n;
ll dp(ll pos)
{
    if(pos>=n)
    {
        return 0;
    }
    if(mem[pos]!=-1)
    {
        return mem[pos];
    }
    ll ans=LONG_LONG_MAX;
    if(V[pos]%2==0)
    {
        if(pos+1<n)
        {
            if(V[pos+1]%2==0)
            {
                ans=min(ans,dp(pos+1));
                ans=min(ans,dp(pos+2));
            }
            else
            {
                ans=min(ans,dp(pos+2)+cnt[pos]+1);
                ans=min(ans,dp(pos+1));
            }
        }
        else
        {
            ans=min(ans,dp(pos+1));
        }
    }
    else
    {
        if(pos+1<n)
        {
            if(V[pos+1]%2==0)
            {
                ans=min(ans,dp(pos+2)+cnt[pos+1]+1);
                ans=min(ans,dp(pos+1)+cnt[pos]);
            }
            else
            {
                ans=min(ans,dp(pos+2)+1);
                ans=min(ans,dp(pos+1)+cnt[pos]);
            }
        }
        else
        {
            ans=min(ans,dp(pos+1)+cnt[pos]);
        }
    }
    return mem[pos]=ans;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        cnt.clear();
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        for(ll i:V)
        {
            ll num=i;
            ll cn=0;
            if(num%2==0)
            {
                while(num%2==0)
                {
                    num/=2;
                    cn++;
                }
                cnt.PB(cn);
            }
            else
            {
                while(num%2)
                {
                    num/=2;
                    cn++;
                }
                cnt.PB(cn);
            }
            //cout<<cn<<" t\n";
        }
        for(ll i=0; i<n; i++)
        {
            mem[i]=-1;
        }
        ll ans=dp(0);
        cout<<ans<<"\n";
    }
    return 0;
}




