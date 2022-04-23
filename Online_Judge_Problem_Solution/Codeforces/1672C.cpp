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
        map<ll,ll>mp;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            mp[a]++;
        }
        ll cnt=0;
        for(ll i=0; i<n-1; i++)
        {
            if(V[i]==V[i+1])
            {
                cnt++;
            }
        }
        if(cnt>1)
        {
            ll current=1;
            while(mp.count(current))
            {
                current++;
            }
            ll ans=0;
            for(ll i=0; i<n-1&&cnt>1; i++)
            {
                if(V[i]==V[i+1])
                {
                    ans+=1;
                    i++;
                    if(i+1<n)
                    {
                        if(V[i+1]==V[i])
                        {
                            cnt--;

                        }
                        if(i+2<n)
                        {
                            if(V[i+1]==V[i+2])
                            {
                                cnt--;
                            }
                        }
                        V[i]=current;
                        V[i+1]=current;
                        current++;
                        while(mp.count(current))
                        {
                            current++;
                        }
                    }
                    i--;
                }
//                cout<<i<<" "<<ans<<" "<<cnt<<" :";
//                for(ll j=0; j<n; j++)
//                {
//                    cout<<V[j]<<" ";
//                }
//                cout<<"\n";

            }
            cout<<ans<<"\n";
        }
        else
        {
            cout<<"0\n";
        }
    }
    return 0;
}





