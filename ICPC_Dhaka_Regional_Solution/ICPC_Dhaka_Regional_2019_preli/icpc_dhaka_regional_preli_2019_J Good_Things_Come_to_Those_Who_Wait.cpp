#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main(){
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1;test<=tcase;test++){
        ll n;
        cin>>n;
        vector<ll>V;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        sort(V.begin(),V.end());
        ll ans=V[0]*V[n-1];
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}
