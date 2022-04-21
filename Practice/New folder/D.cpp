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
        vector<ll>V;
        string s;
        cin>>s;
        ll pre=-1,cnt_red=0,cnt_blue=0;
        ll ck=1;
        for(ll i=0; i<n; i++)
        {
            if(s[i]=='W')
            {
                if(i-pre==2)
                {
                    ck=0;
                    break;
                }
                else
                {
                    if(i-pre>2)
                    {
                        if(cnt_blue==0||cnt_red==0)
                        {
                            ck=0;
                            break;
                        }
                    }
                }
                pre=i;
                cnt_blue=0;
                cnt_red=0;
            }
            else
            {
                if(s[i]=='B')
                {
                    cnt_blue++;
                }
                else
                {
                    cnt_red++;
                }
            }
        }
        if(cnt_blue||cnt_red)
        {
            if(cnt_blue==0||cnt_red==0)
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




