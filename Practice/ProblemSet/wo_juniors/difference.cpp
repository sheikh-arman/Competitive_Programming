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
        ll ans=min(x%d,d-(x%d));
        cout<<ans<<"\n";
    }

    return 0;
}



