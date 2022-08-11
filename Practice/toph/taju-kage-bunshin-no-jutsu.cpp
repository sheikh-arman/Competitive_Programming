/*
    Sk arman Hossain
    University of Barisal

    Problem name : toph-Taju Kage Bunshin No Jutsu
    Algorithm : Merge Sort Tree
 */
#include<bits/stdc++.h>
typedef unsigned long long int ull;
using namespace std;
typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define N 200100
ordered_set m_tree[4*N];
ll ar[N];
void merg(ordered_set v1,ordered_set v2,ll n)
{
    ll siz1=v1.size();
    ll siz2=v2.size();
    ll left=0,right=0;
    m_tree[n].clear();
    while(left<siz1)
    {
        ll x=*v1.find_by_order(left);
        m_tree[n].insert(x);
        left++;
    }
    while(right<siz2)
    {
        m_tree[n].insert(*v2.find_by_order(right));
        right++;
    }
}
ll merge_sort_tree(ll n,ll b,ll e)
{
    if(b==e)
    {
        if(ar[b]!=-1)
        {
            m_tree[n].insert(ar[b]);
        }
        return 0;
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid = (b+e)/2;
    ll p=merge_sort_tree(left,b,mid);
    ll q=merge_sort_tree(right,mid+1,e);
    merg(m_tree[left],m_tree[right],n);
    return 0;
}
ll update(ll n,ll b,ll e,ll i,ll r, ll val)
{
    if(b>=i&&e<=r)
    {
        m_tree[n].clear();
        if(ar[b]!=-1)
        {
            m_tree[n].insert(ar[b]);
        }
//        if(ar[i]==-1)
//        {
//            m_tree[n].erase(val);
//        }
        return 0;
    }
    if(b>r||e<i)
    {
        return 0;
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid = (b+e)/2;
    ll p=update(left,b,mid,i,r,val);
    ll q=update(right,mid+1,e,i,r,val);
    if(ar[i]==-1)
    {
        m_tree[n].erase(val);
    }
    if(ar[i]!=-1)
    {
        m_tree[n].insert(ar[i]);
    }
    return 0;
}
ll query(ll n,ll b,ll e,ll i,ll r,ll val)
{
    if(b>=i&&e<=r)
    {
        ll x=m_tree[n].order_of_key(val);
        return x;
    }
    if(b>r||e<i)
    {
        return 0;
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid = (b+e)/2;
    ll p=query(left,b,mid,i,r,val);
    ll q=query(right,mid+1,e,i,r,val);
    return p+q;
}
int main()
{
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ordered_set V;
    memset(ar,-1,sizeof(ar));
    ll n;
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&ar[i]);
        V.insert(ar[i]);
    }
    ll hi=merge_sort_tree(1,1,200001);
    ll quy;
    scanf("%lld",&quy);
    for(ll i=0; i<quy; i++)
    {
        ll a;
        scanf("%lld",&a);
        if(a==1)
        {
            ll b;
            scanf("%lld",&b);
            n++;
            ll pr=ar[n];
            ar[n]=b;
            ll tt=update(1,1,200001,n,n,pr);
            V.insert(b);
        }
        else if(a==2)
        {
            V.erase(ar[n]);
            ll pr=ar[n];
            ar[n]=-1;
            ll tt = update(1, 1, 200001, n, n, pr);
            n--;
        }
        else
        {
            ll l,r,pos;
            scanf("%lld %lld %lld",&l,&r,&pos);
            ll l2,r2;
            ll idx,b=0,e=n-1;
            ll k=r-l+1;
            k-=pos;
            while(b<=e)
            {
                ll  mid=b+(e-b)/2;
                ll index=query(1,1,200001,l,r,*V.find_by_order(mid));
                if(index<=k)
                {
                    idx=mid;
                    b=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
            printf("%lld\n",*V.find_by_order(idx));
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
