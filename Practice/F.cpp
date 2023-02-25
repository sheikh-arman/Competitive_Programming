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
vector< pair<ll,ll> >ed;
vector<ll>V;
ll label[100100];
vector<ll>edj[100010];
ll n,dist;
vector<ll>tm4,tm2;
ll bfs(ll node){
    queue<ll>q;
    q.push(node);
    label[node]=0;
    ll ma=0;
    while(!q.empty()){
        node=q.front();
        tm4.PB(node);
        tm2.PB(node);
        q.pop();
        for(ll i:edj[node]){
            if(label[i]==-1){
                label[i]=label[node]+1;
                if(label[i]>ma){
                    ma=label[i];
                    dist=i;
                }
                ma=max(ma,label[i]);
                q.push(i);
            }
        }
    }
    return ma;
}
ll ar[1000010];
ll ck(ll val){
    for(auto i:ed){
        ll u=i.first;
        ll v=i.second;
        if(ar[u]<=val&&ar[v]<=val){
            edj[u].PB(v);
            edj[v].PB(u);
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(label[i]==-1){
            tm2.clear();
            ll ma=bfs(i);
            for(ll j:tm2){
                label[j]=-1;
            }
            tm2.clear();
            ma=bfs(dist);
            ans=max(ans,ma);
        }
    }
    for(ll i:tm4){
        label[i]=-1;
        edj[i].clear();
    }
    tm4.clear();
    return ans;
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
        ll k;
        cin>>n>>k;
        V.clear();
        ed.clear();
        for(ll i=1;i<=n;i++){
            cin>>ar[i];
            V.PB(ar[i]);
            label[i]=-1;
        }
        VST(V);
        
        for(ll i=0;i<n-1;i++){
            ll u,v;
            cin>>u>>v;
            ed.PB({u,v});
        }
        ll ans=-1;
        ll left=0,right=n-1;
        while(left<=right){
            ll mid=(left+right)/2;
            ll c=ck(V[mid]);
            if(c>=k){
                ans=V[mid];
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}





