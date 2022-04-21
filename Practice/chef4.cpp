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
ll ar[42];
map<ll,ll>mp;
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        mp.clear();
        for(ll i=0; i<=35; i++)ar[i]=0;
        ll n,sum=0;
        cin>>n;
        vector<ll>V;
        ll zero=0,one=0;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            mp[a]++;
        }
        VST(V);
        ll pre=-1;
        ll k;
        cin>>k;
        ll cnt=0;
        while(k!=0)
        {
            ar[cnt++]=k%2;
            k/=2;
        }
        ll mx=cnt;
        ll ans=n;
        for(ll i:V)
        {
            if(i!=pre)
            {
                ll final_ck=1;
                pre=i;
                ll ck_zero=1;
                ll tm=i;
                cnt=0;
                while(tm!=0)
                {
                    if(cnt>=mx)break;
                    if(ar[cnt])
                    {
                        if(tm%2!=0)
                        {
                            ck_zero=0;
                            break;
                        }
                    }
                    cnt++;
                    tm/=2;
                }
                if(ck_zero)
                {
                    final_ck=0;
                    zero+=mp[i];
                    continue;
                }

                ll ck_one=1;
                tm=i;
                cnt=0;
                if(tm==0)continue;
                while(tm!=0)
                {
                    if(cnt>=mx)break;
                    if(ar[cnt])
                    {
                        if(tm%2!=1)
                        {
                            ck_one=0;
                            break;
                        }
                    }
                    cnt++;
                    tm/=2;
                }
                if(ck_one&&mx<=cnt)
                {
                    final_ck=0;
                    one+=mp[i];
                }
                if(final_ck)
                {
                    ll val=mp[i];
                    ans+=(val*(val-1));
                }
            }
            pre=i;
        }
        //cout<<one<<" "<<zero<<" x\n";
        one=(one*(one-1));
        zero=(zero*(zero-1));
        ans+=(one);
        ans+=(zero);
        cout<<ans<<"\n";
    }
    return 0;
}





