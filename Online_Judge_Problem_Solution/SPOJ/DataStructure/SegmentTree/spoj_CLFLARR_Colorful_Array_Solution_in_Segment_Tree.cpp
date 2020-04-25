/*
    Sk arman Hossain
    University of Barisal

    Problem name : spoj_CLFLARR_Colorful_Array
    Solution : segment tree
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 200010
ll seg_tree[3*N];
ll update_value[N+10];
void update(ll n,ll b,ll e,ll i,ll j,ll up_no)
{
    if(b>=i&&e<=j)
    {
        seg_tree[n]=up_no;
        return;
    }
    if(e<i||b>j)
    {
        return;
    }
    update(n*2,b,(b+e)/2,i,j,up_no);
    update(n*2+1,(b+e)/2+1,e,i,j,up_no);
}
ll query(ll n,ll b,ll e,ll i,ll up_no=0)
{
    if(b>=i&&e<=i)
    {
        return max(up_no,seg_tree[n]);
    }
    if(e<i||b>i)
    {
        return 0;
    }
    ll p=query(n*2,b,(b+e)/2,i,max(up_no,seg_tree[n]));
    ll q=query(n*2+1,(b+e)/2+1,e,i,max(up_no,seg_tree[n]));
    return max(p,q);

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);

    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,q;
        cin>>n>>q;
        for(ll i=0; i<q; i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            update(1,1,n,a,b,i+1);
            update_value[i+1]=c;
        }
        for(ll i=1;i<=n;i++){
            ll ans=query(1,1,n,i);
            cout<<update_value[ans]<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
