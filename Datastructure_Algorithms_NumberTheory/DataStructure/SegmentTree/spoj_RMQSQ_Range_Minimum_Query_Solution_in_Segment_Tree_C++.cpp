/*
    Sk arman Hossain
    University of Barisal
    Problem name : SPOJ RMQSQ_Range_Minimum_Query
    Algorithm : Segment Tree
 */

#include<bits/stdc++.h>
#define PB push_back
typedef long long int ll;
using namespace std;
ll ar[100100],tree[400100];
void build(ll n,ll b,ll e)
{
    if(b==e)
    {
        tree[n]=ar[b];
        return;
    }
    else
    {
        build(n*2,b,(b+e)/2);
        build(n*2+1,((b+e)/2)+1,e);
        tree[n]=min(tree[n*2],tree[n*2+1]);
    }

}
ll query(ll n,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i)
    {
        return LONG_MAX;
    }
    if(b>=i&&e<=j)
    {
        return tree[n];
    }
    return min(query(n*2,b,(b+e)/2,i,j),query(n*2+1,(b+e)/2+1,e,i,j));
}

int main()
{
    //freopen("1input.txt","r",stdin);
    ll tcase=1;
    //scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        scanf("%lld",&n);
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&ar[i]);
        }
        build(1,1,n);
        ll qu;
        scanf("%lld",&qu);
        for(ll i=0; i<qu; i++)
        {
            ll a,b;
            scanf("%lld%lld",&a,&b);
            a++;
            b++;
            ll ans=query(1,1,n,a,b);
            printf("%lld\n",ans);
        }
    }

}
