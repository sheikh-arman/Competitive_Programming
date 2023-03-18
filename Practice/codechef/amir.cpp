#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {

    //ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false);

    ll t;
    cin >> t;
    for (ll T = 1; T <= t; T++) {
        ll n;
        cin >> n;
        if (n == 0) {
            cout <<"0 0\n";
            continue;
        }
        ll temp = n, zero = 0, one = 0;
        while (temp) {
            if(temp % 2 == 0) zero++;
            else one++;
            temp /= 2;
        }
        ll idx = 0, p = 0, zz = zero, ek = one;
        while ((one - 1) > 0) {
            p += (1LL << idx);
            idx++, one--;
        }
        idx += zero;
        if (ek) p += (1LL << idx);
        ll q = -1;
        if (zz) q = p / zz;
        cout << p << " " << q << "\n";
    }
    return 0;
}
