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
bool cmp(pair<ll,ll>& a, pair<ll,ll>& b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
ll ar[2000010];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll>>V;
        vector<ll>bs;
        for(ll i=0; i<n; i++)
        {
            ll a,b;
            cin>>a>>b;
            V.PB({a,b});
        }
        sort(V.begin(),V.end(),cmp);
        for(ll i=0; i<n; i++)
        {
            bs.PB(V[i].first);
            ar[i]=V[i].second;
        }
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++)
        {
            ll a;
            cin>>a;
            ll pos=lower_bound(bs.begin(),bs.end(), a )-bs.begin();
            if(pos==0)
            {
                cout<<ar[pos]<<"\n";
            }
            else if(pos==n)
            {
                cout<<ar[n-1]<<"\n";
            }
            else
            {
                ll dif1=abs(bs[pos]-a);
                ll dif2=abs(bs[pos-1]-a);
                if(dif1<dif2)
                {
                    cout<<ar[pos]<<"\n";
                }
                else
                {
                    cout<<ar[pos-1]<<"\n";
                }
            }
        }
    }
    return 0;
}





