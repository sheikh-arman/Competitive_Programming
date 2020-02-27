#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n, k, d;
	set<long long> a;
	cin>>n>>k;
	for (d=1; d<=n; d++)
        a.insert(d);
        //a.insert({d, n/d});>>multiple value asign
    cout<<*next(a.begin(),k-1);
    for (int i=0; i<a.size(); i++){
            int temp=*next(a.begin(),0);
    }
}
