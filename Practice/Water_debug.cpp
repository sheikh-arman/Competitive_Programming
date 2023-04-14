#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll start[N],ending[N];
ll s=1;
bitset<N>bt;
vector<ll>g[N],v;
ll arr[N],n,parent[N],size1[N];
void dfs(int i){
	bt[i]=1;
	start[i]=s;
	sort(g[i].begin(),g[i].end());
	for(auto j:g[i]){
		if(bt[j]==0) dfs(j);		
	}
	ending[i]=s++;
	v.push_back(i);
}
void make(ll v){
    parent[v]=v;
    size1[v]=1;
}
ll find(ll v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}
void Union(ll a,ll b,ll val,ll e){
    a=find(a);
    b=find(b);
    //cout<<n<<" "<<b;
    parent[a]=b;
    bt[b]=0;
    if(val>0) {
    	if(b+1<=e)Union(b,b+1,val-1,e);
    }
    return;
}
int main() {
	//freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
  	int t;
  	cin>>t;
  	int l=t;
  	while(t--){  		
	  	cout<<"Case "<<l-t<<":\n";
		s=1;
		v.clear();
	  	ll n,i,j,s2=0;
	  	cin>>n;
		for(ll i=0;i<=n;i++){
			g[i].clear();
			bt[i]=0;
		}
	  	for(i=1;i<n;i++){
	  		ll u,v;
	  		cin>>u>>v;
	  		g[v].push_back(u);
	  		g[u].push_back(v);
	  	}
	  	dfs(1);


		// for(ll i=1;i<=n;i++){
		// 	cout<<start[i]<<" ";
		// }
		// cout<<"\n";
		// for(ll i=1;i<=n;i++){
		// 	cout<<ending[i]<<" ";
		// }
		// cout<<"\n";


	  	for(i=1;i<=n;i++){
	  		make(i);
	  		//cout<<start[i]<<" "<<ending[i]<<endl;
	  	}
	  	ll q;
	  	cin>>q;
	  	while(q--){
	  		ll x,y,z;
	  		cin>>x>>y;
	  		if(x==1){
	  			cin>>z;
	  		    ll r=find(start[y]);
	  		    if(r<=ending[y]) {bt[r]=0;z--;}
	  		    if(r+1<=ending[y])Union(r,r+1,z,ending[y]);
			}
			else cout<<(bt[y]^1)<<"\n";
	  	}
  	}
  	return 0;
}