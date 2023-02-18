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
#define N 200010
class node
{
public:
    ll prop;
    ll sum;
    ll ar[30];
};
node seg_tree[3*N];
void build(ll n,ll b,ll e)
{
    if(b==e)
    {
        seg_tree[n].prop=-1;
        seg_tree[n].sum=0;
        for(ll j=0;j<26;j++){
            seg_tree[n].ar[j]=0;
        }
        return;
    }
    build(n*2,b,(b+e)/2);
    build((n*2)+1,((b+e)/2)+1,e);
    seg_tree[n].prop=-1;
    seg_tree[n].sum=0;
    for(ll j=0;j<26;j++){
        seg_tree[n].ar[j]=seg_tree[n*2].ar[j]+seg_tree[n*2+1].ar[j];
    }
}
void propagation(ll n,ll b,ll e)
{
    ll mid=(b+e)/2;
    seg_tree[n*2].prop=seg_tree[n].prop;
    seg_tree[(n*2)+1].prop=seg_tree[n].prop;
    seg_tree[n*2].sum=((mid-b)+1)*seg_tree[n*2].prop;
    seg_tree[(n*2)+1].sum=(e-mid)*seg_tree[n*2].prop;
    seg_tree[n].prop=-1;
}
void query(ll n,ll b,ll e,ll i,ll j)
{
    if(b>=i&&e<=j)
    {
        for(ll j=0;j<26;j++){
            res[j]+=seg_tree[n].ar[j];
        }
        return;
    }
    if(e<i||b>j)
    {
        return;
    }
    if(seg_tree[n].prop!=-1)
        propagation(n,b,e);
    query(n*2,b,(b+e)/2,i,j);
    query(n*2+1,(b+e)/2+1,e,i,j);   
}
void update(ll n,ll b,ll e,ll i,ll j,ll val)
{
    if(b>=i&&e<=j)
    {
        seg_tree[n].prop=val;
        seg_tree[n].sum=val*(e-b+1);  
        return;
    }
    if(e<i||b>j)
    {
        return;
    }
    if(seg_tree[n].prop!=-1)
        propagation(n,b,e);
    update(n*2,b,(b+e)/2,i,j,val);
    update(n*2+1,(b+e)/2+1,e,i,j,val);
    seg_tree[n].sum=seg_tree[2*n].sum+seg_tree[2*n+1].sum;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,q;
        cin>>n>>q;
        build(1,1,n);
        cout<<"Case "<<test<<":"<<"\n";
        for(ll i=0; i<q; i++)
        {
            ll status;
            cin>>status;
            if(status==1)
            {
                ll i,j,val;
                cin>>i>>j>>val;
                i++;
                j++;
                update(1,1,n,i,j,val);
            }
            else
            {
                ll i,j;
                cin>>i>>j;
                i++;
                j++;
                ll ans=query(1,1,n,i,j);
                ll dif=j-i+1;
                //cout<<ans<<" "<<dif<<" x\n";
                ll gcd=__gcd(min(ans,dif),max(ans,dif));
                ans/=gcd;
                dif/=gcd;
                if(dif==1)
                {
                    cout<<ans<<"\n";
                }
                else
                {
                    cout<<ans<<"/"<<dif<<"\n";
                }
            }
        }
    }
    return 0;
}