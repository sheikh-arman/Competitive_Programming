// Problem: D. Water in Tree
// Contest: CodeMarshal - MIST NCPC 2020
// URL: https://a...content-available-to-author-only...l.org/contests/mist-ncpc-2020/problems/D
// Memory Limit: 2048 MB
// Time Limit: 3000 ms
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
  cout << name << " : " << arg1 << std::endl;
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
vector<pair<ll, ll>> v;
vector<ll> g[N], A, ans, pr, st, en;
bitset<N> vis;
ll T = 1;

void dfs(ll u, ll p){
	vis[u] = 1;
	st[u] = T;
	for(auto i : g[u]){
		if(i != p){
			dfs(i, u);
		}
	}
	en[u] = T++;
}

ll find(ll i){
	if(pr[i] == i) return i;
	return pr[i] = find(pr[i]);
}

void Union(ll a, ll b){
	a = find(a);
	b = find(b);
	pr[a] = b;
}


int32_t main(){
	//freopen("1input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	
	ll t = 1, tt = 1;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		st= en = pr = A = ans = vector<ll>(n + 5);
		iota(pr.begin(), pr.end(), 0);
		T = 1;
		v.clear();
		for(ll i = 0; i <= n; i++){
			g[i].clear();
			vis[i] = 0;
		}
						
		for(ll i = 0; i < n - 1; i++){
			ll a, b;
			cin >> a >> b;
			//v.push_back({a, b});
            g[a].push_back(b);
            g[b].push_back(a);
		}
        for(ll i=0;i<=n;i++){
            sort(g[i].begin(), g[i].end());
        }
		// sort(v.begin(), v.end());
		
		// for(ll i = 0; i < n - 1; i++){
		// 	ll a = v[i].first;
		// 	ll b = v[i].second;
		// 	g[a].push_back(b);
		// }
		
		dfs(1, 0);
		for(ll i = 1; i <= n; i++){
			A[en[i]] = i;
		}
		
		ll q;
		cin >> q;
		cout << "Case " << tt++ << ":\n";
		while(q--){
			ll op;
			cin >> op;
			if(op & 1){
				ll i, w;
				cin >> i >> w;
				ll x = find(pr[st[i]]), y = en[i];
				while(w && x <= y && x <= n){
					ans[A[x]] = 1;
					Union(x, pr[x + 1]);
					w--;
					x = pr[x];
				}
			}
			else{
				ll i;
				cin >> i;
				cout << ans[i] << '\n';
			}	
		}
	}
	
	return 0;
}