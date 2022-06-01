/*
    Sk arman Hossain
    University of Barisal

    Problem : uva 562
    Solution : dp(knapsack)
 */
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
ll n,sum;
ll chache[110][50000];
vector<ll>V;
ll dp(ll i,ll val){
    if(i>=n){
        ll tm=sum-val;
        return abs(tm-val);
    }
    if(chache[i][val]!=-1){
        return chache[i][val];
    }
    ll ans=LONG_MAX;
    if(val<sum/2){
        ans=dp(i+1,val+V[i]);
    }
    ans=min(ans,dp(i+1,val));
    return chache[i][val]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        sum=0;
        cin>>n;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V.PB(a);
            sum+=a;
        }
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=25100;j++){
                chache[i][j]=-1;
            }
        }
        ll ans=dp(0,0);
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
