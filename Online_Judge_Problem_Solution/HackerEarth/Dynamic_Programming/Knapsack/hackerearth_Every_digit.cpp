#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
ll SET(ll NUM,ll POS)
{
    return NUM | (1<<POS);
}
bool isOn(ll NUM,ll POS)
{
    return (bool)(NUM & (1<<POS));
}
vector<ll>V;
ll n;
ll mem[1010][1026];
ll dp(ll pos,ll mask)
{

    if(pos>=n)
    {
        if(mask==1023)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(mem[pos][mask]!=-1)
    {
        return mem[pos][mask];
    }
    ll ans=0;
    ll tm_mask=mask|V[pos];
    ll val1=dp(pos+1,tm_mask);
    val1%=mod;
    ll val2=dp(pos+1,mask);
    val2%=mod;
    //cout<<pos<<" "<<mask<<" "<<val1<<" "<<val2<<" xx\n";
    ans=val1+val2;
    ans%=mod;
    return mem[pos][mask]=ans;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            string s;
            cin>>s;
            ll siz=s.size();
            ll tm=0;
            for(ll j=0; j<siz; j++)
            {
                ll val=s[j]-'0';
                tm=SET(tm,val);
            }
            V.PB(tm);
        }
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=1024; j++)
            {
                mem[i][j]=-1;
            }
        }
        ll ans=dp(0,0);
        cout<<ans<<"\n";
    }
    return 0;
}

