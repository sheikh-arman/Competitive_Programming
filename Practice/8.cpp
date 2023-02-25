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
ll ar[100010];
vector<ll>edj[100010];
ll color[100010];
ll color2[100010];
ll cnt=0,cost=0;
void dfs(ll node){
    for(ll i:edj[node]){
        if(color[i]==0){
            if(color[node]==1){
                color[i]=2;
            }
            else{
                color[i]=1;
            }
            if(color[i]==1){
                cost+=ar[i];
                cnt++;
            }
            dfs(i);
        }
        else{
            if(color[i]==2&&color[node]==2){
                if(ar[i]<ar[node]){
                    color[i]=1;
                    cost+=ar[i];
                    cnt++;
                }
                else{
                    color[node]=1;
                    cost+=ar[node];
                    cnt++;
                }
            }
        }
    }
}
vector<ll>tm2;
void dfs2(ll node){
    tm2.PB(node);
    for(ll i:edj[node]){
        if(color2[i]==0){
            if(color2[node]==1){
                color2[i]=2;
            }
            else{
                color2[i]=1;
            }
            if(color2[i]==1){
                cost+=ar[i];
                cnt++;
            }
            dfs2(i);
        }
       else{
            if(color[i]==2&&color[node]==2){
                if(ar[i]<ar[node]){
                    color[i]=1;
                    cost+=ar[i];
                    cnt++;
                }
                else{
                    color[node]=1;
                    cost+=ar[node];
                    cnt++;
                }
            }
        }
    }
}
ll cc[100010];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=1;i<=n;i++){
            cin>>ar[i];
        }
        vector<pair<ll,ll>>pa;
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
            pa.PB({u,v});
        }
        vector<ll>V;
        
        for(ll i=1;i<=n;i++){
            if(color[i]==0){
                color[i]=1;
                cost=0;
                cnt=1;
                dfs(i);
                ll ans=cnt*cost;
                //cout<<i<<" "<<ans<<"x\n";
                ll cur=i;
                for(ll j:edj[i]){
                    tm2.clear();
                    cnt=1;cost=0;
                    color2[j]=1;
                    dfs2(j);
                    ll tm_ans=cnt*cost;
                   // cout<<j<<" "<<tm_ans<<" x2\n";
                    if(ans>tm_ans){
                        ans=tm_ans;
                        cur=j;
                    }
                    for(ll k:tm2)color2[k]=0;
                }
                V.PB(cur);
            }
        }

        for(ll i=1;i<=n;i++){
            color[i]=0;
        }
        for(ll i:V){
            color[i]=1;
            //cout<<i<<" x\n";
            dfs(i);
        }
        V.clear();
        for(ll i=1;i<=n;i++){
            if(color[i]==1){
                V.PB(i);
            }
        }
        cout<<V.size()<<"\n";
        ll ck=0;
        for(ll i:V){
            if(ck)cout<<" ";
            cout<<i;
            cc[i]=1;
            ck=1;
        }
        cout<<"\n";
         for(ll i=0;i<m;i++){
            assert(cc[pa[i].first]||cc[pa[i].second]);
            //cout<<cc[pa[i].first]<<" "<<cc[pa[i].second]<<" x\n";
        } 
    }
    return 0;
}

for(int i=0;i<=n;i++){
    ar[i]=0;
}