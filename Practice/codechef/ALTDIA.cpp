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
        ll b,w;
        cin>>b>>w;
        if(!b||!w){
            cout<<"-1\n";
            continue;
        }
        ll ar[b+w+2];
        vector<pair<ll,ll>>V;
        if(b>=w)
        {
            ar[1]=1;
            cout<<"W";
            for(ll i=2; i<=b+1; i++)
            {
                V.PB({1,i});
                cout<<"B";
            }
            w--;
            ll blue=2,white=b+2;
            while(w--)
            {
                cout<<"W";
                V.PB({blue++,white++});
            }
            cout<<"\n";
            for(auto i:V)
            {
                cout<<i.first<<" "<<i.second<<"\n";
            }
        }
        else
        {
            cout<<"B";
            for(ll i=2; i<=w+1; i++)
            {
                V.PB({1,i});
                cout<<"W";
            }
            b--;
            ll blue=w+2,white=2;
            while(b--)
            {
                cout<<"B";
                V.PB({blue++,white++});
            }
            cout<<"\n";
            for(auto i:V)
            {
                cout<<i.first<<" "<<i.second<<"\n";
            }
        }
    }
    return 0;
}




