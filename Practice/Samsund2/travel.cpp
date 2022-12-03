// Problem: Super Order
// Contest: HackerRank - SRBD Code Contest - 2022 (Round 2)
// URL: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-2/challenges/super-order
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
#define   MAX    500006
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
ll A[MAX], B[MAX], C[MAX];
ll mat[13][13], nt[13][13];
ll dp[1 << 12][12];

ll sti(string a, int base = 10){
	ll k = 0;
	for (int i = 0; i < (int)a.size(); ++i){
		k *= base;
		k += a[i]-'0';
	}
	return k;
}
ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
ll calc(int mask, int last, int idx){
    if(idx == n) {
        return 0;
    }
    ll& ret = dp[mask][last];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) continue;
        ret = max(ret, calc(mask | (1 << i), ((nt[last][i] == 1)?last: i), idx + 1)+ mat[last][i]);
    }
    return ret;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n;
        mem(mat, 0);
        mem(nt, 0);
        mem(dp, - 1);
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            char ch;
            getline(cin, s);
            cntr = 0;
            for (int j = 0; j < n; ++j) {
                cntr++; s1 ="";
                while(s[cntr] != ',') {
                    s1 += s[cntr]; cntr++;
                }
                cntr++;cntr++;

                mat[i][j] = sti(s1);
                //cout << s1 << endl;
                if(s[cntr]== 'T') nt[i][j]=1;
                else nt[i][j] = 0;
                cntr++; cntr++; cntr++;
            }
        }
        ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, calc(1 << i, i, 0));
        }
        cout <<"Case "<<++cnt<<": "<< ans << endl;

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
