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
ll ck(vector<ll>V1,vector<ll>V2)
{
    ll cnt=LONG_MAX;
    for(ll i=0; i<4; i++)
    {

    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    // fast;
    ll tcase=1;
    //cin>>tcase;

    for(ll test=1; test<=tcase; test++)
    {
        vector<ll>V;
        V.PB(1);
        V.PB(2);
        V.PB(3);
        V.PB(3);
        do
        {
            for(ll i:V)
            {
                cout<<i<<" ";
            }
            cout<<" x\n";
        }
        while(next_permutation(V.begin(),V.end()));



    }
    return 0;
}




