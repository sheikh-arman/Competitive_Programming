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
ll seg[2000000];
ll ar[300010];
void build(ll n,ll b,ll e)
{
    if(b==e)
    {
        seg[n]=ar[b];
        return;
    }
    ll left=n*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    seg[n]=min(seg[left],seg[right]);
}
ll query(ll n,ll b,ll e,ll l,ll r)
{
    if(l>r)return 0;
    if(b>=l&&e<=r)
    {
        return seg[n];
    }
    if(b>r||e<l)
    {
        return 10000000000000;
    }
    ll left=n*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    ll p=query(left,b,mid,l,r);
    ll q=query(right,mid+1,e,l,r);
    return min(p,q);
}
ll n;
ll pos[300010];
ll po[300010];
ll bin_1(ll l,ll r,ll val)
{
    ll ans=1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll v=query(1,1,n,1,mid);
        if(v<val)
        {
            r=mid-1;
        }
        else
        {
            ans=mid;
            l=mid+1;
        }
    }
    return ans;
}
ll bin_2(ll l,ll r,ll val)
{
    ll ans=1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll v=query(1,1,n,mid,n);
        if(v<val)
        {
            l=mid+11;
        }
        else
        {
            ans=mid;
            r=mid-1;
        }
    }
    return ans;
}
ll sol(ll val)
{
    ll value=ar[val];
    ll seg1_l=1,seg1_r=val-1;
    ll seg2_l=val+1, seg2_r=n;
    if( seg1_l<=seg1_r && seg2_l<=seg2_r)
    {
        ll ma=query(1,1,n,seg1_l,seg1_r);
        ll ma2=query(1,1,n,seg2_l,seg2_r);
        if(ma<=value&&ma2<=value)
        {
            return 0;
        }
        if(ma2<value)
        {
            ll total=seg1_r-seg1_l+1;
            ll l=bin_1(seg1_l,seg1_r,value);
            ll r=bin_2(seg1_l,seg1_r,value);
            ll extra1=l-1;
            ll extra2=(val-1)-r;
            return (extra1+1)*(extra2+1);
        }
        if(ma<value)
        {
            ll total=seg2_r-seg2_l+1;
            ll l=bin_1(seg2_l,seg2_r,value);
            ll r=bin_2(seg2_l,seg2_r,value);
            ll extra1=l-(val+1);
            ll extra2=n-r;
            return (extra1+1)*(extra2+1);
        }
    }
    else
    {
        if(seg1_l<=seg1_r)
        {
            ll ma=query(1,1,n,seg1_l,seg1_r);

            ll total=seg1_r-seg1_l+1;
            ll l=bin_1(seg1_l,seg1_r,value);
            ll r=bin_2(seg1_l,seg1_r,value);
            ll extra1=l-1;
            ll extra2=(val-1)-r;
            return (extra1+1)*(extra2+1);
        }
        if(seg2_l<=seg2_r)
        {
            ll ma2=query(1,1,n,seg2_l,seg2_r);

            ll total=seg2_r-seg2_l+1;
            ll l=bin_1(seg2_l,seg2_r,value);
            ll r=bin_2(seg2_l,seg2_r,value);
            ll extra1=l-(val+1);
            ll extra2=n-r;
            return (extra1+1)*(extra2+1);
        }
    }
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

        vector<ll>V;
        cin>>n;
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
            pos[ar[i]]=i;
        }
        build(1,1,n);
        for(ll i=1; i<=n; i++)
        {
            ll ans;
            if(i==n)
            {
                ans=1;
            }
            else
            {
                ans=sol(pos[i]);
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
