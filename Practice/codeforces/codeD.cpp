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
vector<ll>V;
ll n,x,y;
ll cmp()
{
    vector<ll>new_v=V;
    ll cnt=0;
    for(ll i=n-1; i>=0; i--)
    {
        V[i]-=(cnt*y);
        if(V[i]<=0)continue;
        cnt+=(V[i]/x)+(V[i]%x!=0);
        //cout<<cnt<<" x\n";
    }
    return cnt;
    //return 0;
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

        cin>>n>>x>>y;
        V.clear();
        ll ma=0;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            ma=max(ma,a);
        }
        if(ma==0)
        {
            cout<<"0\n";
            continue;
        }
        ll ans=((ma+(y-1))/y);
        if(x<=y)
        {
            cout<<ans<<"\n";
        }
        else
        {
//            ll left=1,right=ans;
//            while(left<=right)
//            {
//                ll mid=(left+right)/2;
//                if(cmp(mid))
//                {
//                    ans=mid;
//                    right=mid-1;
//                }
//                else
//                {
//                    left=mid+1;
//                }
//            }
            ans=cmp();
            cout<<ans<<"\n";
        }
    }
    return 0;
}




