#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t=1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<ll,ll> >v,q;
        for(ll i=0;i<n;i++){
            ll tmp;
            cin>>tmp;
            v.push_back({tmp,i});
        }
        q=v;
        sort(q.begin(),q.end());
        ll ck=0;
        for(ll i=0;i<n;i++){
            ll val=q[i].first;
            val+=v[i].first;
            if(val%2==1){
                ck=1;
                break;
            }
        }
        if(ck==0)cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}
