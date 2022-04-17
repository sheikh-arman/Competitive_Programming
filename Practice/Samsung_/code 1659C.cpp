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
ll ar[200010];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;

    for(ll test=1; test<=tcase; test++)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        vector<ll>V;
        for(ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            V.PB(x);
            ar[i]=0;
        }
        ll sum=0;
        for(ll i=n-1; i>=0; i--)
        {
            sum+=V[i];
            ar[i]=sum;
        }
//        for(ll i=0; i<n; i++)
//        {
//            cout<<ar[i]<<" ";
//        }
//        cout<<"\n";
        ll ans=b*sum;
        // cout<<ans<<" test\n";
        ll last_pos=0,res=0;
        for(ll i=1; i<n; i++)
        {
            res+=a*(abs(last_pos-V[i-1]));
            res+=b*(abs(last_pos-V[i-1]));
            last_pos=V[i-1];
            ll node=n-i;
            ll second_section=ar[i]-(V[i-1]*node);
            ll res2=(b*second_section);
            //cout<<ans<<" "<<res<<" "<<res2<<" "<<res+res2<<" x\n";
            ans=min(res+res2,ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}





