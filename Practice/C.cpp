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
ll sum[100010];
ll cnt[100010];
ll Find(ll node){
    return (rep[node]==node?node:rep[node]=Find(rep[node]));
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
        ll n;
        cin>>n;
        for(ll i=0;i<=n;i++){
            rep[i]=i;
            cnt[i]=0;
            sum[i]=0;
        }
        vector<ll>V;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>sum[i];
            cnt[i]=1;
        }
        ll q;
        cin>>q;
        while(q--){
            ll a;
            cin>>a;
            if(a==1){
                ll u,v;
                cin>>u>>v;
                u--;
                v--;
                ll tm_u=u;
                ll tm_v=v;
                u=Find(u);
                v=Find(v);
                if(sum[u]!=sum[v]&&sum[v]&&sum[u]&&tm_u==u&&tm_v==v){
                    if(sum[u]<sum[v]){
                        swap(u,v);
                    }
                    rep[v]=u;
                    sum[u]+=sum[v];
                    sum[v]=0;
                    cnt[u]+=cnt[v];
                    cnt[v]=0;
                }
            }
            else if(a==2){
                ll x;
                cin>>x;
                x--;
                x=Find(x);
                cout<<cnt[x]<<"\n";
            }
            else{
                ll x;
                cin>>x;
                x--;
                x=Find(x);
                cout<<++x<<"\n";
            }
        }

    }
    return 0;
}





