#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main(){ 
    //fast;
    map<string,int>mp;
    vector<string>V,ans;
    string s;
    while(cin>>s){
        V.push_back(s);
    }
    reverse(V.begin(),V.end());
    int n=V.size();
    for(int i=0;i<n;i++){
        if(!mp.count(V[i])){
            ans.push_back(V[i]);
        }
        mp[V[i]]++;
    }
    for(auto i:ans){
        cout<<i<<" "<<mp[i]<<"\n";
    }
    return 0;
}