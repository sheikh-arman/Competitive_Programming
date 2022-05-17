/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date: None
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
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,sum=0,q;
        cin>>n>>q;
        vector<ll>V;
        map<ll,ll>mp;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            sum+=a;
            mp[i]=1;
        }
        ll pre=-1;
        for(ll i=0; i<q; i++)
        {
            ll a;
            cin>>a;
            if(a==1)
            {
                ll pos,x;
                cin>>pos>>x;
                pos--;
                if(!mp.count(pos))
                {
                    V[pos]=pre;
                }
                sum-=V[pos];
                V[pos]=x;
                sum+=x;
                mp[pos]=1;
            }
            else
            {
                ll x;
                cin>>x;
                sum=(n*x);
                pre=x;
                mp.clear();
            }
            cout<<sum<<"\n";
        }
    }
    return 0;
}





