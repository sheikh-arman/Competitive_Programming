#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll tcase=1;
	//cin>>tcase;
	for(ll test=1;test<=tcase;test++){
		ll n;
		vector<ll>V;
		cin>>n;
		for(ll i=0;i<n;i++){
			ll a;
			cin>>a;
			V.PB(a);
		}
		sort(V.begin(),V.end());
		ll q;
		cin>>q;
		for(ll i=0;i<q;i++){
			ll a;
			cin>>a;
			ll gcd=0;
			ll pos=lower_bound(V.begin(),V.end(),a)-V.begin();
			for(ll j=pos;j<n;j++){
				if(V[j]%a==0){
					gcd=__gcd(V[j],gcd);
					if(gcd==a)break;
				}
			}
			if(gcd==a){
				cout<<"Y\n";
			}
			else{
				cout<<"N\n";
			}
		}
	}
	return 0;
}