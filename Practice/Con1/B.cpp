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
        ll n,m,ck=1;
        cin>>n>>m;
        vector<pair<pair<ll,ll>,ll>>V;
        for(ll i=0; i<m; i++)
        {
            ll a,b,w;
            cin>>a>>b>>w;
            if(a>b){
                swap(a,b);
                w*=-1;
            }
            V.PB({{a,b},w});
        }
        VST(V);
        map<ll,ll>mp;
        for(ll i=0; i<m; i++)
        {
            ll a=V[i].first.first;
            ll b=V[i].first.second;
            ll c=V[i].second;
            if(mp.count(a)||mp.count(b))
            {
                if(mp.count(a)&&mp.count(b))
                {
                    ll dif=mp[b]-mp[a];
                    if(dif!=c)
                    {
                        ck=0;
                        break;
                    }
                }
                else
                {
                    if(mp.count(a))
                    {
                        mp[b]=mp[a]+c;
                    }
                    else
                    {
                        mp[a]=mp[b]-c;
                    }
                }
            }
            else
            {
                mp[a]=0;
                mp[b]=c;
            }
        }
        if(ck)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }

    }
    return 0;
}
/*
4
3
1 2 5
3 4 5
3 2 3


*/





