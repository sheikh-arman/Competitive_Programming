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
ll cnt[500010];
ll ar[500010];
ll pre_modified[500100];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<=n+m;i++){
            pre_modified[i]=-1;
            cnt[i]=0;
        }
        for(ll i=1;i<=n;i++){
            cin>>ar[i];
            pre_modified[ar[i]]=0;
            cnt[i]=0;
        }
        for(ll i=1;i<=m;i++){
            ll pos,val;
            cin>>pos>>val;
            cnt[ar[pos]]+=i-pre_modified[ar[pos]];
            pre_modified[ar[pos]]=-1;
            pre_modified[val]=i;
            ar[pos]=val;
        }
        ll ans=0;
        for(ll i=1;i<=m+n;i++){
            if(pre_modified[i]!=-1){
                cnt[i]+=(m+1)-pre_modified[i];
            }
            ll x=m+1;
            ll val=max(0LL,(x-cnt[i])-1);
            ans+=(x*(x-1))/2;
            //cout<<i<<" "<<ans<<" x\n";
            ans-=(val*(val+1))/2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}





