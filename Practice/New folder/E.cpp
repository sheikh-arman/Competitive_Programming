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
    // cout<<(int)'k'-'a'<<" x\n";
    freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        vector<string>V;
        for(ll i=0; i<n; i++)
        {
            string s;
            cin>>s;
            V.PB(s);
        }
        VST(V);
        ll ans=0;
        for(ll j=0; j<=10; j++)
        {
            ll first_char=0,second_char=0,same=0;
            for(ll i=0; i<=10; i++)
            {
                ll cnt=0,same_cnt=0;
                for(ll k=0; k<n; k++)
                {
                    string s=V[k];
                    ll val1=s[0]-'a';
                    ll val2=s[1]-'a';
                    if(val1==j&&val2==i&&i!=j)
                    {
                        cnt++;
                    }
                    if(val1==j&&val2==i&&i==j)
                    {
                        same_cnt++;
                    }
                    if(val1==j)
                    {
                        first_char++;
                    }
                    if(val2==j)
                    {
                        second_char++;
                    }
                }
                if(i==j){
                    ans-=(cnt*(cnt-1))/2;

                }
                else{

                }

            }
            // cout<<j<<" "<<first_char<<" "<<second_char<<" "<<ans<<" x\n";

        }

        cout<<ans<<"\n";


    }
    return 0;
}




