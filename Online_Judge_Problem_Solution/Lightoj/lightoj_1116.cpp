#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define db double
//#define vec(a) vector<int>a

int main (){
    int t,ck=1,i;
    ll n,j;
    cin>>t;
    for(i=1;i<=t;i++){
    cin>>n;ck=1;
    if(n%2){
        printf("Case %d: Impossible\n",i);
        continue;
    }
    for(j=2;j*j<=n;j+=2){
        if(n%j==0&&(n/j)%2){
                ck=0;
            //cout<<j<<" "<<n/j<<endl;
            printf("Case %d: %lld %lld\n",i,n/j,j);
            break;
        }
    }
    long long int a=sqrt(n);
    if(a%2==0)
        a-=1;
    for(j=a;ck&&j>=0;j-=2){
        if(n%j==0&&(n/j)*j==n){
            printf("Case %d: %lld %lld\n",i,j,n/j);
            break;
        }
    }
    }

    return 0;
}
