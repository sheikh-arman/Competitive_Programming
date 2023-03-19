
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
ll cum[2000101];
vector<ll>V;
ll fix=7;
ll query2(ll l,ll r)
{
//    cout<<"?";
//    for(ll i=l; i<=r; i++)
//    {
//        cout<<" "<<i;
//    }
//    cout<<"\n";
    ll x;
    //cin>>x;
    ll sum=cum[r]-cum[l-1];
    ll ck=0;
    if(fix>=l&&fix<=r)ck=1;
    x=sum+ck;
    return (sum!=x);
}
ll query(ll l,ll r)
{
    cout<<"? "<<(r-l)+1;
    for(ll i=l; i<=r; i++)
    {
        cout<<" "<<i;
    }
    cout<<"\n";
    ll x;
    cin>>x;
    ll sum=cum[r]-cum[l-1];
    return (sum!=x);
}
int main()
{
    cout.flush();
    // cout<<"hjg\n";
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<n+2; i++)cum[i]=0;
        V.clear();
        V.PB(0);
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        ll sum=0;
        for(ll i=1; i<=n; i++)
        {
            sum+=V[i];
            cum[i]=sum;
        }
        ll left=1,right=n;
        while(left<right)
        {
            ll mid=(left+right)/2;
            ll tm=query(left,mid);
            if(tm)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        cout<<"! "<<left<<"\n";
    }
    return 0;
}





