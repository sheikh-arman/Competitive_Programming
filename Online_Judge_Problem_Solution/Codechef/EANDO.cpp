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
        vector<ll>even,odd;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            if(a%2==0)
            {
                even.PB(a);
            }
            else
            {
                odd.PB(a);
            }
        }
        ll eve=0;
        ll od=0;
        ll ev_mx=8;
        ll od_mx=-1;
        for(ll i=0; i<n/2; i++)
        {
            od+=abs(odd[i]-od_mx);
            eve+=abs(even[i]-ev_mx);
        }
        if(od>eve)swap(eve,od);
        //cout<<eve<<" "<<od<<" x\n";
        //ll eve_mi=eve/(n/2);
        //ll od_mi=od/(n/2);
        ll dif=abs(eve-od);
        if(eve%od==0||dif%4==0)
        {
            YES;
        }
        else
        {
            NO;
        }
    }
    return 0;
}




