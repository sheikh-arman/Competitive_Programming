// Problem: N - Dinner 02
// Contest: Virtual Judge - Weekly Contest 01
// URL: https://v...content-available-to-author-only...e.net/contest/554320#problem/N
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
void __f(const char* name, Arg1&& arg1)
{
    cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1<<" | ";
    __f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 1e5 + 5;
ll pr[N], cnt[N], a[N];
ll find(ll i)
{
    if(pr[i] == i) return i;
    return pr[i] = find(pr[i]);
}

void Union(ll a, ll b)
{
    a = find(a);
    b = find(b);

    pr[a] = b;
}

int32_t main()
{

    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll t = 1, tt = 1;
    cin >> t;

    while(t--)
    {

        ll n, q;
        cin >> n >> q;

        for(ll i = 0; i < N; i++)
        {
            pr[i] = i, cnt[i] = 0, a[i] = 0;
        }

        for(ll i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt[a[i]] = 1;
        }


        cout << "Case " << tt++ << ":\n";
        while(q--)
        {
            ll op;
            cin >> op;

            if(op & 1)
            {
                ll i, v;
                cin >> i >> v;
                i = find(i), v = find(v);
                if(!cnt[i]) continue;
                cnt[v] = 1;
                cnt[i] = 0;
                Union(i, v);
            }
            else
            {
                ll i;
                cin >> i;
                i--;
                ll ans = find(a[i]);
                cout << ans << '\n';
            }
        }
    }

    return 0;
}
/*
1
2 3
3 4
1 4 5
1 3 4
2 1
Answer: 4
*/
