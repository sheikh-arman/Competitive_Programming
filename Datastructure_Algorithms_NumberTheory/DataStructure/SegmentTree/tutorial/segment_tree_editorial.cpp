/*
    Sk arman Hossain
    University of Barisal

    Problem name : range minimun query
    Solution : segment tree
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 200010
ll seg_tree[3*N];
ll ar[N+10];
ll build(ll n,ll b,ll e)
{
    if(b==e)
    {
        seg_tree[n]=ar[b];
        return seg_tree[n];
    }
    ll p=build(n*2,b,(b+e)/2);
    ll q=build(n*2+1,(b+e)/2+1,e);
    return seg_tree[n]=min(p,q);
}
ll query(ll n,ll b,ll e,ll i,ll j)
{
    if(b>=i&&e<=j)
    {
        return seg_tree[n];
    }
    if(e<i||b>j)
    {
        return LONG_MAX;
    }
    ll p=query(n*2,b,(b+e)/2,i,j);
    ll q=query(n*2+1,(b+e)/2+1,e,i,j);
    return min(p,q);

}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,qry;
        cin>>n;
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
        }
        ll x=build(1,1,n);
        cin>>qry;
        while(qry--){
            ll l,r;
            cin>>l>>r;
            if(l>r)swap(l,r);
            ll ans=query(1,1,n,l,r);
            cout<<ans<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
