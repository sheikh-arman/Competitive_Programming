/*
    Sk arman Hossain
    University of Barisal

    Problem : Fibonacci
    Solution : Dynamic Programming
 */
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long int ll ;
 #define N 100
 ll dp[N+10];
 ll fib(ll n){
    if(n==0)return dp[n]=0;
    if(n==1)return dp[n]=1;
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];
 }
 int main(){
     //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //fill(dp,dp+N,-1);
    memset(dp,-1,sizeof(dp));
    ll x=fib(N);
    ll tcase=1;
    cin>>tcase;
    for(ll TEST=1;TEST<=tcase;TEST++){
        ll n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
 }
