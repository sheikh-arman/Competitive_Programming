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
ll mem[101010][18],n;
string s;
ll mod=1e9+7;
ll dp(ll pos,ll val){
    if(pos>=n){
        if(val==5){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(mem[pos][val]!=-1){
        return mem[pos][val];
    }
    ll ans=0;
    if(s[pos]=='?'){
        for(ll i=0;i<10;i++){
            ans+=dp(pos+1,((val*10)+i)%13);
            if(ans>=mod)ans%=mod;
        }
    }
    else{
        ll va=(val*10)+(s[pos]-'0');
        ans+=dp(pos+1,va%13);
    }
    if(ans>=mod)ans%=mod;
    return mem[pos][val]=ans;

}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
   // cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>s;
        n=s.size();
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=13;j++){
                mem[i][j]=-1;
            }
        }
        ll ans=dp(0,0);
        cout<<ans<<"\n";
    }
    return 0;
}





