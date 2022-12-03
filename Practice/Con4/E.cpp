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
ll ar[50011];
ll V[100010];
ll res[100010];
ll sol(ll n)
{
    ll ans=0;
    ans=(n*(n-1))/2;
    return ans;
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
        vector< pair< pair<ll,ll>, ll>  >V2;
        for(ll i=1; i<=n; i++)
        {
            cin>>V[i];
        }
        ll a,b;
        ll ans=0;
        for(ll j=1; j<=q; j++)
        {
            cin>>a>>b;
            V2.PB({{a,b},j});
        }
        VST(V2);
        ll left=V2[0].first.first;
        ll right=V2[0].first.second;
        for(ll i=left; i<=right; i++)
        {
            ll cnt=ar[V[i]];
            ans-=sol(cnt);
            ar[V[i]]++;
            cnt=ar[V[i]];
            ans+=sol(cnt);
        }
        res[V2[0].second]=ans;
        for(ll j=1; j<q; j++)
        {
            ll a=V2[j].first.first;
            ll b=V2[j].first.second;
            ll c=V2[j].second;
            while(right<b)
            {
                right++;
                ll i=right;
                ll cnt=ar[V[i]];
                ans-=sol(cnt);
                ar[V[i]]++;
                cnt=ar[V[i]];
                ans+=sol(cnt);
            }
            while(left<a)
            {

                ll i=left;
                ll cnt=ar[V[i]];
                ans-=sol(cnt);
                ar[V[i]]--;
                cnt=ar[V[i]];
                ans+=sol(cnt);
                left++;
            }
            res[c]=ans;
        }
        for(ll i=1; i<=q; i++)
        {
            cout<<res[i]<<"\n";
        }
    }
    return 0;
}






