/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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
ll dis[5010][5010];
ll mem[5010][5010];
ll ar[5010];
ll cum_ar[5010];
ll rev[5010];
ll cum_rev[5010];
vector<ll>V;
ll ck(ll l,ll r)
{
    ll ans=0;
    if((r-l)%2)
    {
        //cout<<" t\n";
        ll mid=(l+r)/2;
        //cout<<l<<" "<<r<<" "<<mid<<" x\n";
        ll point_1=mid;
        ll point_2=mid+1;
        mid=point_1;
        ans+=cum_rev[l]-cum_rev[mid];
        //cout<<ans<<" t\n";
        ans+=cum_ar[r-1]-cum_ar[mid-1];
        //cout<<ans<<" t\n";
        ans-=(abs(l-mid))*(rev[mid]);
        ans-=(abs(r-mid))*(ar[mid-1]);
        //cout<<ans<<" x\n";
        mid=point_2;
        ll tm_ans=0;
        tm_ans+=cum_rev[l]-cum_rev[mid];
        tm_ans+=cum_ar[r-1]-cum_ar[mid-1];
        tm_ans-=(abs(l-mid))*(rev[mid]);
        tm_ans-=(abs(r-mid))*(ar[mid-1]);
        //cout<<ans<<" "<<tm_ans<<" x\n";
        ans=min(ans,tm_ans);
        //cout<<ans<<" f\n";
    }
    else
    {
        ll mid=(l+r)/2;
        ans+=cum_rev[l]-cum_rev[mid];
        ans+=cum_ar[r-1]-cum_ar[mid-1];
        ans-=(abs(l-mid))*(rev[mid]);
        ans-=(abs(r-mid))*(ar[mid-1]);
    }
    return ans;
}
ll siz;
ll dp(ll i,ll skp)
{
    if(skp<0)
    {
        return 10000000000000000;
    }
    if(i>siz)
    {
        if(skp==0)
        {
            return 0;
        }
        else
        {
            return 10000000000000000;
        }
    }
    if(mem[i][skp]!=-1)
    {
        return mem[i][skp];
    }
    ll ans=LONG_LONG_MAX;
    if(skp==0)
    {

        ans=dis[i][siz+1];
    }
    else
    {
        ll ma=siz-skp;
        for(ll j=i; j<=ma; j++)
        {
            //cout<<i<<" "<<j<<" "<<dis[i][j]<<" x\n";
            ans=min(ans,dp(j+1,skp-1)+dis[i][j]);
        }
    }
    return mem[i][skp]=ans;
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
        V.clear();
        V.PB(0);
        ll n,k;
        cin>>n>>k;
        siz=n-1;
        for(ll i=0; i<=n+1; i++)
        {
            for(ll j=0; j<=n+1; j++)
            {
                mem[i][j]=-1;
                dis[i][j]=0;
            }
            ar[i]=0;
            cum_ar[i]=0;
            rev[i]=0;
            cum_rev[i]=0;
        }
        for(ll i=1; i<=n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        for(ll i=2; i<=n; i++)
        {
            ar[i-1]=V[i]-V[i-1];
            ar[i-1]+=ar[i-2];
        }
        for(ll i=1; i<=n; i++)
        {
            cum_ar[i]=ar[i];
            cum_ar[i]+=cum_ar[i-1];
        }
        for(ll i=n-1; i>=1; i--)
        {
            rev[i]=V[i+1]-V[i];
            rev[i]+=rev[i+1];
        }
        for(ll i=n; i>=1; i--)
        {
            cum_rev[i]=rev[i];
            cum_rev[i]+=cum_rev[i+1];
        }
        // ck(2,5);
//        for(ll i=1; i<n; i++)
//        {
//            cout<<ar[i]<<" ";
//        }
//        cout<<" x\n";
//        for(ll i=1; i<n; i++)
//        {
//            cout<<rev[i]<<" ";
//        }
//        cout<<" x\n";
        ll sum=0;
        for(ll i=2; i<=n; i++)
        {
            sum+=ar[i-1];
            dis[1][i]=sum;
            //cout<<dis[1][i]<<" ";
        }
//        cout<<"xx \n";
        for(ll i=2; i<n; i++)
        {
            for(ll j=i+1; j<=n; j++)
            {
                ll val=ck(i,j);
                dis[i][j]=val;
            }
        }
//        for(ll i=1; i<=n; i++)
//        {
//            for(ll j=1; j<=n; j++)
//            {
//                cout<<dis[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<siz-k<<" test\n";
        ll ans=dp(1,siz-k);
        cout<<ans<<"\n";
    }
    return 0;
}






