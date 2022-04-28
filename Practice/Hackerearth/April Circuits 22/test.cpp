#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
int extended_euclidean(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main()
{
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m=1e9+7,k;
        cin>>n>>k;
        int x, y;
        int g = extended_euclidean(n, m, x, y);
        if (g != 1)
        {
            cout << "No solution!";
        }
        else
        {
            x = (x + m) % m;
            x*=k;
            x%=m;
            cout << x << endl;
        }
    }

    return 0;
}
