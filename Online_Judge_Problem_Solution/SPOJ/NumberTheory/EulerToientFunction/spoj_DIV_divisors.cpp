#include<bits/stdc++.h>
using namespace std;
#define MAX 10000001
vector<int>prime_list;
const int N1=1000000;
int prime_ck[N1+5];
void seive(){
    prime_ck[0]=prime_ck[1]=1;
    for(int i=4;i<N1;i+=2){
        prime_ck[i]=1;
    }
    for(int i=3;i<N1;i+=2){
        if(prime_ck[i]==0){
            for(int j=i+i;j<N1;j+=i){
                prime_ck[j]+=1;
                if(prime_ck[j]==2)
                    prime_list.push_back(j);
            }
        }
    }
}
int main ()
{
    seive();
    sort(prime_list.begin(),prime_list.end());
        for(int i=0;prime_list[i]<=1000000;i++)
        printf("%d\n",prime_list[i]);
}
