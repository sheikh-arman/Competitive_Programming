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
ll fac[100010];
ll mod=1e9+7;
ll ar[100010];
ll extended_euclidean(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
ll npr(ll n,ll r)
{
    ll ans=1;
    if(r==0)
    {
        return fac[n];
    }
    else
    {
        ll x,y;
        ll gcd=extended_euclidean(r,mod,x,y);
        x=(x+mod)%mod;
        ans=fac[n]*x;
        ans%=mod;
    }
    return ans;
}
int main()
{
    ll ans=1;
    for(ll i=1; i<=100000; i++)
    {
        ans*=i;
        ans%=mod;
        fac[i]=ans;
    }
    freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll> >V;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB({a,i});
            ar[a]=i;
        }
        if(n==1)
        {
            cout<<"1\n";
            continue;
        }
        //ar[n]=n+1;
        VST(V);
        ll mx=2;
        ll l=V[0].second,r=V[1].second;
        if(l>r)
        {
            swap(l,r);
        }
        ans=1;
        while(r-l<n-1&&mx<n)
        {
            ll num=0;
            while(ar[mx]>=l&&ar[mx]<=r&&mx<n)
            {
                mx++;
                num++;
            }
            ll total=(r-l)+1;
            ll baki=total-mx;
            cout<<l<<" "<<r<<" "<<baki<<" "<<num<<" \n";
            ans*=npr(baki,num);
            if(mx>=n)break;
            l=min(l,ar[mx]);
            r=max(r,ar[mx]);
            //T(1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}




