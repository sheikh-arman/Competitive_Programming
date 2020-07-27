
/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution : Binary Search
 */
#include<bits/stdc++.h>
#define PB push_back
typedef long long int ll;
using namespace std;
vector<ll>V;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k,sum=0;
        cin>>n>>k;
        V.PB(0);
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            sum+=a;
            V.PB(sum);
        }
        ll ans=0;
        for(ll i=1;i<=n;i++){
            ll pos=upper_bound(V.begin(),V.end(),V[i-1]+k)-V.begin();
            pos--;
            ans=max(ans,(pos-i)+1);
            cout<<pos<<" \n";
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}




