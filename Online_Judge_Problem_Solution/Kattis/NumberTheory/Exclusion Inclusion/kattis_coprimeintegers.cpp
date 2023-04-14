/*
    Sk arman Hossain
    University of Barisal

    Problem : Kattis coprime integer
    Solution : Exclusion Inclusion
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
ll N=10000000;
int prime[10000003];
void seive(){
    for(ll i=1;i<=N;i++)prime[i]=i;
    for(ll i=2;i<=N;i+=2)prime[i]=2;
    for(ll i=3;i<=N;i+=2){
        if(prime[i]==i){
            for(ll j=i*i;j<=N;j+=i+i){
                prime[j]=min(prime[j],(int)i);
            }
        }
    }
}
ll func(ll a,ll b,ll val){
    ll ans=b/val;
    ans-=(a-1)/val;
    return ans;
}
int main()
{
    seive();
    vector<pair<ll,ll>>V;
    for(ll i=2;i<=N;i++){
        ll cnt=0;
        ll tm=i;
        while(tm!=1){
            if(tm%(prime[tm]*prime[tm])==0){
                cnt=0;break;
            }
            cnt++;
            tm/=prime[tm];
        }
        if(cnt){
            V.PB({i,cnt});
        }
    }
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll ans=0,n=V.size();
        for(ll i=0;i<n;i++){
            ll val=V[i].first;
            ll cnt=V[i].second;
            if(cnt%2==0){
                ll x=func(a,b,val);
                ll y=func(c,d,val);
                ans-=(x*y);
            }
            else{
                ll x=func(a,b,val);
                ll y=func(c,d,val);
                ans+=(x*y);
            }
        }
        ll len1=(b-a)+1;
        ll len2=(d-c)+1;
        ans=(len1*len2)-ans;
        cout<<ans<<"\n";
    }
    return 0;
 ///*****************************  ALHAMDULILLAH  *****************************/
}





