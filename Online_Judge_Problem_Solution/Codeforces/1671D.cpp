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
        ll n,k;
        cin>>n>>k;
        ll ans=0,mi=LONG_MAX,ma=0;
        vector<ll>V;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            mi=min(mi,a);
            ma=max(ma,a);
        }
        for(ll i=1; i<n; i++)
        {
            ans+=abs(V[i]-V[i-1]);
        }
        if(mi<=1&&ma>=k)
        {
            cout<<ans<<"\n";
        }
        else
        {
            ll res=LONG_MAX;
            if(mi>1)
            {
                res=V[0]-1;
                res=min(abs(V[n-1]-1),res);
                for(ll i=1; i<n; i++)
                {
                    ll tm=abs(V[i]-V[i-1]);
                    ll tm2=abs(1-V[i])+abs(V[i-1]-1);
                    ll dif=abs(tm2-tm);
                    res=min(res,dif);
                }
                ans+=res;
            }
            if(ma<k)
            {
                res=abs(V[0]-k);
                res=min(abs(V[n-1]-k),res);
                for(ll i=1; i<n; i++)
                {
                    ll tm=abs(V[i]-V[i-1]);
                    ll tm2=abs(k-V[i])+abs(V[i-1]-k);
                    ll dif=abs(tm2-tm);
                    res=min(res,dif);
                }
                ans+=res;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}




