// Problem: H. Colorful Balls
// Contest: CodeMarshal - ACM ICPC Dhaka Regional Online Preliminary Contest, 2018 Hosted by Daffodil International University
// URL: https://a...content-available-to-author-only...l.org/contests/icpc-dhaka-preli-18/problems/H
// Memory Limit: 1500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://c...content-available-to-author-only...r.org)

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 1e5 + 5;
string s;
ll n, m = 1000000007;
ll dp[N][4], v[N][4], id;

ll solve(ll i, ll c){
	if(i == n) return 1;
	if(v[i][c] == id) return dp[i][c];
	v[i][c] = id;
	ll res = 0;
	if(s[i] == 'W'){
		if(c != 0 && s[i + 1] != 'R'){
			res += solve(i + 1, 0);
		}
		if(c != 1 && s[i + 1] != 'G'){
			res += solve(i + 1, 1);
		}
		if(c != 2 && s[i + 1] != 'B'){
			res += solve(i + 1, 2);
		}
	}
	else{
		ll p = 0;
		if(s[i] == 'G') p = 1;
		else if(s[i] == 'B') p = 2;
		res += solve(i + 1, p);
	}
	res %= m;
	return dp[i][c] = res;	
}


int32_t main(){
	
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	
	ll t = 1, tt = 1;
	cin >> t;
	
	while(t--){
		cin >> s;
		n = s.size();
		s += s[n - 1];
		id++;
		for(int i=0;i<=n;i++){
            for(int j=0;j<3;j++){
                dp[i][j]=-1;
            }
        }
		ll ans = solve(0, 3);
		if(count(s.begin(), s.end(), 'W') == 0) ans--;
		
		cout << "Case " << tt++ << ": " << ans << '\n';
	}
	
	return 0;
}