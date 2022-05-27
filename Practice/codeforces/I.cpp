
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
ll fact[1000000];
ll res[1000000];
ll N = 700000;
ll big_mod(ll n,ll p)
{
    if(p==0)
    {
        return 1LL;
    }
    if(p==1)
    {
        return n;
    }
    if(p%2==0)
    {
        ll tm=big_mod(n,p/2);
        ll val=((tm%mod)*(tm%mod))%mod;
        return val;
    }
    else
    {
        ll val=((big_mod(n,p-1)%mod)*(n%mod))%mod;
        return val;
    }
}

void precalc(){
    fact[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = (fact[i -1] * 1LL * i) % mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n, q, s;
    precalc();
    cin >> n >> s >> q;
    ll A[n + 5]; long long ans = 0;
    vector<ll> v; ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> A[i]; sum += A[i];
    }
    for(int i = 0; i <= s; i++){
        ll tempn = i;
        ll temp = i + n - 1;
        ll fact1 = fact[temp];
        ll fact2 = fact[tempn];
        ll fact3 = fact[temp - tempn];
        ll fact4 = (fact2 * 1LL * fact3) % mod;
        ll ifact = big_mod(fact4, mod - 2);
        ll ncr = (fact1 * 1LL * ifact) % mod;
        if(i) res[i] = (res[i - 1] + ncr) % mod;
        else res[i] = 1;
    }
    while(q--){
        int query, idx;
        cin >> idx >> query;
        sum -= A[idx]; A[idx] = query;
        sum += A[idx];
        int req = s - sum;
        if(req < 0){
            cout << 0 <<"\n"; continue;
        }
        cout << res[req] <<"\n";
    }

}



