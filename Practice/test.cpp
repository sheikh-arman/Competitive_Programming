#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int nn=1e6+5;
ll ans=0,vis[nn],arr[nn];
map<pair<ll,ll>,ll>cost;
vector<ll>g[nn];
void dfs(ll i){
	vis[i]=1;
	for(int j:g[i]){
		if(vis[j]) continue;
		dfs(j);
		arr[i]+=min(arr[j],cost[{i,j}]);
		//cout<<i<<" "<<j<<" "<<arr[i]<<" "<<arr[j]<<" "<<cost[{i,j}]<<endl;
	}
	//arr[i]=min(arr[i],g[i].second);
	
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,z,i,j,u,v,y;
    cin>>n>>z;
    int zz=n-1;
    while(zz--){
    	int u,v,w;
    	cin>>u>>v>>w;
    	g[u].push_back(v);
    	g[v].push_back(u);  
    	cost[{u,v}]=w;
    	cost[{v,u}]=w;  	
    }
    for(i=1;i<=n;i++) cin>>arr[i];
   // ans=arr[z];
    dfs(z);
    
    cout<<arr[z]<<"\n";
    return 0;
}