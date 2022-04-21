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
ll dp[1010];
ll ar_cnt[1010];
ll ar[1010];
int main()
{
    cout<<fixed<<setprecision(7);
    freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i];
            ar_cnt[i]=0;
            dp[i]=0;
        }
        ar_cnt[n]=1;
        dp[n]=ar[n];
        for(ll i=n-1; i>=1; i--)
        {
            for(ll j=1; j<=6; j++)
            {
                if(i+j>n)break;
                dp[i]+=dp[j+i]+ar[i];
                ar_cnt[i]+=ar_cnt[j+i];
                // cout<<i<<" "<<j<<" "<<dp[i]<<" test\n";
            }
        }
        double ans=(double)dp[1]/ar_cnt[1];
        cout<<dp[1]<<" "<<ar_cnt[1]<<" x\n";
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}




