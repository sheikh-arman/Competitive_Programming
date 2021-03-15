#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
ll sq(unsigned long long int n){
	if(n<1)return 0;
	ll left=1,right=sqrt(n+10);
	ll ans=1;
	while(left<right){
		ll mid=(left+right)/2;
		unsigned long long int tm=mid*mid;
		if(tm==n){
			ans=mid;break;
		}
		if(tm>n){
			right=mid;
		}
		else{
			ans=mid;
			left=mid+1;
		}
	}
	if(left*left<=n&&left>ans)ans=left;
	return ans;
}
int main(){
	//freopen("1input.txt","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll tcase=1;
	cin>>tcase;
	for(ll test=1;test<=tcase;test++){
		ll l, r;
		cin>>l>>r;
		ll val1,val2;
		val1=sq((l-1));
		val2=sq(r);
		ll ans=abs(val2-val1);
		// cout<<ans<<" test\n";
		ll new_l=l/2;
		if(l%2==0)new_l--;
		ll new_val1=sq(new_l);
		//cout<<new_val1<<" val\n";
		ll new_r=r/2;
		ll new_val2=sq(new_r);
		//cout<<new_r<<" "<<new_val2<<" val2\n";
		ll ans2=new_val2-new_val1;
		ans+=ans2;
		cout<<"Case "<<test<<": "<<ans<<"\n";
	}
	return 0;
}