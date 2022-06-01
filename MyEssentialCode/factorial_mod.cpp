#include<bits/stdc++.h>
using namespace std;
int main (){
    int n,m,ans;
    while(cin>>n>>m){
    ans=1;
    for(int i=1;i<=n;i++){
        ans=((ans%m)*(i%m))%m;
    }
    cout<<ans<<endl;
    }
    return 0;
}
