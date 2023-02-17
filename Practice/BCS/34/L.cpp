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
ll query(ll x,ll y)
{
    cout<<"1 "<<x<<" "<<y<<"\n";
    string s;
    cin>>s;
    if(s=="TAK")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    fflush(stdout);
    ll tcase=1;
    // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        cin>>n>>k;
        if(n==2)
        {
            cout<<"2 1 2\n";
            continue;
        }
        ll left=1,right=n;
        ll init=n;
        while(left<=right)
        {
            if(left==n)break;
            ll mid=(left+right)/2;
            ll val=query(mid,mid+1);
            if(val)
            {
                init=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        left=1,right=init;
        ll ans;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            ll val=query(init,mid);
            if(val)
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        left=1,right=ans-1;
        init=-1;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            ll val=query(mid,mid+1);
            if(val)
            {
                init=mid;
                break;
            }
            else
            {
                left=mid+1;
            }
        }
        if(init!=-1)
        {
            left=1,right=init;
            ll ans2;
            while(left<=right)
            {
                ll mid=(left+right)/2;
                ll val=query(mid,init);
                if(val)
                {
                    ans2=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            cout<<"2 "<<ans<<" "<<ans2<<"\n";
        }
        else
        {
            left=ans+1,right=n;
            while(left<=right)
            {
                ll mid=(left+right)/2;
                ll val=query(mid+1,mid);
                if(val)
                {
                    init=mid+1;
                    break;
                }
                else
                {
                    left=mid+1;
                }
            }
            left=init,right=n;
            ll ans2;
            while(left<=right)
            {
                ll mid=(left+right)/2;
                ll val=query(mid,init);
                if(val)
                {
                    ans2=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            cout<<"2 "<<ans<<" "<<ans2<<"\n";
        }

    }
    return 0;
}




