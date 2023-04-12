#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int mem[1010][1010];
int n,m;
string s1,s2;
int dp(int i,int j){
    if(i>=n||j>=m){
        return 0;
    }
    if(mem[i][j]!=-1){
        return mem[i][j];
    }
    int ans=0;
    if(s1[i]==s2[j]){
        ans=dp(i+1,j+1)+1;
    }
    ans=max(ans,dp(i+1,j));
    ans=max(ans,dp(i,j+1));
    return mem[i][j]=ans;
}
int main() {
	//ios::sync_with_stdio(0);
    //cin.tie(0);
    while(getline(cin,s1)){
        getline(cin,s2);
        n=s1.size();
        m=s2.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(0,0);
        cout<<ans<<"\n";
    }
	
	return 0;
}