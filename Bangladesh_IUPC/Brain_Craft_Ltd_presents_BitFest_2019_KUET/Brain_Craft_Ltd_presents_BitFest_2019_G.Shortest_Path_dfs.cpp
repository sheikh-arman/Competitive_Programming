#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
vector< pair<ll,ll> >edj[30011];
ll cost[30010];
ll n;
bitset<30010>color;
bitset<30010>ck_loop;
ll parent[30010];
ll sum[30010];
void dfs(ll start,ll paren){
	parent[start]=paren;
	color[start]=true;
	for(auto i:edj[start]){
		if(color[i.first]==false){
			color[i.first]=true;
			cost[i.first]=cost[start]+i.second;
			sum[paren]+=i.second;
			dfs(i.first,paren);
		}
	}
}
int main(){
    //freopen("1input.txt","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll tcase=1;
	cin>>tcase;
	for(ll test=1;test<=tcase;test++){
		ll e;
		cin>>n>>e;
		for(ll i=0;i<=n;i++){
			color[i]=false;
			cost[i]=0;
			edj[i].clear();
			parent[i]=i;
			ck_loop[i]=0;
			sum[i]=0;
		}
		for(ll i=0;i<e;i++){
			ll u,v,w;
			cin>>u>>v>>w;
			edj[u].PB({v,w});
			edj[v].PB({u,w});
		}
		for(ll i=1;i<=n;i++){
			if((ll)edj[i].size()==1 && color[i]==false){
				dfs(i,i);
				ck_loop[i]=1;
			}
		}
		for(ll i=1;i<=n;i++){
			if(color[i]==false){
				dfs(i,i);
				sum[i]+=edj[i][1].second;
			}
		}
		ll q;
		cout<<"Case "<<test<<":\n";
		cin>>q;
		ll ans;
		for(ll i=0;i<q;i++){
			ll u,v;
			cin>>u>>v;
			if(parent[u]==parent[v]){
				if(ck_loop[parent[u]]==1){
				 	ans=abs(cost[u]-cost[v]);
				}
				else{
					ans=abs(cost[u]-cost[v]);
					ans=min(ans,sum[parent[u]]-ans);
				}
				cout<<ans<<"\n";
			}
			else{
				cout<<"-1\n";
			}
		}
	}
	return 0;
}
