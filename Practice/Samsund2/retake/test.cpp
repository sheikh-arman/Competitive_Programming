#include<bits/stdc++.h>
using namespace std;

template <typename T>
class fenwick
{
    vector<T> bit;
    int N;
public:
    fenwick(int n)
    {
        N = n + 5;
        bit.resize(N);
    }
    void add(int i, T val)
    {
        while (i < N)
        {
            bit[i] += val;
            i += (i & -i);
        }
    }
    void add(int l, int r, T val)
    {
        add(l, val);
        add(r + 1, -val);
    }
    T query(int i)
    {
        T ans(0);    // prefix sum
        while (i > 0)
        {
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }
    T rquery(int l, int r)
    {
        return (T)(query(r) - query(l - 1));    // range sum
    }
    T pquery(int idx)
    {
        return (T)(query(idx) - query(idx - 1));
    }
    int lb(T val)
    {
        static const int LOG = log2(N);
        T sum(0);
        int pos = 0;
        for (int i = LOG; i >= 0; --i)
        {
            int calc = pos + (1 << i);
            if (calc < N && sum + bit[calc] < val)
            {
                sum += bit[calc];
                pos = calc;
            }
        }
        if (pos > N - 5) pos = N - 5;
        return pos + 1;//// +1 because 'pos' will have position of largest value less than 'v'
    }
};

int main()
{
    map<int,int>mp;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n=1000000;
    //cin >> n >> q;
    //assert(min(n, q) >= 2 && max(n, q) <= 1e6);
    fenwick<int> f(n), cnt(n);
    vector<int> rnk(n + 1), Sz(n + 1), par(n + 1);
    for (int i = 0; i <= 1000000; i++)
    {
        Sz[i] = 0;
    }
    while(1)
    {
        int t;
        cin >> t;
        if(t==-1)break;
        //assert(1 <= t && t <= 2);
        if (t == 1)
        {
            int i, j;
            cin>>j;
            mp[j]++;
            Sz[j] += 1;
            f.add(Sz[j], Sz[j]);
            cnt.add(Sz[j], 1);
        }
        else if(t==2)
        {
            int j;
            cin>>j;
            if(mp[j]>0)
            {
                f.add(Sz[j], -Sz[j]);
                cnt.add(Sz[j], -1);
            }
            else
            {
                cout<<"-1\n";
            }
        }
        else
        {
            int k;
            cin >> k;
            int y = cnt.query(n);
            if (y - 1 <= k)
            {
                cout << n << '\n';
            }
            else
            {
                int x = cnt.lb(y - k - 1);
                int rem = (y - cnt.query(x - 1)) - (k + 1);
                cout << n - f.query(x - 1) - x * rem << '\n';
            }
        }
    }
    return 0;
}
