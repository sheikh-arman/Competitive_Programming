#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+7;
//ll b[N],a[N];
const ll mod=1000000007 ;
ll dp[N][4];
int main() {
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    map<char,int>mp;
    mp['R']=0; mp['G']=1;mp['B']=2;
	ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    int tt=t,tcase=1;
    while(t--){
    	string s;
        cin>>s;
        ll n=s.size();
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<3;j++)dp[i][j]=0;
        }
        if(s[0]=='W'){
            dp[0][0]=dp[0][1]=dp[0][2]=1;
        }
        else{
            dp[0][mp[s[0]]]=1;
        }
        for(ll i=1;i<n;i++){
            if(s[i]=='W'){
                dp[i][0]=dp[i-1][1]+dp[i-1][2];
                dp[i][1]=dp[i-1][0]+dp[i-1][2];
                dp[i][2]=dp[i-1][1]+dp[i-1][0];
            }
            else if(s[i]=='R'){
                dp[i][0]=dp[i-1][1]+dp[i-1][2];
            }
            else if(s[i]=='G'){
                dp[i][1]=dp[i-1][0]+dp[i-1][2];
            }
            else{
                dp[i][2]=dp[i-1][1]+dp[i-1][0];
            }
            for(ll j=0;j<3;j++){
                dp[i][j]%=mod;
            }
        }
        ll ans=0;
        for(ll j=0;j<3;j++){
                ans+=dp[n-1][j];
                ans%=mod;
        }
        cout<<"Case "<<tcase++<<": "<<ans<<"\n";
    }
    return 0;
}