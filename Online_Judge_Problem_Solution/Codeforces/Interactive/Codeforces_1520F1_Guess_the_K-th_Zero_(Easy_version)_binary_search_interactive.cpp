#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll inter(ll l,ll r)
{
    cout<<"? "<<l<<" "<<r<<"\n";
    ll val;
    cin>>val;
    return val;
}
int main()
{
    cout.flush();
    //freopen("1input.txt","r",stdin);
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,t,k;
        cin>>n>>t;
        cin>>k;
        ll ans=n;
        ll left=1,right=n;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            ll dif=mid;
            ll ase=inter(1,mid);
            if(ase+k<=dif)
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        cout<<"! "<<ans<<"\n";
    }
    return 0;
}
