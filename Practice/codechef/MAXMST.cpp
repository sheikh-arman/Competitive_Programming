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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> policy_set;

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
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>V;
        for(ll i=0; i<m; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        VST(V);
        ll ans=0;
        ll extra=m-(n-1);
        ll node=0;
        //cout<<extra<<" x\n";
        while(extra>0)
        {
            ll khali=(node*(node-1))/2;
            if(node>1)
            khali-=(node-1);
            if(extra<=khali)
            {
                break;
            }
            node++;
        }
        //cout<<node<<" xf\n";
        ll nici=n-node;
        for(ll i=m-1,j=0; i>=0,j<min(nici,m); i--)
        {
            ans+=V[i];
            //cout<<"ck\n";
            j++;
        }
        for(ll i=0; i<min(node-1,m); i++)
        {
            ans+=V[i];
        }
        cout<<ans<<"\n";



    }
    return 0;
}




