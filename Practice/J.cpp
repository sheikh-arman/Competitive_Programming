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
#define MAX 200000000010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
int main()
{
   // cout<<"hjg\n";
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;

        ll a[n][m];
        ll chk[n],cnt[m+1];
        memset(cnt,0,sizeof(cnt));

        vector<pair<ll,ll>> pos[m+1];

        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>a[i][j];
                pos[a[i][j]].PB({i,j});
            }
            chk[i]=0;
            cnt[a[i][0]]++;
        }

        ll ans=n;
        for(ll i=0;i<m;i++){
            ll mx=0,val=-1;
            for(ll j=1;j<=m;j++){
                if(cnt[j]>=mx){
                    mx=cnt[j];
                    val=j;
                }
            }
            //cout<<i<<" "<<val<<" "<<mx<<endl;
            ans=min(ans,mx);
            cnt[val]-=mx;
            for(ll j=0;j<pos[val].size();j++){
                a[pos[val][j].first][pos[val][j].second]=-1;
            }
            for(ll j=0;j<n;j++){
                if(a[j][chk[j]]!=-1) continue;
                while(chk[j]<m && a[j][chk[j]]==-1) chk[j]++;
                //cout<<j<<" "<<chk[j]<<endl;
                if(chk[j]<m) cnt[a[j][chk[j]]]++;
            }
        }

        cout<<ans<<endl;


    }
    return 0;
}





