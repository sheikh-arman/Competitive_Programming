#include<bits/stdc++.h>
using namespace std;
int weight[1000],cost[10000],n,cap;
int dp[1000][1000];
int knapsack(int i,int w){
    int profit1,profit2;
    if(i==n)
        return 0;
    if(dp[i][w]!=-1)
        return dp[i][w];
    if(w+weight[i]<=cap){
        profit1=cost[i]+knapsack(i+1,w+weight[i]);
    }
    else{
        profit1=0;
    }
    profit2=knapsack(i+1,w);
    dp[i][w]=max(profit1,profit2);
    return dp[i][w];
}
int main (){
    //freopen("input.txt","r",stdin);
    cin>>n>>cap;
    for(int i=0;i<n;i++){
        cin>>cost[i]>>weight[i];
    }
    int ans=knapsack(0,0);
       cout<<ans<<endl;
    return 0;
}
///*1017 , 1106 , 1125 , 1169 , 1200 , 1217 (Light Oj)*/
