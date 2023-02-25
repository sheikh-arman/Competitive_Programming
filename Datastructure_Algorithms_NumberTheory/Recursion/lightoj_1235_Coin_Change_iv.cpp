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
bitset<1000000010>color;
vector<ll>V;
ll n;
ll ar[20];
void dp(ll pos,ll val){
    if(pos>=n){
        if(val<=1e9 && color[val]==0){
            V.PB(val);
            color[val]=1;
        }
        return;
    }
    dp(pos+1,val+ar[pos]);
    dp(pos+1,val);
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
        ll k;
        cin>>n>>k;
        for(ll i=0;i<n;i++){
            cin>>ar[i];
        }
        V.clear();
        dp(0,0);
        ll ck=0;
        ll siz=V.size();
        for(ll i:V){
            ll val=k-i;
            if(color[k]==1||(val>=0&&color[val]==1)){
                ck=1;
            }
        }
        cout<<"Case "<<test<<": "<<(ck?"Yes":"No")<<"\n";
        for(ll i:V){
            color[i]=0;
        }
    }
    return 0;
}





