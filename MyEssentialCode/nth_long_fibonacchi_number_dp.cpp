#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define long long long
const long M = 1000000007; // modulo

map<long, long> F;
vector<long> T[1234];

long f(long n, int Depth)
{
    T[Depth].push_back(n);
    if (F.count(n)) return F[n];
    long k=n/2;
    if (n%2==0)   // n=2*k
    {
        return F[n] = (f(k, Depth+1)*f(k, Depth+1) + f(k-1, Depth+1)*f(k-1, Depth+1)) % M;
    }
    else     // n=2*k+1
    {
        return F[n] = (f(k, Depth+1)*f(k+1, Depth+1) + f(k-1, Depth+1)*f(k, Depth+1)) % M;
    }
}

int main()
{
    fast;
    long n,test;
    cin>>test;
    while(test--)
    {
        F[0]=F[1]=1;
        cin>>n;
        n+=1;
        if (n==0)
            cout << 0 << endl;
        else
            cout << f(n-1, 0) << endl;

    }
    return 0;

}
