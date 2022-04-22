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
        string s;
        cin>>s;
        ll a=0,b=0;
        ll pre=-1;
        n=s.size();
        ll ck=1;
        a=1;
        for(ll i=0; i<n; i++)
        {
            ll val=s[i]-'a';
            if(pre!=val)
            {
                if(a&&i!=0)
                {
                    if(a==1)
                    {
                        ck=0;
                    }
                }
                a=1;
                pre=val;
            }
            else
            {
                a++;
            }
        }
        if(a)
        {
            if(a==1)
            {
                ck=0;
            }
        }
        if(ck)
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




