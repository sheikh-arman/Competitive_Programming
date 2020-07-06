#include<bits/stdc++.h>
using namespace std;
int main (){
    long long int n,root,t;
    double r,chek;
    cin>>t;
    for(int i=1;i<=t;i++){
          cin>>n;
    r=sqrt(n);
    root=r;
    chek=root+.5;
    //cout<<chek;
    if(r>chek){
        root=r+1;
        if(root%2==0){
            cout<<"Case "<<i<<": "<<root<<" "<<root*root-n+1<<endl;
        }
        else{
            cout<<"Case "<<i<<": "<<root*root-n+1<<" "<<root<<endl;
        }
    }
    else if(r==(double)root){
        if(root%2!=0){
            cout<<"Case "<<i<<": 1 "<<root<<endl;
        }
        else{
            cout<<"Case "<<i<<": "<<root<<" 1"<<endl;
        }
    }
    else{
        root=r;
     if(root%2==0){
        cout<<"Case "<<i<<": "<<root+1<<" "<<n-root*root<<endl;
     }
      else if(root%2!=0){
            cout<<"Case "<<i<<": "<<n-root*root<<" "<<root+1<<endl;
       }
    }
    }
    return 0;
}
