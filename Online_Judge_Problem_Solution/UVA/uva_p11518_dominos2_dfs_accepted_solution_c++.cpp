#include<bits/stdc++.h>
using namespace std;
vector<int>v[10004];
int clr[10004];
int n,e,n_fallen_node;
void dfsVisit(int node){
    clr[node]=1;
    for(int i=0;i<v[node].size();i++){
        if(clr[v[node][i]]==0){
            dfsVisit(v[node][i]);
        }
    }
}
int main(){
    int t;
    //freopen("input.txt","r",stdin);
    cin>>t;
    while(t--){
    cin>>n>>e>>n_fallen_node;
    for(int i=0;i<=n;i++){
        clr[i]=0;
        v[i].clear();
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=0;i<n_fallen_node;i++){
        int a;
        cin>>a;
       dfsVisit(a);
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(clr[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    }
    return 0;
}
