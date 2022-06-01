#include<bits/stdc++.h>
using namespace std;
ll modstr(string ch,int mod){
    ll m=0,a;
    for(ll i=0;ch[i]!='\0';i++){
        a=ch[i]-48+m*10;
        m=a%mod;
    }
    return m;
}
int main (){
    string str;
    while(cin>>str){
       int mod,c;
      cin>>mod;
      c=modstr(str,mod);
      cout<<c<<endl;
    }
    return 0;
}
