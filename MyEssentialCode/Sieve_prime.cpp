#include<bits/stdc++.h>
using namespace std;
#define MAX 10000001
vector<int>prime_list;
int prime_ck[10000001];
void seive(){
    prime_ck[0]=prime_ck[1]=1;
    prime_list.push_back(2);
    for(int i=4;i<=MAX;i+=2){
        prime_ck[i]=1;
    }
    for(int i=3;i<=MAX;i+=2){
        if(prime_ck[i]==0){
            prime_list.push_back(i);
            for(int j=i+i;j<=MAX;j+=i){
                prime_ck[j]=1;
            }
        }
    }
     //Here prime_list vector indicate list of all prime number
    //prime_ck array indicate a number is prime? or not?
    //if prime_ck[n]=0 then number is prime else not a prime
}
int main ()
{
    seive();
    for(int i=0;i<40;i++){
        printf("%d\n",prime_list[i]);
    }
    int n;
    cin>>n;
    for(int i=0;prime_list[i]<=n;i++){
        cout<<prime_list[i]<<" ";
    }
    cout<<endl;


    return 0;
}
