
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000006][7];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n, p, s;
    cin >> n >> p >> s;
    ll A[n + 5]; long long ans = 0;
    vector<ll> v; ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> A[i]; v.push_back(A[i]);
    }
    int k;
    cin >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            ll val = s * j;
            val = A[i] - val;
            int idx = lower_bound(v.begin(), v.end(), val) - v.begin() + 1;
            dp[i][j] = max(dp[i -1][j], dp[idx][k - j] + (A[i] - A[idx] + 1));
        }
    }
    cout << p - dp[n][k] + 1<< endl;

}


