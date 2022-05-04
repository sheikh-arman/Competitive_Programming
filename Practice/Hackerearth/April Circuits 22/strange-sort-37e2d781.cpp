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
ll mod=1e9+7;
ll mem[MAX+10];
int main()
{
//    mem[0]=mem[1]=1;
//    for(ll i=2;i<=150000;i++){
//        mem[i]=i*mem[i-1];
//        mem[i]%=mod;
//    }
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll q,k;
        cin>>q>>k;
        ll pre=0;
        mem[1]=1;
        if(k==1)
        {
            mem[1]+=1;
            pre++;
        }
        for(ll i=2; i<=150000; i++)
        {
            ll val=i/k;
            if(val>pre)
            {
                pre++;
            }
            mem[i]=mem[i-1]+pre;
            mem[i]%=mod;
        }
        for(ll i=2; i<=150000; i++)
        {
            mem[i]+=mem[i-1];
            mem[i]%=mod;
        }
        for(ll i=0; i<q; i++)
        {
            ll l,r;
            cin>>l>>r;
            ll ans=mem[r]-mem[l-1];
            ans+=mod;
            ans%=mod;
            cout<<ans<<"\n";
        }
    }
    return 0;
}




