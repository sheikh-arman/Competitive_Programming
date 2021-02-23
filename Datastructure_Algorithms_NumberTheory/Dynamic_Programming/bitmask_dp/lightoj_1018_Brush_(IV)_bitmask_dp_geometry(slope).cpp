/*
    Sk arman Hossain
    University of Barisal

    Problem : lightoj_1018
    Solution : bitmask dp + geometry
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define PR pair<ll,ll>
#define sf1(n) cin>>n
#define sf2(n, m) cin>>n>>m
#define sf3(n, m,k ) cin>>n>>m>>k
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define minus1 printf("-1\n");
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTr(v) sort(v.begin(),v.end(),greater<long long int>())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll SET(ll NUM,ll pos)
{
    return NUM | (1<<pos);
}
bool isOn(ll NUM,ll pos)
{
    return (bool)(NUM & (1<<pos));
}
ll mem[1000000];
ll mem1[18][18];
int n;
vector<PR>V;
ll dp(ll mask,ll pos)
{
    if(mask==(1<<(n))-1||pos>=n)
    {
        return 0;
    }
    if(mem[mask]!=-1)
    {
        return mem[mask];
    }
    ll ans=100000;
    if(isOn(mask,pos)==0)
    {
        ll tm_mask=mask;
        tm_mask=SET(tm_mask,pos);
        ll ck=0;
        for(ll j=pos+1; j<n; j++)
        {
            if(isOn(tm_mask,j)==0)
            {
                ck=1;
                ll new_mask=tm_mask;
                new_mask=SET(new_mask,j);
                new_mask|=mem1[pos][j];
                ans=min(ans,dp(new_mask,pos+1)+1);
            }
        }
        if(ck==0)
        {
            ans=min(ans,dp(tm_mask,pos+1)+1);
        }
    }
    else
    {
        ans=dp(mask,pos+1);
    }
    return mem[mask]=ans;

}
int main()
{
    fast;
    // freopen("1input.txt","r",stdin);
    // freopen("1output.txt","w",stdout);
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll u,v;
            cin>>u>>v;
            V.PB({u,v});
        }
        for(ll i=0; i<=(1<<n); i++)
        {
            mem[i]=-1;
        }
        VST(V);
        for(ll i=0; i<n; i++)
        {
            for(ll j=i+1; j<n; j++)
            {
                ll slopx=V[i].first-V[j].first;
                ll slopy=V[i].second-V[j].second;
                ll gcd;
                gcd=__gcd(abs(slopx),abs(slopy));
                slopx/=gcd;
                slopy/=gcd;
                ll new_mask=0;
                for(ll k=0; k<n; k++)
                {
                    if(k==i||k==j)continue;
                    ll new_slopx=V[i].first-V[k].first;
                    ll new_slopy=V[i].second-V[k].second;
                    gcd=__gcd(abs(new_slopx),abs(new_slopy));
                    new_slopx/=gcd;
                    new_slopy/=gcd;
                    if((slopx==new_slopx&&slopy==new_slopy))
                    {
                        new_mask=SET(new_mask,k);
                    }
                }
                new_mask=SET(new_mask,i);
                new_mask=SET(new_mask,j);
                mem1[i][j]=new_mask;
            }
        }
        ll ans=0;
        ans=dp(0,0);
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    /****************************  ALHAMDULILLAH  ****************************/
}




