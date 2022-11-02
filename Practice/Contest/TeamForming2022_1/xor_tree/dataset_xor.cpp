
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
ll rep[100010];
ll Find(ll n){
    return (rep[n]==n?n:rep[n]=Find(rep[n]));
}
ll ran;
ll ran2;
ll ran3;
int main()
{
    for(ll i=0;i<=100000;i++)rep[i]=i;
    //freopen("1input.txt","r",stdin);
    //freopen("input10.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    ran=17376;
    ran2=2675787;
    ran3=253745;
    for(ll test=1; test<=tcase; test++)
    {
        ll n=100000;
        cout<<n<<"\n";
        for(ll i=0;i<n;i++){
            ll val=rand()+ran;
            val%=1000000000;
            cout<<val<<" ";
            ran*=242;
            ran%=100000000;
        }
        cout<<"\n";
        ll cnt=1;
        while(cnt<n){
            ll u=rand()+ran2;
            ll v=rand()+ran3;
            u%=n+1;
            v%=n+1;
            if(u==0)u++;
            if(v==0)v++;
            if(u!=v){
                if(Find(u)!=Find(v)){
                    cnt++;
                    cout<<u<<" "<<v<<"\n";
                    rep[Find(u)]=Find(v);
                }
            }
            ran2*=1213;
            ran3*=5242;
            ran2%=100000000;
            ran3%=100000000;
        }
    }
    return 0;
}





