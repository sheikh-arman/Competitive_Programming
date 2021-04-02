#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
vector<ll>Merge[500000];
ll ar[100010];
void merg(vector<ll> a,vector<ll> b,ll node)
{
    ll i=0,j=0;
    ll l1=a.size(),l2=b.size();
    while(i<l1&&j<l2)
    {
        if(a[i]<b[j])
        {
            Merge[node].PB(a[i]);
            i++;
        }
        else
        {
            Merge[node].PB(b[j]);
            j++;
        }
    }
    while(i<l1)
    {
        Merge[node].PB(a[i]);
        i++;
    }
    while(j<l2)
    {
        Merge[node].PB(b[j]);
        j++;
    }
}
ll segmentTree(ll n,ll b,ll e)
{
    if(b==e)
    {
        Merge[n].PB(ar[b]);
        return 1;
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    segmentTree(l,b,mid);
    segmentTree(r,mid+1,e);
    merg(Merge[l],Merge[r],n);
    return 1;
}
ll ck;
ll query(ll n,ll b,ll e,ll i,ll j,ll x)
{
    if(b>j||e<i)
    {
        return 0;
    }
    if(b>=i&&e<=j)
    {
        ll pos=lower_bound(Merge[n].begin(),Merge[n].end(),x)-Merge[n].begin();
        ll siz=Merge[n].size();
        if(pos<siz)
        {
            if(Merge[n][pos]==x)
            {
                pos++;
                ck=1;
            }
        }
        return pos;
    }
    ll l=n*2;
    ll r=(n*2) + 1;
    ll mid=(e+b)/2;
    ll p=query(l,b,mid,i,j,x);
    ll q=query(r,mid+1,e,i,j,x);
    return (p+q);
}
int main()
{
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,q;
        vector<ll>V;
        cin>>n>>q;
        V.PB(-111111111111111);
        for(ll i=1; i<=n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            ar[i]=a;
        }
        ll x=segmentTree(1,1,n);
        sort(V.begin(),V.end());
        for(ll i=0; i<q; i++)
        {
            ll l,r,k;
            cin>>l>>r>>k;
            ll left=1,right=n;
            ll ans;
            while(left<=right)
            {
                ll mid=(left+right)/2;
                ck=0;
                ll pos=query(1,1,n,l,r,V[mid]);
                if(pos==k&&ck)
                {
                    ans=V[mid];
                    break;
                }
                if(pos>=k)
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
