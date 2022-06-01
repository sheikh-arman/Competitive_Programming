/*
    Author : SK Arman Hossain
    University of Barishal
    Problem: dfs editorial
    Solution:
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 2000010
bitset<N>color;
vector<ll>edj[N];
void dfs(ll node){
    color[node]=true;
    for(ll i:edj[node]){
        if(color[i]==false){
            color[i]=true;
            dfs(i);
        }
    }
}
int main(){
    ll n,e;
    cin>>n>>e;
    for(ll i=0;i<=n;i++)edj[i].clear(),color[i]=false;
    for(ll i=0;i<e;i++){
        ll a,b;
        cin>>a>>b;
        edj[a].push_back(b);
        edj[b].push_back(a);
    }
    dfs(1);
    ll q;
    cin>>q;
    while(q--){
        ll a;
        cin>>a;
        if(color[a]==false){
            cout<<a<<" Unvisited\n";
        }
        else{
            cout<<a<<" Visited\n";
        }

    }
    return 0;
}
