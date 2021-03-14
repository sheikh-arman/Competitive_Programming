#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
#define MAX 100010
ll cnt_node[MAX+10];
ll parent[MAX+10];
vector<ll>edj[MAX+10];
bitset<MAX+10>sorted;
ll find_parent(ll node){
	return (parent[node]==node?node:parent[node]=find_parent(parent[node]));
}
void joint(ll a,ll b){
	ll pa_a=find_parent(a);
	ll pa_b=find_parent(b);
	if(pa_a!=pa_b){
		if(cnt_node[pa_a]<cnt_node[pa_b]){
			swap(pa_a,pa_b);
		}
		for(ll i:edj[pa_b])edj[pa_a].push_back(i);
		edj[pa_b].clear();
		cnt_node[pa_a]+=cnt_node[pa_b];
		parent[pa_b]=pa_a;
		sorted[pa_a]=0;
	}
}
int main(){
	//freopen("1input.txt","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll tcase=1;
	cin>>tcase;
	for(ll test=1;test<=tcase;test++){
		ll n,q;
		cin>>n>>q;
		for(ll i=0;i<=n;i++){
			parent[i]=i;
			cnt_node[i]=1;
			edj[i].clear();
			sorted[i]=0;
		}
		cout<<"Case "<<test<<":\n";
		for(ll i=0;i<q;i++){
			ll a;
			cin>>a;
			if(a==0){
				ll u,v;
				cin>>u>>v;
				joint(u,v);
			}
			else if(a==1){
				ll u,t;
				cin>>u>>t;
				u=find_parent(u);
				edj[u].push_back(t);
				sorted[u]=0;
			}
			else{
				ll u,l,r;
				cin>>u>>l>>r;
			    u=find_parent(u);
				if(sorted[u]==0){
					sort(edj[u].begin(),edj[u].end());
				}
				ll ans=0;
				ll siz=edj[u].size();
				if(siz>0){
					ll pos_l=lower_bound(edj[u].begin(),edj[u].end(),l)-edj[u].begin();
					ll pos_r=lower_bound(edj[u].begin(),edj[u].end(),r+1)-edj[u].begin();
					if(pos_l<siz){
						if(pos_r>=siz)pos_r-=1;
						if(edj[u][pos_r]>r)pos_r-=1;
						if(edj[u][pos_l]<=r){
							ans=pos_r-pos_l;
							ans+=1;
						}
					}
				}
				sorted[u]=1;
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
