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
vector<ll>seg[400010];
ll ar[100010];
void build(ll n, ll b,ll e)
{
    if(b==e)
    {
        seg[n].PB(ar[b]);
        return;
    }
    ll left=n*2;
    ll right=(n*2)+1;
    build(left,b,(b+e)/2);
    build(right,((b+e)/2)+1,e);
    merge(seg[left].begin(), seg[left].end(), seg[right].begin(), seg[right].end(),back_inserter(seg[n]));
}
ll query(ll n,ll b,ll e,ll l,ll r,ll val)
{
    if(b>=l&&e<=r)
    {
        ll ck=0;
        ll pos=lower_bound(seg[n].begin(),seg[n].end(),val)-seg[n].begin();
        if(pos<(e-b+1))
        {
            if(seg[n][pos]==val){
//                cout<<n<<" "<<val<<" x\n";
//                for(ll i:seg[n]){
//                    cout<<i<<" ";
//                }
//                cout<<"\n";
                ck=1;
            }
        }
        return ck;
    }
    if(b>r||e<l)return 0;
    ll mid=(b+e)/2;
    ll left=2*n;
    ll right=2*n+1;
    ll p=query(left,b,mid,l,r,val);
    ll q=query(right,mid+1,e,l,r,val);
    return p+q;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,q;
        cin>>n>>q;
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
        }
        build(1,1,n);
        for(ll i=0; i<q; i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            if(a>b)swap(a,b);
            ll ans=query(1,1,n,a,b,c);
            if(ans)
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }

    }
    return 0;
}
