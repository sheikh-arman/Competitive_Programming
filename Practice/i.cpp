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
ll ck(ll num,ll base){
    vector<ll>V,V_rev;
    while(num){
        V.PB(num%base);
        V_rev.PB(num%base);
        num/=base;
    }
    reverse(V_rev.begin(),V_rev.end());
    return (V_rev==V);
}
int main()
{
    //1422773
     /* for(ll i=2;i<=2000000;i++){
        if(ck(i,3)&&ck(i,4)){
            cout<<i<<" t\n";
        }
        if(i==2000000){
            cout<<" cc\n";
        }
    }   */
    //ck(6643,2);
    //ck(6643,3);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll a,b,k;
        cin>>a>>b>>k;
        ll ans=0;
        if(a==0){ans++;a++;}
        if(a<=b&&a==1){
            ans++;
            a++;
        }
        if(k==2){
            for(ll i=a;i<=b;i++){
                ans+=ck(i,2);
            }
        }
        if(k==3){
            if(a<=6643LL && b>=1422773LL){
                ans+=2; 
            }
            else if(a<=6643&&b>=6643){
                ans+=1;
            }
            else if(a<=1422773LL&&b>=1422773LL){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}





