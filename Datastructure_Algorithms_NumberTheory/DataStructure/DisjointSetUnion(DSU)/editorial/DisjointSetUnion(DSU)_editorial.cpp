/*
    Sk arman Hossain
    University of Barisal

    Problem name : Disjoint Set Union Editorial
    Solution : DSU
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 200002
ll rep[N+10];
ll node_cnt[N+10];
ll Find(ll node){
    return (rep[node]==node)?node:rep[node]=Find(rep[node]);
}
void joint (ll u,ll v){
    ll ru=Find(u);
    ll rv=Find(v);
    if(ru!=rv){
        if(node_cnt[ru]>node_cnt[rv]){
            node_cnt[ru]+=node_cnt[rv];
            rep[rv]=ru;
        }
        else{
            node_cnt[rv]+=node_cnt[ru];
            rep[ru]=rv;
        }
    }
}
int main(){
// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);

    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<=n;i++){
            rep[i]=i;
            node_cnt[i]=1;
        }
        for(ll i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            joint(a,b);
        }
        ll query;
        cin>>query;
        while(query--){
            ll a,b;
            cin>>a>>b;
            ll ra=Find(a);
            ll rb=Find(b);
            if(ra!=rb){
                cout<<a<<" "<<b<<" Are not Connected\n";
            }
            else{
                cout<<a<<" "<<b<<" Are Connected\n";
            }
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}

