#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 100;
int lp[N+1];
vector<int> pr;
void linear_seive()
{
    for (int i=2; i<=N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j){
            lp[i * pr[j]] = pr[j];
           // cout<<i<<" "<<pr[j]<<" "<<i*pr[j]<<" \n";
        }

    }
}
int main()
{
    linear_seive();
    ll n;
    while(cin>>n){
        ll ck=lp[n];
        //cout<<ck;
        if(ck==n){
            cout<<" Prime\n";
        }
        else{
            cout<<" Not Prime\n";
        }
    }
    return 0;
}
//ref: cp-algorithm
