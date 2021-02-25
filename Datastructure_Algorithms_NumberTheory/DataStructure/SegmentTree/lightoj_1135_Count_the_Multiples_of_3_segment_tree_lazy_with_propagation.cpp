#include<bits/stdc++.h>
#define N 100101
#define sf(n) scanf("%d", &n)
typedef long long int ll;
using namespace std;
struct tree{
    ll mod0,mod1,mod2,prop;
}s_tree[N*4];
ll segmentTree(ll n,ll b,ll e)
{
    if(b==e)
    {
       s_tree[n].mod0=1;
       s_tree[n].mod2=0;
       s_tree[n].mod1=0;
       s_tree[n].prop=0;
       return s_tree[n].mod0;
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    segmentTree(l,b,mid);
    segmentTree(r,mid+1,e);
    s_tree[n].mod0=s_tree[l].mod0+s_tree[r].mod0;
    s_tree[n].mod1=s_tree[l].mod1+s_tree[r].mod1;
    s_tree[n].mod2=s_tree[l].mod2+s_tree[r].mod2;
    s_tree[n].prop=0;
    return s_tree[n].mod0;
}
ll query(ll n,ll b,ll e,ll i,ll j,ll carry)
{
    if(b>j||e<i)
    {
        return 0;
    }
    if(b>=i&&e<=j)
    {
        carry=carry%3;
        if(carry==0){
             return s_tree[n].mod0;
        }
        else if(carry==1){
             return s_tree[n].mod2;
        }
        else{
             return s_tree[n].mod1;
        }
    }
    ll l=n*2;
    ll r=(n*2) + 1;
    ll mid=(e+b)/2;
    ll p=query(l,b,mid,i,j,carry+s_tree[n].prop);
    ll q=query(r,mid+1,e,i,j,carry+s_tree[n].prop);
    return p+q;
}
ll update(ll n,ll b,ll e,ll x,ll y){
    if(b>y||e<x)
    {
        return 0;
    }
    if(b>=x&&e<=y)
    {
       ll tmp=s_tree[n].mod0;
       s_tree[n].mod0=s_tree[n].mod2;
       s_tree[n].mod2=s_tree[n].mod1;
       s_tree[n].mod1=tmp;
       s_tree[n].prop+=1;
       //s_tree[n].prop=s_tree[n].prop%3;
       return s_tree[n].mod0;
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    update(l,b,mid,x,y);
    update(r,mid+1,e,x,y);
    s_tree[n].mod0=s_tree[l].mod0+s_tree[r].mod0;
    s_tree[n].mod1=s_tree[l].mod1+s_tree[r].mod1;
    s_tree[n].mod2=s_tree[l].mod2+s_tree[r].mod2;
    ll tm=s_tree[n].prop;
    tm%=3;
    if(tm==1){
        ll tmp=s_tree[n].mod0;
       s_tree[n].mod0=s_tree[n].mod2;
       s_tree[n].mod2=s_tree[n].mod1;
       s_tree[n].mod1=tmp;
    }
    else if(tm==2){
        ll tmp=s_tree[n].mod0;
       s_tree[n].mod0=s_tree[n].mod1;
       s_tree[n].mod1=s_tree[n].mod2;
       s_tree[n].mod2=tmp;
    }
    return s_tree[n].mod0;
}
int main()
{
    ///freopen("input.txt","r",stdin);
    int tcase=1;
    int cnt=0;
    sf(tcase);
    while(tcase--)
    {
        memset(s_tree,0,sizeof(s_tree));
        ll n,q,a,b,c,l,r,v;
        ll ans;
        scanf("%lld%lld",&n,&q);
        segmentTree(1, 1, n);
        printf("Case %d:\n",++cnt);
        for(int i=0; i<q; i++)
        {
            scanf("%lld",&a);
            if(a==0){
                scanf("%lld%lld",&l,&r);
                update(1,1,n,l+1,r+1);
            }
            else{
                scanf("%lld%lld",&b,&c);
                 ans=query(1,1,n,b+1,c+1,0);
                printf("%lld\n",ans);
            }
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



