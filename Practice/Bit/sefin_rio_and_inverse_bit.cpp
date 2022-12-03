#include <bits/stdc++.h>
using namespace std;

#define ll int
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%d", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll ara[10009];

int BITree[109];

ll getSum(ll index)
{
    ll sum = 0;

    while (index>0)
    {
        sum += BITree[index];

        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int n, int index)

{
    while (index <= n)
    {
       BITree[index]++;

       index += index & (-index);
    }
}

int main()

{
    ll n;
    sl(n);
    for0(i, n) {
        sl(ara[i]);
        ara[i] += 2;
    }

    ll q, u, v, op, inv, j, k;
    sl(q);
    for1(i, q) {
        scanf("%d %d %d", &op, &u, &v);
        if(u > v) swap(u, v);

        ms(BITree, 0);
        inv = 0;
        if(op != 1) {
            swap(ara[u], ara[v]);
            for(j = n-1; j >= 0; j--) {
                inv += getSum(ara[j]-1);
                updateBIT(102, ara[j]);
            }

            pf("%d\n", inv);
            swap(ara[u], ara[v]);
        }
        else {
            for(j = n-1; j > v; j--) {
                inv += getSum(ara[j]-1);
                updateBIT(102, ara[j]);
            }
            for(j = u-1; j >= 0; j--) {
                inv += getSum(ara[j]-1);
                updateBIT(102, ara[j]);
            }
            pf("%d\n", inv);
        }
    }

    return 0;
}
