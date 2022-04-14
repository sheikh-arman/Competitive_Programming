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
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;

    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        vector<ll>V;
        cin>>n>>k;
        ll ar[n+10];
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            ar[i]=0;
        }
        ll cnt=0,sum=0,ans=0;
        for(ll i=n-1; i>=0; i--)
        {
            cnt-=ar[i];
            sum-=cnt;
            sum-=ar[i];
            V[i]-=sum;
           // cout<<i<<" "<<ar[i]<<" "<<cnt<<" "<<V[i]<<" "<<sum<<" t\n";
            if(V[i]<=0)continue;
            ll mi=min(k,i+1);
            ll need=(V[i]/mi)+(V[i]%mi!=0);
            cnt+=need;
            sum+=(need*mi);
            ans+=need;
            if(i-k>=0)
            {
                ar[i-k]=need;
             //   cout<<i-k<<" "<<need<<" tt\n";
            }
            //cout<<i<<" "<<need<<" x\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}




