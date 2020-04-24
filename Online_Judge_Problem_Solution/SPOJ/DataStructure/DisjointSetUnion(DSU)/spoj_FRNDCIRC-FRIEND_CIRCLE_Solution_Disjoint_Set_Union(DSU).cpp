/*
    Sk arman Hossain
    University of Barisal

    Problem name : FRNDCIRC - FRIEND CIRCLE
    Solution : DSU
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 200010
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
            cout<<node_cnt[ru]<<"\n";
        }
        else{
            node_cnt[rv]+=node_cnt[ru];
            rep[ru]=rv;
            cout<<node_cnt[rv]<<"\n";
        }
    }
    else{
        cout<<node_cnt[ru]<<"\n";
    }
}
int main(){
 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    for(ll i=0;i<=N;i++){
        rep[i]=i;
        node_cnt[i]=1;
    }
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        map<string , ll> mp;
        ll cnt=1;
        for(ll i=0;i<n;i++){
            string s1,s2;
            ll a,b;
            cin>>s1>>s2;
            if(mp.count(s1)==0){
                a=cnt;
                mp[s1]=cnt++;
            }
            else{
                a=mp[s1];
            }
            if(mp.count(s2)==0){
                b=cnt;
                mp[s2]=cnt++;
            }
            else{
                b=mp[s2];
            }
            joint(a,b);
        }
        for(ll i=0;i<=cnt;i++){
            rep[i]=i;
            node_cnt[i]=1;
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}


