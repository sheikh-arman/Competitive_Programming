/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
vector<ll>V;
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll l,r;
    while(scanf("%lld%lld",&l,&r)!=EOF){
        ll ans=0;
        ll tl=l,tr=r;
        if(l>r)swap(l,r);
        for(ll i=l;i<=r;i++){
            ll n=i,cnt=1;
            while(n!=1){
                cnt++;
                if(n%2==0)n/=2;
                else n=(n*3)+1;
            }
            ans=max(ans,cnt);
        }
        printf("%lld %lld %lld\n",tl,tr,ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


