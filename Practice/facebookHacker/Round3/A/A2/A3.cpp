/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 1000010
#define T(n) printf("test : %d\n",n);
#define f first
#define s second
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int A[MAX];
map<ll, ll> M;
map<ll, ll> rev;
struct SegmentTree
{
    vector<pair<ll, ll>> tree;
    int n;
    SegmentTree(int _n)
    {
        n = _n;
        tree.clear();
        tree.resize(n * 4);
    }
    void build(int node, int tb, int te)
    {
        if(tb > te) return;
        if(tb == te)
        {
            ll a = M[A[tb]];
            tree[node]  = {a, a};
            return;
        }
        int mid=(tb + te) >> 1;
        int left = (node * 2);
        int right = node * 2 + 1;
        build(left, tb, mid);
        build(right, mid + 1, te);
        tree[node].first = tree[left].first + tree[right].first;
        tree[node].second = tree[left].second ^ tree[right].second;
    }
    void update(int node, int tb, int te,int idx, ll newval)
    {
        if(te < idx || idx < tb)return;
        if(tb == te)
        {
            tree[node] = {newval, newval};
            return;
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        update(left, tb, mid, idx, newval);
        update(right, mid + 1, te, idx, newval);
        tree[node].first = tree[left].first + tree[right].first;
        tree[node].second = tree[left].second ^ tree[right].second;
    }
    pair<ll, ll> query(int node, int tb, int te, int qb, int qe)
    {
        if(tb > te) return {0LL, 0LL};
        if(qb > te || qe < tb)return {0LL, 0LL};
        if(qb <= tb && te <= qe)
        {
            return tree[node];
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        pair<ll, ll> L = query(left, tb, mid, qb, qe);
        pair<ll, ll> R = query(right, mid + 1, te, qb, qe);
        return {(ll)L.first + R.first, (ll)L.second ^ R.second};
    }

};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,sum=0,ans=0,check;
        cin >> n;
        M.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i];
            if (M.count(A[i]) == 0)
            {
                ll z = rng();
                M[A[i]] = z;
                rev[z] = 1;
            }
        }
        SegmentTree st(n);
        st.build(1, 1, n);
        ans = 0;
        ll q;
        cin >> q;
        for (int cs = 1; cs <= q; cs++)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                ll x,y;
                cin >> x >> y;
                if (M.count(y) == 0)
                {
                    M[y] = rng();
                    rev[M[y]] = 1;
                }
                st.update(1, 1, n, x, M[y]);
                continue;
            }
            ll l,r;
            cin >> l >> r;
            if(r == l)
            {
                ans++;
                continue;
            }
            if ((r + l) % 2 == 1) continue;
            pair<ll, ll> p = st.query(1, 1, n, l, r);
            if (rev.count(p.second) == 0)
            {
                continue;
            }
            check = 1;
            int ck = 1;
            int mid = (l + r) / 2;
            pair<ll, ll> fst = st.query(1, 1, n, l, mid), snd = st.query(1, 1, n, mid + 1, r);
            if (fst.first == snd.first + p.second) check = 0;
            fst = st.query(1, 1, n, l, mid - 1);
            snd = st.query(1, 1, n, mid, r);
            if (snd.f == fst.f + p.s) ck = 0;
            if (check == 0 or ck == 0 ) ans++;
        }
        cout <<"Case #"<<test<<": "<<ans<<endl;
    }
    return 0;
}
