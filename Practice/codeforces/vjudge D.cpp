#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> g[100005];
int sz[100005];
ll ans[100005];
int n;
void dfs(int source, int par){
    sz[source] = 1;
    for(auto v: g[source]){
        if(v == par)continue;
        dfs(v, source);
        sz[source] += sz[v];
        ans[source] += (n - sz[v] - 1) * 1LL * sz[v];
    }
    //cout << source << endl;
    //cout << ans[source]<<endl;
    ans[source] += (n - sz[source]) * 1LL * (sz[source] - 1);
    //cout << ans[source]<< endl << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int n, k;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);

    int q;
    cin >> q;
    while(q--){
        ll query;
        cin >> query;
        //cout << sz[query] << endl;
        //ll ans = (sz[query]-1) * 1LL * (n - sz[query] + 1);
        cout << ans[query]/2 + n - 1<<"\n";
    }
}



