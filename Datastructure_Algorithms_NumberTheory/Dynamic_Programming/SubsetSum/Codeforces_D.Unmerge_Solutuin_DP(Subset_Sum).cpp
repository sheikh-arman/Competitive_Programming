
/*
    Sk arman Hossain
    University of Barisal

    Problem : codeforces 1382D
    Solution : DP(Subset Sum)
 */
#include<bits/stdc++.h>
#define PB push_back
typedef long long int ll;
using namespace std;
ll chache[4010][2010],n,siz;
vector<ll>V,V2,V3;
ll dp(ll i,ll sum){
    if(i>=siz){
        return (sum==0);
    }
    if(chache[i][sum]!=-1){
        return chache[i][sum];
    }
    bool ans=0;
    if(sum-V3[i]>=0){
        ans=dp(i+1,sum-V3[i]);
    }
    ans|=dp(i+1,sum);
    return chache[i][sum]=(ll)ans;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        V2.clear();
        V3.clear();
        cin>>n;
        for(ll i=0;i<n*2;i++){
            ll a;
            cin>>a;
            V.PB(a);
        }
        ll mx=0;
        for(ll i=1;i<2*n;i++){
            if(V[i]>V[mx]){
                V3.PB(i-mx);
                mx=i;
            }
        }
        V3.PB(2*n-mx);
        siz=V3.size();
        for(ll i=0;i<=siz;i++){
            for(ll j=0;j<=n;j++){
                chache[i][j]=-1;
            }
        }
        ll ans=dp(0,n);
        if(ans==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}




