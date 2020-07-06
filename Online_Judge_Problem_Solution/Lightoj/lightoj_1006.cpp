#include<bits/stdc++.h>
using namespace std;
long long int ar[10003];
long long int a, b, c, d, e, f;
long long int fn( long long int n ) {
    if( n == 0 ) return a;
    else if( n == 1 ) return b;
    else if( n == 2 ) return c;
    else if( n == 3 ) return d;
    else if( n == 4 ) return e;
    else if( n == 5 ) return f;
    else if(ar[n]!=-1) return ar[n];
    else{
        ar[n]=(fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))% 10000007;
    return ar[n];
    }
}
int main() {
    long long int n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
            memset(ar,-1,10003*sizeof(ar[0]));
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
