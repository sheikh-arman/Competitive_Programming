
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300;
const ll inf=1e15;
ll a[N][N],h,w;
map<pair<ll,ll>,ll>mp,mp2;
//vector<pair<ll,ll>>dist;
ll dr[4]={1,-1,0,0};
ll dr2[4]={0,0,1,-1};
void dijkstra(ll r2,ll c2){
	mp2[{r2,c2}]=0;
	set<pair<ll,pair<ll,ll>>>s;
	s.insert({0,{r2,c2}});
	while(!s.empty()){
		auto x=*(s.begin());
		s.erase(x);
		ll r=x.second.first,c=x.second.second;
		for(int i=0;i<4;i++){
			//cout<<r<<" "<<dr[i]<<" "<<c<<" "<<dr2[i]<<endl;
			if(r+dr[i]>=0 && r+dr[i]<h && c+dr2[i]>=0 && c+dr2[i]<w){
				//r+=dr[i];c+=dr2[i];
				//cout<<r<<" "<<c<<" "<<mp2[{r,c}]<<" "<<mp2[{x.second.first,x.second.second}]<<" "<<a[r][c]<<endl;
				if(mp2[{r+dr[i],c+dr2[i]}]>mp2[{r,c}]+a[r][c]){
					s.erase({mp2[{r+dr[i],c+dr2[i]}],{r+dr[i],c+dr2[i]}});
					mp2[{r+dr[i],c+dr2[i]}]=mp2[{r,c}]+a[r][c];
					s.insert({mp2[{r+dr[i],c+dr2[i]}],{r+dr[i],c+dr2[i]}});
					//cout<<"???"<<r+dr[i]<<" "<<c+dr2[i]<<" "<<mp2[{r+dr[i],c+dr2[i]}]<<endl;
				}
			}
		}
	}
}
int main() {
    freopen("1input.txt","r",stdin);
	ios::sync_with_stdio(0);
    cin.tie(0);
	ll r,c,r2,c2,i,j,s=0,s2=0,z=0,crc=0;
	cin>>h>>w;
	cin>>r>>c>>r2>>c2;
	r--;c--;r2--;c2--;
	string str[h];
	for(i=0;i<h;i++){
		for(j=0;j<w;j++) {cin>>a[i][j];mp2[{i,j}]=inf;}
	}
	for(i=0;i<h;i++) cin>>str[i];
	dijkstra(r,c);
	z=inf;

	s=0;
	vector<pair<ll,ll>>v;
	map<pair<ll,ll>,ll>m;
	mp[{r2,c2}]=0;
	while(1){
		s++;
		ll x,y;
		//cout<<s<<" "<<r2<<" "<<c2<<" "<<m[{r2,c2}]<<endl;
		m[{r2,c2,}]++;
		if(m[{r2,c2}]==2){crc=1;break;}
		v.push_back({r2,c2});
		if(str[r2][c2]=='U') x=-1,y=0;
		else if(str[r2][c2]=='D') x=1,y=0;
		else if(str[r2][c2]=='L') x=0,y=-1;
		else x=0,y=1;
		if(x+r2>=0 && x+r2<h && y+c2>=0 && y+c2<w){
			r2+=x;c2+=y;
			mp[{r2,c2}]=s;
		}
		else break;
	}


	ll x,y;
	s--;
	for(i=0;i<(int)v.size();i++){
		x=v[i].first,y=v[i].second;
		//cout<<x<<" "<<y<<" "<<mp[{x,y}]<<" "<<mp2[{x,y}]<<" "<<z<<endl;
		if(mp[{x,y}]>mp2[{x,y}]) z=min(z,mp[{x,y}]);
		else if(crc==1){
			ll ans=mp2[{x,y}];
			ans=(ans+s-1)/s;
			z=min(z,ans*s+mp[{x,y}]);
			//cout<<z<<" "<<x<<" "<<y<<" "<<ans<<" "<<mp2[{x,y}]<<" "<<mp[{x,y}]<<endl;
		}
	}
	if(z==inf) cout<<"-1\n";
	else cout<<z<<"\n";
	return 0;
}
