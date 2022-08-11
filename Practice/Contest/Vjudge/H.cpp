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
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll h,w;
        cin>>h>>w;
        ll ans=LONG_LONG_MAX;
        ll tmx=w/3;
        ll tmy=(w/3)+(w%3!=0);
        tmx*=h;
        tmy*=h;
        ans=abs(tmx-tmy);
        
        
        tmx=h/3;
        tmy=(h/3)+(h%3!=0);
        tmx*=w;
        tmy*=w;
        ans=min(ans,abs(tmx-tmy));
        
        //cout<<ans<<" x\n";
        for(ll i=1;i<=w;i++){
        	vector<ll>V;
        	V.PB(i*h);
        	ll a=(h/2);
        	ll b=(h/2)+(h%2!=0);
        	V.PB(a*(w-i));
        	V.PB(b*(w-i));
        	VST(V);
        	ans=min(ans,V[2]-V[0]);
        }
        
        for(ll i=1;i<=h;i++){
        	vector<ll>V;
        	V.PB(i*w);
        	ll a=(w/2);
        	ll b=(w/2)+(w%2!=0);
        	V.PB(a*(h-i));
        	V.PB(b*(h-i));
        	VST(V);
        	ans=min(ans,V[2]-V[0]);
        }
		cout<<ans<<"\n";
    }
    return 0;
}




