

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
<<<<<<< HEAD
ll ar[2000010];
int main()
{
    // cout<<"hjg\n";
=======
int main()
{
>>>>>>> 53f1cd93ed3d250b28360b312ec0e3e7a40bad68
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
<<<<<<< HEAD
        ll n,q;
        cin>>n>>q;
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
            ar[i]+=ar[i-1];
        }
        for(ll i=0; i<q; i++)
        {
            ll l,r,x;
            cin>>l>>r>>x;
            ll dif=(r-l)+1;
            ll par=ar[n]%2;
            ll pre=(ar[r]-ar[l-1])%2;
            ll ne=0;
            if(x%2&&dif%2)ne=1;
            if(pre!=ne)
            {
                par=1-par;
            }
            if(par%2)
            {
                YES;
            }
            else
            {
                NO;
            }
        }
=======
        ll n;
        cin>>n;
        


>>>>>>> 53f1cd93ed3d250b28360b312ec0e3e7a40bad68

    }
    return 0;
 ///*****************************  ALHAMDULILLAH  *****************************/
}





