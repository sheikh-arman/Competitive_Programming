/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution : Dynamic Programming
 */
 #include<bits/stdc++.h>
 using namespace std;
 int chache[110][110];
 string s;
 int n;
 int dp(int i,int j){
    if(i>=j){
        return 0;
    }
    if(chache[i][j]!=-1){
        return chache[i][j];
    }
    int ans;
    if(s[i]==s[j]){
        ans=dp(i+1,j-1);
    }
    else{
        ans=1+dp(i+1,j);
        ans=min(ans,(1+dp(i,j-1)));
    }
    return chache[i][j]=ans;
 }
 int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tcase;
    cin>>tcase;
    for(int test=1;test<=tcase;test++){
        cin>>s;
        n=s.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                chache[i][j]=-1;
            }
        }
        int ans=dp(0,n-1);
        cout<<"Case "<<test<<": "<<ans<<endl;
    }
    return 0;
 }
