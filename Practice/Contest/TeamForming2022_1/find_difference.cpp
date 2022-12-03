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
ll ar[100010];
int main()
{
    freopen("input52.txt","r",stdin);
    freopen("output52.txt","w",stdout);
    //fast;
    ll tcase=1;
    // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        ordered_set st;
        st.insert(-100000000000000);
        st.insert(100000000000000);
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
            st.insert(ar[i]);
        }
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll type;
            cin>>type;
            if(type==1)
            {
                ll x;
                cin>>x;
                ll ans=LONG_LONG_MAX;
                ll ind=st.order_of_key(x);
                ans=min(ans,abs(x-*st.find_by_order(ind)));
                ans=min(ans,abs(x-*st.find_by_order(ind-1)));
                ans=min(ans,abs(x-*st.find_by_order(ind+1)));
                cout<<ans<<"\n";
            }
            else
            {
                ll p,x;
                cin>>p>>x;
                st.erase(st.find_by_order(st.order_of_key(ar[p])));
                ar[p]=x;
                st.insert(x);
            }
        }
    }
    return 0;
}





