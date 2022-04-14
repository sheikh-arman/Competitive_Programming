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
vector<ll>V;
ll n;
ll checking(ll val){
    ll odd=val/2+(val%2!=0);
    ll even=val/2;
    ll mx=V[n-1];
    ll ck=0;
    for(ll i=mx;i<=mx+2&&ck==0;i++){
        ll cu_odd=odd;
        ll cu_even=even;
        ll en=1;
        for(ll v:V){
            ll dif=i-v;
            ll ev_lagbe=dif/2;
            ll mi=min(cu_even,ev_lagbe);
            cu_even-=mi;
            dif-=(mi*2);
            if(dif){
                if(cu_odd>=dif){
                    cu_odd-=dif;
                }
                else{
                        en=0;
                    break;
                }
            }
        }
        if(en){
            ck=1;
        }
    }
    return ck;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        VST(V);
        if(V[0]==V[n-1]){
            cout<<"0\n";continue;
        }
        ll left=1;
        ll right=100000000000000000;
        ll ans;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            ll ck=checking(mid);
            if(ck==1)
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}





