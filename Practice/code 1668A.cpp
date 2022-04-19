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
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;

    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        if(n==1&&m==1)
        {
            cout<<"0\n";
            continue;
        }
        if(n==1||m==1)
        {
            if(n>2||m>2)
            {
                cout<<"-1\n";
            }
            else
            {
                cout<<"1\n";
            }
            continue;
        }
        ll difx=abs(n-1);
        ll dify=abs(m-1);
        ll mi=min(difx,dify);
        ll ans=mi*2;
        difx-=mi;
        dify-=mi;
        ll ma=max(difx,dify);
        //cout<<ma<<" x\n";
        if(ma%2==0)
        {
            ans+=((ma/2)*3)+ma/2;
        }
        else
        {
            if(ma==1)
            {
                ans+=1;
            }
            else
            {
                ans+=ma;
                ma-=2;
                ans+=(ma/2+(ma*2!=0))*2;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}




