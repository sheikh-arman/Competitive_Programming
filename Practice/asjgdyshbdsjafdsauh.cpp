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
ll ans=0;
ll query(ll n)
{
    vector<ll>VV;
    VV.PB(V[0]/2);
    VV.PB(V[0]%2);
    VV.PB(V[0]/2);
    // cout<<V[0]<<" x\n";
    ll an=0;
    ll cnt=3,siz=V.size();
    while(n)
    {
        if(n<4)
        {
            for(ll i=0; i<n; i++)ans+=VV[i];
            //cout<<n<<" "<<ans<<" x\n";
            break;
        }
        ll ck=1;
        for(ll i=1; i<siz; i++)
        {
            if((cnt*2)+1<=n)
            {
                an=V[i];
                cnt=(cnt*2)+1;
            }
            else
            {
                if(cnt+1<=n)
                {
                    n-=cnt+1;
                    an=V[i-1]+(V[i]%2);
                    ck=0;
                    break;
                }
                else
                {

                    n-=cnt;
                    an=V[i-1];
                    ck=0;
                    break;
                }
            }
        }
        // cout<<n<<" "<<ans<<" xx\n";
        if(ck)
        {
            n-=cnt;
        }
        ans+=an;
    }
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
        ll n,l,r;
        cin>>n>>l>>r;
        while(n>1)
        {
            V.PB(n);
            n/=2;
        }
        reverse(V.begin(),V.end());
        ll r_ans=0;
        query(r);
        r_ans=ans;
        ans=0;
        query(l-1);
        //cout<<r_ans<<" "<<ans<<" x\n";
        r_ans-=ans;
        cout<<r_ans<<"\n";
    }
    return 0;
}
