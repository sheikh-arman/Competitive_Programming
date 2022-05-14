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

//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree2<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> policy_set;

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
#define N 101010
ll tree[3*N];
ll seg_tree2[3*N];
ll ar[N+10];
ll ar2[N+10];
ll build(ll n,ll b,ll e)
{
    if(b==e)
    {
        return tree[n]=ar[b];
    }
    ll p=build(n*2,b,(b+e)/2);
    ll q=build(n*2+1,(b+e)/2+1,e);
    return tree[n]=p+q;
}
ll query(ll n,ll b,ll e,ll l,ll r)
{
    if(b>=l&&e<=r)
    {
        return tree[n];
    }
    else if(e<l||b>r)
    {
        return 0;
    }
    ll p=query(n*2,b,(b+e)/2,l,r);
    ll q=query(n*2+1,(b+e)/2+1,e,l,r);
    return p+q;
}
ll update(ll n,ll b,ll e,ll l,ll r)
{
    if(b>=l&&e<=r)
    {
        return tree[n]=ar[b];
    }
    else if(e<l||b>r)
    {
        return tree[n];
    }
    ll p=update(n*2,b,(b+e)/2,l,r);
    ll q=update(n*2+1,(b+e)/2+1,e,l,r);
    return tree[n]=p+q;
}


//ll build2(ll n,ll b,ll e)
//{
//    if(b==e)
//    {
//        seg_tree2[n]=ar2[b];
//        return seg_tree2[n];
//    }
//    ll p=build2(n*2,b,(b+e)/2);
//    ll q=build2(n*2+1,(b+e)/2+1,e);
//    return seg_tree2[n]=p+q;
//}
//ll query2(ll n,ll b,ll e,ll i,ll j)
//{
//    if(b>=i&&e<=j)
//    {
//        return seg_tree2[n];
//    }
//    if(e<i||b>j)
//    {
//        return 0;
//    }
//    ll p=query2(n*2,b,(b+e)/2,i,j);
//    ll q=query2(n*2+1,(b+e)/2+1,e,i,j);
//    return p+q;
//
//}
//ll update2(ll n,ll b,ll e,ll i,ll j)
//{
//    if(b>=i&&e<=j)
//    {
//        seg_tree2[n]=ar2[b];
//        return seg_tree2[n];
//    }
//    if(e<i||b>j)
//    {
//        return seg_tree2[n];
//    }
//    ll p=update2(n*2,b,(b+e)/2,i,j);
//    ll q=update2(n*2+1,(b+e)/2+1,e,i,j);
//    return seg_tree2[n]=p+q;
//}
ll build2(ll n,ll b,ll e)
{
    if(b==e)
    {
        return seg_tree2[n]=ar2[b];
    }
    ll p=build2(n*2,b,(b+e)/2);
    ll q=build2(n*2+1,(b+e)/2+1,e);
    return seg_tree2[n]=p+q;
}
ll query2(ll n,ll b,ll e,ll l,ll r)
{
    if(b>=l&&e<=r)
    {
        return seg_tree2[n];
    }
    else if(e<l||b>r)
    {
        return 0;
    }
    ll p=query2(n*2,b,(b+e)/2,l,r);
    ll q=query2(n*2+1,(b+e)/2+1,e,l,r);
    return p+q;
}
ll update2(ll n,ll b,ll e,ll l,ll r)
{
    if(b>=l&&e<=r)
    {
        return seg_tree2[n]=ar2[b];
    }
    else if(e<l||b>r)
    {
        return seg_tree2[n];
    }
    ll p=update2(n*2,b,(b+e)/2,l,r);
    ll q=update2(n*2+1,(b+e)/2+1,e,l,r);
    return seg_tree2[n]=p+q;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,q;
        cin>>n>>q;
        for(ll i=1; i<=n; i++)
        {
            ar[i]=ar2[i]=0;
        }
        ll x=build(1,1,n);
        ll y=build2(1,1,n);
        for(ll i=0; i<q; i++)
        {
            ll a;
            cin>>a;
            if(a==1)
            {
                cin>>x>>y;
                ar[y]=1;
                ar2[x]=1;
                ll tt=update(1,1,n,y,y);
                tt=update2(1,1,n,x,x);
            }
            else if(a==2)
            {
                cin>>x>>y;
                ar[y]=0;
                ar2[x]=0;
                ll tt=update(1,1,n,y,y);
                tt=update2(1,1,n,x,x);
            }
            else
            {
                ll x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                ll ans=0;
                ll tt=query(1,1,n,y1,y2);
                ll tt2=query2(1,1,n,x1,x2);
                if(tt==((y2-y1)+1)||tt2==((x2-x1)+1))
                {
                    cout<<"Yes\n";
                }
                else
                {
                    cout<<"No\n";
                }
            }
        }
    }
    return 0;
}





