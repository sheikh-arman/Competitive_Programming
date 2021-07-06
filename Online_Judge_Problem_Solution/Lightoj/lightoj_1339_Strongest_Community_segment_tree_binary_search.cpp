#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
vector<ll>V;
ll seg_tree[1000000];
ll c;
void build(ll n, ll b,ll e)
{
    if(b==e)
    {
        seg_tree[n]=V[b+1]-V[b];
        return;
    }
    ll mid=(b+e)/2;
    build(2*n,b,mid);
    build((2*n)+1,mid+1,e);
    seg_tree[n]=max(seg_tree[2*n],seg_tree[n*2+1]);
}
ll query(ll n,ll b,ll e,ll l,ll r)
{
    if(b>=l&&e<=r)
    {
        return seg_tree[n];
    }
    if(b>r||e<l)
    {
        return 0;
    }
    ll mid=(b+e)/2;
    ll p=query(n*2,b,mid,l,r);
    ll q=query((n*2)+1,mid+1,e,l,r);
    return max(p,q);
}
int main()
{
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,c,q;
        cin>>n>>c>>q;
        ll prev=-1;
        V.clear();
        V.PB(0);
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            if(a!=prev)
            {
                V.PB(i+1);
            }
            prev=a;
        }
        V.PB(n+1);
        build(1,1,c);
        cout<<"Case "<<test<<":"<<"\n";
        for(ll i=0; i<q; i++)
        {
            ll l,r;
            cin>>l>>r;
            ll start=lower_bound(V.begin(),V.end(),l)-V.begin();
            ll en=upper_bound(V.begin(),V.end(),r)-V.begin();
            en-=2;
            ll ans=0;
            if(start>en)
            {
                ll tm=lower_bound(V.begin(),V.end(),r+1)-V.begin();
                if(tm==start)
                {
                    ans=r-l+1;
                }
                else
                {
                    ans=max(V[start]-l,r-V[start]+1);
                }
            }
            else
            {
                ans=query(1,1,c,start,en);
                ans=max(ans,V[start]-l);
                ans=max(ans,r-V[en+1]+1);
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}

