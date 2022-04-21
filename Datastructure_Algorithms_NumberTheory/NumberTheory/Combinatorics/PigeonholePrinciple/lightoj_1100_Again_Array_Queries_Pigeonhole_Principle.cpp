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
ll ck_ar[1010];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;

    for(ll test=1; test<=tcase; test++)
    {
        ll n,q;
        cin>>n>>q;
        vector<ll>V;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V.PB(a);
        }
        cout<<"Case "<<test<<":\n";
        for(ll i=0;i<q;i++){
            ll l,r;
            cin>>l>>r;
            if(l>r)swap(l,r);
            if((r-l>1000)){
                cout<<"0\n";
            }
            else{
                for(ll j=0;j<=1000;j++){
                    ck_ar[j]=0;
                }
                for(ll j=l;j<=r;j++){
                    ck_ar[V[j]]++;
                }
                ll pre=-10000;
                ll ans=LONG_MAX;
                for(ll j=1;j<=1000;j++){
                    if(ck_ar[j]>0){
                        if(ck_ar[j]>1){ans=0;break;}
                        ans=min(j-pre,ans);
                        pre=j;
                    }
                }
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}




