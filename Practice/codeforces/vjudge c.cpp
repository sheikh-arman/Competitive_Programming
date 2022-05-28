
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n;
    ll A[n + 5], B[n + 5]; long long ans = 0;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    A[n + 1] = 3e18; vector<ll> v;
    for(int i = 1; i <= n; i++){
        B[i] = A[i + 1] - A[i];
        v.push_back(B[i]);
    }
    ll cumsum[n + 5] = {0};
    for(int i = 1; i <= n; i++){
        cumsum[i] = cumsum[i - 1] + B[i];
    }
    int q;
    cin >> q;
    while(q--){
        ll query;
        cin >> query;
        int idx = upper_bound(v.begin(), v.end(), query) - v.begin();
        sum = cumsum[idx] + (n - idx) * 1LL * query;
        cout << sum << '\n';
    }
}


