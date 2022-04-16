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
ll ar[2010][2010];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,one=0;
        cin>>n;
        string s;
        for(ll i=0; i<n; i++)
        {
            cin>>s;
            for(ll j=0; j<n; j++)
            {
                ll a=s[j]-'0';
                ar[i][j]=a;
                if(ar[i][j]==1)one++;
            }
        }
        ll ans=9999999999;
        for(ll i=0; i<n; i++)
        {
            ll my_one=0;
            ll new_i=i;
            ll new_j=0;
            for(ll j=0; j<n; j++)
            {
                if(ar[new_i][new_j]==1)
                {
                    my_one++;
                }
                new_i++;
                new_j++;
                new_i%=n;
                new_j%=n;
            }
            ll res=n-my_one;
            res+=(one-my_one);
            ans=min(ans,res);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
