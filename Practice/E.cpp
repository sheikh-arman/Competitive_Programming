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
ll sol(vector<ll>V1, vector<ll>V2, vector<ll>V3){
    ll n=V1.size();
    ll ans=100000000000000;
    for(ll i=0;i<n;i++){
        ll val=V1[i];
        ll pos1=upper_bound(V2.begin(),V2.end(),val)-V2.begin();
        ll pos2=upper_bound(V3.begin(),V3.end(),val)-V3.begin();
        ll a=pos1;
        ll b=pos1-1;
        ll c=pos2;
        ll d=pos2-1;
        if(a>=n){
            a--;
        }
        if(c>=n){
            c--;
        }
        if(b<0){
            b++;
        }
        if(d<0){
            d++;
        }
        a=V2[a];
        b=V2[b];
        c=V3[c];
        d=V3[d];
        
        ans=min(ans,abs(a-val)+abs(a-c)+abs(val-c));
        ans=min(ans,abs(a-val)+abs(a-d)+abs(val-d));
        ans=min(ans,abs(b-val)+abs(b-c)+abs(val-c));
        ans=min(ans,abs(b-val)+abs(b-d)+abs(val-d));
    }
    return ans;
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
        ll n;
        cin>>n;
        vector<ll>V1,V2,V3;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V1.PB(a);
        }
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V2.PB(a);
        }
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V3.PB(a);
        }
        VST(V1);VST(V2);VST(V3);
        ll ans=sol(V1,V2,V3);
        ans=min(ans,sol(V1,V3,V2));
        ans=min(ans,sol(V2,V1,V3));
        ans=min(ans,sol(V2,V3,V1));
        ans=min(ans,sol(V3,V1,V2));
        ans=min(ans,sol(V3,V2,V1));
        cout<<ans<<"\n";
    }
    return 0;
}





