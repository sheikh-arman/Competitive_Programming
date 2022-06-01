#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll toten[1000010];
ll ans[1000010];
ll N=1000001;
void totient()
{
    for(ll i=1; i<=N; i++)
    {
        toten[i]=i;
        ans[i]=1;
    }
    for(ll i=2; i<=N; i++)
    {
        ll ck=0;
        if(toten[i]==i)
        {
            ck=1;
        }
        for(ll j=i; j<=N; j+=i)
        {
            if(ck==1)
            {
                toten[j]-=toten[j]/i;
            }
            ans[j]+=(i*toten[i]);
        }
    }
    for(ll i=1; i<=N; i++)
    {
        ans[i]=((ans[i]+1)*i)/2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase;
    totient();
    cin>>tcase;
    while(tcase--)
    {
        ll n;
        cin>>n;
        cout<<ans[n]<<"\n";
    }

    ///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
