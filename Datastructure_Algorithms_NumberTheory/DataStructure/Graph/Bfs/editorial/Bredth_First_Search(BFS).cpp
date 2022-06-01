/*
Author:Sk Arman Hossain
University of Barishal
Problem:
Solution:BFS
*/


#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
ll N=2000000;
bitset<2000010>color;
vector<ll>edj[2000010];
void bfs(ll parent){
    queue<ll>q;
    color[parent]=true;
    q.push(parent);
    while(!q.empty()){
        parent=q.front();
        q.pop();
        ll siz=edj[parent].size();
        for(ll i=0;i<siz;i++){
            ll child=edj[parent][i];
            if(color[child]==false){
                color[child]=true;
                q.push(child);
            }
        }
    }
}
int main(){
    ///ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll node,edge;
    cin>>node>>edge;
    for(ll i=0;i<=node;i++){
        color[i]=false;
        edj[i].clear();
    }
    for(ll i=0;i<edge;i++){
        ll u,v;
        cin>>u>>v;
        edj[u].PB(v);
        edj[v].PB(u);
    }
    bfs(1);
    ll x;
    while(cin>>x){
        if(color[x]==true){
           cout<<"Visited\n";
        }
        else{
            cout<<"Not Visited\n";
        }
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************///
}
