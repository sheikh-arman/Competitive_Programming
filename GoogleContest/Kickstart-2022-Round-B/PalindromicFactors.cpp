#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
ll ck(ll n)
{
    ll tm=n;
    ll sum=0;
    while(tm)
    {
        sum=(sum*10)+(tm%10);
        tm/=10;
    }
    return (sum==n);
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;

    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        ll sq=sqrt(n+1);
        ll ans=0;
        for(ll i=1; i<=sq; i++)
        {
            ll num2=n/i;
            if(n%i==0)
            {
                //cout<<i<<" "<<n/i<<" hi\n";
                if(ck(i))
                {
                    ans++;
                    //  cout<<i<<" x\n";
                }
                if(i<num2)
                {
                    if(ck(num2))
                    {
                        ans++;
                        // cout<<num2<<" x\n";
                    }
                }
            }

        }
        cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
    return 0;
}





