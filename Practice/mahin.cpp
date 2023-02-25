// Problem: B. Transform the Array
// Contest: CodeMarshal - 2022 ICPC Asia Dhaka Regional Online Preliminary Contest Hosted by Green University of Bangladesh
// URL: https://a...content-available-to-author-only...l.org/contests/icpc-dhaka-22-preli/problems/B
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
 
#include<bits/stdc++.h>
#define ll long long int
 
using namespace std;
const ll N = 10000005;
ll di[N+5];
bitset<N+5> cnt, crt;
void siv(){
	for(ll i = 2; i < N; i += 2) di[i] = 2;
	for(ll i = 3; i < N; i += 2){
		if(!di[i]){
			di[i] = i;
			for(ll j = i * i; j < N; j += 2 * i){
				if(!di[j]) di[j] = i;
			}
		}
	}
}
 
int main(){
    siv();
	ll t = 1, tt = 1;
	scanf("%lld", &t);
	while(t--){
		ll n;
		scanf("%lld", &n);
		ll a[n], b[n], ok = 1, ck = 1, gcd = 0, d = 0;
 
		for(ll i = 0; i < n; i++){
			scanf("%lld", &a[i]);
			ll x = a[i];
			while(x != 1){
				cnt[di[x]] = 1;
				x /= di[x];
			}
			gcd = __gcd(a[i], gcd);
		}
 
		ll m = gcd;
		while(m != 1){
			crt[di[m]] = 1;
			m /= di[m];
		}
 
		for(ll i = 0; i < n; i++){
			scanf("%lld", &b[i]);
			ll x = b[i];
			while(x != 1){
				if(!cnt[di[x]]) ok = 0;
				x /= di[x];
			}
		}
 
		m = (a[0] < b[0]);
		if(m){
			d = b[0] / a[0];
		}
		else d = a[0] / b[0];
 
		m = d;
		while(m != 1){
			if(!crt[di[m]]) ck = 0 ;
			m /= di[m];
		}
		m = (a[0] < b[0]);
 
		for(ll i = 0; i < n; i++){
			if(m) swap(a[i], b[i]);
			if(((a[i] / b[i]) != d) || (a[i] % b[i])) ck = 0; 
            if(m)swap(a[i],b[i]);
		}
 
 
		for(ll i = 0; i < n; i++){
			ll x = a[i];
			while(x != 1){
				cnt[di[x]] = 0;
				x /= di[x];
			}
		}
		m = gcd;
		while(m != 1){
			crt[di[m]] = 0;
			m /= di[m];
		}

		printf("Case %lld: ", tt++);
		if(ok){
			printf("Yes ");
		}
		else printf("No ");
		if(ck){
			printf("Yes\n");
		}
		else printf("No\n");
 
	}
 
	return tt - tt;
}