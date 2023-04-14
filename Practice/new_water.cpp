#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll start[N],ending[N];
ll s=1;
bitset<N>bt;
vector<ll>g[N];
ll arr[N],n,parent[N];
void dfs(int i){
	bt[i]=1;
	start[i]=s;//Check this line
	sort(g[i].begin(),g[i].end());
	for(auto j:g[i]){
		if(bt[j]==0) dfs(j);		
	}
	ending[i]=s++;//Check this line
}
ll find(ll v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
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
		s=1;//Check this line
	  	ll n,i,j,s2=0;
	  	cin>>n;
		for(ll i=0;i<=n;i++){
			g[i].clear();//Check this line
			bt[i]=0;//Check this line
		}
	  	for(i=1;i<n;i++){
	  		ll u,v;
	  		cin>>u>>v;
	  		g[v].push_back(u);
	  		g[u].push_back(v);
	  	}
	  	dfs(1);
	  	for(i=0;i<=n+2;i++){
	  		parent[i]=i;
			bt[i]=0;
	  	}
	  	ll q;
	  	cin>>q;
	  	while(q--){
	  		ll x,y,z;
	  		cin>>x>>y;
	  		if(x==1){
	  			cin>>z;
	  		    ll r=find(start[y]);
	  		    while(r<=ending[y]&&z) {//Check this line
                    //cout<<r<<" x\n";
					bt[r]=1;
					z--;
					parent[r]=find(r+1);//Check this line
					r=find(r);//Check this line
				}
			}
			else cout<<(bt[ending[y]])<<"\n";//Check this line
	  	}
  	}
  	return 0;
}