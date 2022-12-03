///https://www.hackerrank.com/contests/icpc-team-forming-contest-cse-bu/challenges/kth-largest-value-my-madness

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll     long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    1000006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element
// also 0 indexed
ll A[MAX], BIT[MAX], C[MAX];

struct FT{
    int n;
    FT(int _n){
        n = _n;
        for (int i = 0; i <= n + 2; ++i) {
            BIT[i] = 0;
        }
    }
    void update(int x, ll delta){
          for(; x <= n; x += x&-x) BIT[x] += delta;
    }
    ll query(int x, ll sum = 0LL){
         for(; x > 0; x -= x&-x) sum += BIT[x];
         return sum;
    }
};


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> q;
        FT ft(n); ll totsum = n;
        for (int i = 1; i <= n; ++i) {
            C[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> A[i]; C[A[i]]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (C[i]) ft.update(i, C[i]);
        }

        for (int i = 1; i <= q; ++i) {
            int type; cin >> type;
            if (type == 1) {
                ll u, v;
                cin >> u >> v;
                if (u == v) continue;
                ft.update(u, -C[u]);
                C[v] += C[u];
                ft.update(v, C[u]);
                C[u] = 0;
            }
            else if (type == 2) {
                ll u;
                cin >> u >> x;
                ft.update(u, x);
                totsum += x;
                C[u] += x;
            }
            else {
                cin >> k;l = 1; r = n;
                if (k > totsum) {
                    cout << -1 <<"\n"; continue;
                }
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (ft.query(mid) >= k) {
                        r = mid - 1;
                    }
                    else l = mid + 1;
                }

                cout << l << endl;
            }
        }

    }
    /*
        precedence : ! * / % + - << >>
        < > <= >= == != & ^ | && ||
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}
