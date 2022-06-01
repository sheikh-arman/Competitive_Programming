/*
    Sk arman Hossain
    University of Barisal

    Problem name : spoj- PT07X - Vertex Cover
    Algorithm : dfs + DP(Minimum Vertex Cover)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
ll mem[100010][3];
vector<ll>edj[100010];
ll dfs(ll node,ll status,ll parent){
    if(mem[node][status]!=-1){
        return mem[node][status];
    }
    ll ans=LONG_MAX;
    if(status){
        ans=0;
        for(ll i:edj[node]){
            if(i!=parent){
                ans+=dfs(i,0,node);
            }
        }
    }
    else{
        ans=0;
        for(ll i:edj[node]){
            if(i!=parent){
                ans+=dfs(i,1,node)+1;
            }
        }
        ans=min(ans,dfs(node,1,parent)+1);
    }
    return mem[node][status]=ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        edj[u].PB(v);
        edj[v].PB(u);
    }
    for(ll i=0;i<=n;i++){
        mem[i][0]=-1;
        mem[i][1]=-1;
    }
    ll ans=dfs(1,0,-1);
    cout<<ans<<"\n";
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
