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
//map<ll,ll>mp;
vector<pair<ll,ll>>V[100010];
ll ar[100010];
bitset<100010>color;
ll ck;
void dfs(ll node,ll cnt){
    color[node]=true;
    for(auto i:V[node]){
        ll a=i.first;
        ll cost=i.second;
        if(color[a]==false){
            color[a]=true;
            ar[a]=ar[node]+cost;
            dfs(a,ar[node]+cost);
        }
//        else{
//            if(ar[node]-ar[a]!=cost){
//                ck=0;
//            }
//        }
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
        ck=1;
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<=n;i++){
            color[i]=false;
            V[i].clear();
        }
        vector< pair<pair<ll,ll>,ll> >save;
        for(ll i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            V[a].PB({b,c});
            V[b].PB({a,c*-1});
            save.PB({{a,b},c});
        }
        ll cnt=0;
        for(ll i=1;i<=n;i++){
            if(color[i]==false){
                cnt+=10000000;
                ar[i]=cnt;
                dfs(i,cnt);
            }
        }
        for(ll i=0;i<m;i++){
            ll a=save[i].first.first;
            ll b=save[i].first.second;
            ll c=save[i].second;
            if(ar[b]-ar[a]!=c){
                ck=0;
            }
        }
         if(ck)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}




