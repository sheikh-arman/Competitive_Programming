#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dx[]={2,2,-2,-2,-1,1,1,-1};
ll dy[]={1,-1,1,-1,2,2,-2,-2};
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll tcase;
	cin>>tcase;
	for(ll test=1;test<=tcase;test++){
		ll x,y;
		cin>>x>>y;
		ll cnt=0;
		for(ll i=0;i<8;i++){
			ll tm_x=x+dx[i];
			ll tm_y=y+dy[i];
			if(tm_x>=1&&tm_x<=8&&tm_y>=1&&tm_y<=8){
				cnt++;
			}
		}
		cout<<"Case "<<test<<": "<<cnt<<"\n";
	}
	return 0;
}