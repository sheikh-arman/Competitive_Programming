/*
    Sk arman Hossain
    University of Barisal

    Problem name : Codeforces 651 A. Joysticks
    Algorithm : dp
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll mem[310][310];
ll dp(ll a,ll b){
    if((a<=1&&b<=1)||(a<1||b<1)){
        return 0;
    }
    if(mem[a][b]!=-1){
        return mem[a][b];
    }
    ll ans=0;
    ans=1+dp(a+1,b-2);
    ans=max(ans,1+dp(a-2,b+1));
    return mem[a][b]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        for(ll i=0;i<=300;i++){
            for(ll j=0;j<=300;j++){
                mem[i][j]=-1;
            }
        }
        ll n,cnt=0,a,b;
        cin>>a>>b;
        ll ans=dp(a,b);
        cout<<ans<<"\n";
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}
