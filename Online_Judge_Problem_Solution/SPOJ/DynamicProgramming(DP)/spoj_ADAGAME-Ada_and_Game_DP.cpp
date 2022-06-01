/*
    Sk arman Hossain
    University of Barisal

    Problem : spoj_ADAGAME-Ada_and_Game
    Solution : DP
 */
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
string s;
ll dp[10000][110],limit;
ll sol(string ch,ll i){
    if(i>=limit){
        if(ch>s){
            return 1;
        }
        else{
            return 0;
        }
    }
    ll tm=((ch[0]-'0')*1000)+((ch[1]-'0')*100)+((ch[2]-'0')*10)+(ch[3]-'0');
    if(dp[tm][i]!=-1){
        return dp[tm][i];
    }
    ll ans=0;
    if(i%2!=0)ans=1;
    for(ll k=0;k<4;k++){
        ll c=(ch[k]-'0')+1;
        c%=10;
        string xx=ch;
        xx[k]=(char)(c+'0');
        if(i%2==0){
            ans|=sol(xx,i+1);
        }
        else{
            ans&=sol(xx,i+1);
        }
    }
    return dp[tm][i]=ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>s>>limit;
        for(ll i=0;i<=9999;i++){
            for(ll j=0;j<=limit;j++){
                dp[i][j]=-1;
            }
        }
        ll ans=sol(s,0);
        if(ans){
            cout<<"Ada\n";
        }
        else{
            cout<<"Vinit\n";
        }


    }
///*****************************  ALHAMDULILLAH  *****************************/
}
