#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
vector<ll>edj[100010];
bitset<100010>color;
ll label[100010];
void dfs(ll node,ll ck){
	color[node]=true;
	for(ll i:edj[node]){
		if(color[i]==false){
			color[i]=true;
			ll tm=1-ck;
			label[i]=tm;
			dfs(i,tm);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll tcase;
	cin>>tcase;
	for(ll test=1;test<=tcase;test++){
		vector<pair<ll,ll> >V;
		ll n;
		cin>>n;
		for(ll i=0;i<=n;i++){
			edj[i].clear();
			color[i]=false;
			label[i]=0;
		}
		for(ll i=0;i<n-1;i++){
			ll u,v;
			cin>>u>>v;
			edj[u].PB(v);
			edj[v].PB(u);
			V.PB({u,v});
		}
		label[1]=0;
		dfs(1,0);
		// for(ll i=1;i<=n;i++){
		// 	cout<<label[i]<<" ";
		// }
		// cout<<" \n";
		cout<<"Case "<<test<<":\n";
		for(ll i=0;i<n-1;i++){
			ll u=V[i].first;
			ll v=V[i].second;
			if(label[u]==0){
				cout<<u<<" "<<v<<"\n";
			}
			else{
				cout<<v<<" "<<u<<"\n";
			}
		}
	}
	return 0;
}