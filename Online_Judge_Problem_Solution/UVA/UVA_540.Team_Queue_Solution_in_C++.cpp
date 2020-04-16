/*
Author:SK Arman HOSSAIN

Problem:UVA 540 Team Queue
Solution: queue
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll t,cnt=1;
    while(cin>>t&&t){
            queue<ll>que2d[1009];
            queue<ll>que;
            unordered_map<ll,ll>mp;
            unordered_map<ll,ll>mp2;
        ll n;
        for(ll i=1;i<=t;i++){
            ll a;
            cin>>a;
            while(a--){
                ll b;
                cin>>b;
                mp[b]=i;
            }
        }
       // if(cnt!=1){

        //}
        cout<<"Scenario #"<<cnt++<<"\n";
        while(1){
            string s;
            cin>>s;
            if(s=="STOP"){
                break;
            }
            else if(s=="ENQUEUE"){
                ll a;
                cin>>a;
                if(mp2[mp[a]]==1){
                    que2d[mp[a]].push(a);
                }
                else{
                    mp2[mp[a]]=1;
                    que.push(mp[a]);
                    que2d[mp[a]].push(a);
                }
            }
            else{
                    cout<<que2d[que.front()].front()<<"\n";
                    que2d[que.front()].pop();
                    if(que2d[que.front()].empty()){
                        mp2[que.front()]=0;
                        que.pop();
                    }
                }
        }
        cout<<"\n";
    }
}
