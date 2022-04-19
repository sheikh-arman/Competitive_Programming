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
    freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>V;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
              cout<<a<<" ";
        }
         cout<<" test\n";
        if(n>=m)
        {
            NO;
            continue;
        }
        ll last_chair=0;
        ll current=0,next,ck=1;
        for(ll i=0; i<n; i++)
        {
            if(i==0)
            {
                last_chair=0-V[i];
                last_chair+=(100000000*m);
                last_chair%=m;
                current=0;
                next=V[i]+1;
            }
            else
            {
                ll new_pos=next;
                ll gap=new_pos-current;
                if(gap<=V[i])
                {
                    new_pos+=(V[i]-gap)+1;
                }
                next=new_pos+V[i]+1;
                current=new_pos;
                if(new_pos>=last_chair)
                {
                    ck=0;
                    break;
                }
            }
            cout<<current<<" "<<next<<" x\n";
        }
        if(next>m)
        {
            ck=0;
        }
        if(ck)
        {
            YES;
        }
        else
        {
            NO;
        }
        cout<<" \n\n";
    }
    return 0;
}





