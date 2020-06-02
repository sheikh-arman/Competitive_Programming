/*
    Sk arman Hossain
    University of Barisal

    Problem : Codeforces 1363 E. Tree Shuffling
    Solution : DFS
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 200010
vector<ll>edj[N];
ll a[N],b[N],c[N];
ll cn[N],on_pre[N],on_aft[N];
bitset<N>color;
void dfs(ll node){
    color[node]=true;
    if(b[node]!=c[node]){
        cn[node]++;
    }
    for(ll i:edj[node]){
        if(color[i]==false){
            dfs(i);
            cn[node]+=cn[i];
            b[node]+=b[i];
            c[node]+=c[i];
        }
    }
}
ll ans=LONG_MAX;
void dfs2(ll node,ll val){
    color[node]=true;
    if(cn[node]&&a[node]<val){
      ll tm=cn[node];
      tm-=abs(b[node]-c[node]);
      ans-=(tm*val);
      ans+=tm*a[node];
      val=a[node];
    }
    for(ll i:edj[node]){
        if(color[i]==false){
            color[i]=true;
            dfs2(i,val);
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,cntb=0,cntc=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(b[i]==1)cntb++;
        if(c[i]==1)cntc++;
    }
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        edj[u].push_back(v);
        edj[v].push_back(u);
    }
    if(cntb!=cntc){
        cout<<"-1\n";return 0;
    }
    dfs(1);
    for(ll i=0;i<=n;i++)color[i]=false;
    ans=cn[1]*a[1];
    dfs2(1,a[1]);
    cout<<ans<<"\n";

    return 0;
}
