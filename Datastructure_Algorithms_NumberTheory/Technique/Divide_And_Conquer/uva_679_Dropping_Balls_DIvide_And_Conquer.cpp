/*
    Sk arman Hossain
    University of Barisal

    Problem : uva_679_Dropping_Balls
    Solution : Divide And Conquer
 */
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
ll d;
ll divide(ll i,ll dep,ll x){
    if(dep>=d){
        return x;
    }
    if(i&1){
        return divide(i/2,dep+1,x*2+1);
    }
    else{
        return divide(i/2,dep+1,x*2);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    while(cin>>tcase&&(tcase!=-1))
    {
        while(tcase--){
            ll n;
            cin>>d>>n;
            ll ans=divide(n-1,1,1);
            cout<<ans<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

