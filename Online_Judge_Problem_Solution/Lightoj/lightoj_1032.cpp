/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    //freopen("1in.txt","r",stdin);
    //freopen("2out.txt","w",stdout);
    ll tcase;
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        scanf("%lld",&n);
        n++;
        ll tm=4,ans=0;
        while(tm<=n){
            ans+=(n/tm)*(tm/4);
            ll x=n%tm;
            x-=tm/2+(tm/4);
            if(x>0)
            ans+=x;
            tm*=2;
        }
        if(tm!=n){
            ll x=n%tm;
            x-=tm/2+(tm/4);
            if(x>0)
            ans+=x;
        }
        printf("Case %lld: %lld\n",test,ans);
    }
    return 0;
}
