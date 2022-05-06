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
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
ll seg_tree_bit_sum[900000][34];
ll ar[200010];
void build(ll n,ll b,ll e)
{
    if(b==e)
    {
        ll num=ar[b];
        ll cnt=0;
        if(num==0)seg_tree_bit_sum[n][33]=1;
        while(num)
        {
            if(num==1)
            {
                seg_tree_bit_sum[n][cnt]=1;
            }
            cnt++;
            num/=2;
        }
        return;
    }
    ll mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    for(ll i=0; i<34; i++)
    {
        seg_tree_bit_sum[n][i]=seg_tree_bit_sum[n*2][i]+seg_tree_bit_sum[n*2+1][i];
        // seg_tree_cum[n][i]=seg_tree_cum[n*2][i]+seg_tree_cum[n*2+1][i];
    }
}
ll big,zero,pos,x;
void query(ll n,ll b,ll e,ll l,ll r)
{
    if(b>=l&&e<=r)
    {
        ll temp=0;
        for(ll i=0; i<=pos; i++)
        {
            temp+=seg_tree_bit_sum[n][i];
            //cout<<i<<" "<<seg_tree_bit_sum[]<<
        }
        big+=((e-b)+1)-temp;
        if(x==0)
        {
            big-=seg_tree_bit_sum[n][33];
        }
        for(ll i=0; i<pos; i++)
        {
            zero+=seg_tree_bit_sum[n][i];
            //cout<<i<<" "<<seg_tree_bit_sum[n][i]<<" f\n";
        }
        //zero+=((e-b)+1)-seg_tree_bit_sum[n][pos];
        return;
    }
    if(b>r||e<l)
    {
        return;
    }
    ll mid=(b+e)/2;
    query(n*2,b,mid,l,r);
    query(n*2+1,mid+1,e,l,r);
}
void clr(ll n,ll b,ll e)
{
    if(b==e)
    {
        ll num=ar[b];
        ll cnt=0;
        while(num)
        {
            seg_tree_bit_sum[n][cnt]=0;
            cnt++;
            num/=2;
        }
        return;
    }
    ll mid=(b+e)/2;
    clr(n*2,b,mid);
    clr(n*2+1,mid+1,e);
    for(ll i=0; i<=33; i++)
    {
        seg_tree_bit_sum[n][i]=0;
    }
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
        ll n;
        cin>>n;
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
        }
        build(1,1,n);
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll l,r;
            cin>>l>>r>>x;
//            if(x==0){
//                cout<<r-l+1<<"\n";continue;
//            }
            pos=0;
            ll tm_x=x;
            while(tm_x)
            {
                pos++;
                tm_x/=2;
            }
            pos--;
            big=0;
            zero=0;
            query(1,1,n,l,r);
            //cout<<big<<" "<<zero<<" x\n";
            cout<<big+zero<<"\n";
        }
        clr(1,1,n);
    }
    return 0;
}




