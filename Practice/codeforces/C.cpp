
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n, k;
    cin >> n >> k;
    int A[n + 5]; long long ans = 0;
    map<ll, int> M; M[0] = 1; ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        sum += A[i];
        sum %= k;
        ans += M[sum];
        M[sum]++;
    }
    cout << ans << endl;
}

