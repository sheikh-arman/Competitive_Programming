#include<bits/stdc++.h>
using namespace std;
int cmb[100][100];
int combination(int n,int r){
    if(r==1)
        return n;
    if(r==n)
        return 1;
    if(cmb[n][r]){
        return cmb[n][r];
    }
    return cmb[n][r]=combination(n-1,r)+combination(n-1,r-1);
}
int main (){
    int n,r,ans;
    while(1){
        cin>>n>>r;
        ans=combination(n,r);
        cout<<ans<<endl;
    }
}
