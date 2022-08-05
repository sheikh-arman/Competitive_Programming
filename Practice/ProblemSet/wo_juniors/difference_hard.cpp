/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll t=1;
    for(ll i=0; i<t; i++)
    {
        ll d,x;
        cin>>d>>x;
        ll ans1=x%d;
        ll ans2=d-(x%d);
        ll ans;
        if(ans1<=ans2){
            ans=x-ans1;
        }
        else{
            ans=(x+d)-ans1;
        }
        cout<<ans<<"\n";
    }

    return 0;
}



