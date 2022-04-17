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
ll SET(ll NUM,ll POS)
{
    return NUM | (1<<POS);
}
bool isOn(ll NUM,ll POS)
{
    return (bool)(NUM & (1<<POS));
}
vector<ll>for_x,for_y;
ll n,posx,posy;
ll mem[13][1<<12];
ll dp(ll pos, ll mask)
{
    if(mask==(1<<n)-1)
    {
        ll dis=abs(for_x[pos]-for_x[0])+abs(for_y[pos]-for_y[0]);
        return dis;
    }
    if(mem[pos][mask]!=-1)
    {
        return mem[pos][mask];
    }
    ll ans=LONG_MAX;
    for(ll i=1; i<n; i++)
    {
        if(isOn(mask,i)==0)
        {
            ll dis=abs(for_x[pos]-for_x[i])+abs(for_y[pos]-for_y[i]);
            ans=min(ans,dp(i,SET(mask,i))+dis);
        }
    }
    return mem[pos][mask]=ans;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        for_x.clear();
        for_y.clear();
        ll row,column;
        cin>>row>>column;
        cin>>posx>>posy;
        for_x.PB(posx);
        for_y.PB(posy);
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a,b;
            cin>>a>>b;
            for_x.PB(a);
            for_y.PB(b);
        }
        n=for_x.size();
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=(1<<n); j++)
            {
                mem[i][j]=-1;
            }
        }
        ll ans=dp(0,1);
        cout<<"The shortest path has length "<<ans<<"\n";

    }
    return 0;
}




