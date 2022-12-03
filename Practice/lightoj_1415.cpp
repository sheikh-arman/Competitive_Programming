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
ll dp[200010];
ll ar[200010];
ll height[200010];
ll jump[200010];
ll cnt[200010];
#define N 200010
ll seg_tree[3*N];
ll build(ll n,ll b,ll e)
{
    if(b==e)
    {
        seg_tree[n]=height[b];
        return seg_tree[n];
    }
    ll p=build(n*2,b,(b+e)/2);
    ll q=build(n*2+1,(b+e)/2+1,e);
    return seg_tree[n]=max(p,q);
}
ll query(ll n,ll b,ll e,ll i,ll j)
{
    if(b>=i&&e<=j)
    {
        return seg_tree[n];
    }
    if(e<i||b>j)
    {
        return 0;
    }
    ll p=query(n*2,b,(b+e)/2,i,j);
    ll q=query(n*2+1,(b+e)/2+1,e,i,j);
    return max(p,q);

}
ll bin(ll l,ll r,ll n)
{
    ll left=l,right=r;
    ll ans=l;
    while(left<=right)
    {
        ll mid=(left+right)/2;
        ll qu=query(1,1,n,l,mid);
        if(qu<=height[l])
        {
            ans=mid;
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return ans;
}
int main()
{
    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<=200002; i++)
        {
            cnt[i]=0;
            dp[i]=0;
            height[i]=0;
        }
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i]>>height[i];
        }
        build(1,1,n);
        ll left=n,right=n;
        while(left>=1)
        {
            ll val=ar[left];
            cnt[val]++;
            left--;
            while(cnt[val]>1)
            {
                ll new_val=ar[right];
                cnt[new_val]--;
                right--;
            }
            jump[left+1]=right+1;
        }
        for(ll i=n; i>=1; i--)
        {
            ll valueForQuery=query(1,1,n,i,jump[i]-1);
            ll bi=bin(i,jump[i]-1,n);
            ll ans=min(height[i]+dp[bi+1],valueForQuery+dp[jump[i]]);
            dp[i]=ans;
        }
        cout<<"Case "<<test<<": "<<dp[1]<<"\n";
    }
    return 0;
}






