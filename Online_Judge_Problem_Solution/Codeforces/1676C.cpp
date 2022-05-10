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
        ll n,sum=0,m;
        cin>>n>>m;
        vector<string>V;
        for(ll i=0; i<n; i++)
        {
            string s;
            cin>>s;
            V.PB(s);
        }
        ll ans=LONG_MAX;
        for(ll i=0; i<n-1; i++)
        {

            for(ll j=i+1; j<n; j++)
            {
                sum=0;
                for(ll k=0; k<m; k++)
                {
                    ll val=abs((V[i][k]-'a')-(V[j][k]-'a'));
                    sum+=val;
                }
                ans=min(ans,sum);
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}





