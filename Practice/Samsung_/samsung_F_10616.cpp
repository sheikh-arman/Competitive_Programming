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
ll mem[210][22][11];
ll d,m,n,q;
vector<ll>V;
ll dp(ll pos,ll mod, ll cnt)
{
    if(pos>=n)
    {
        //cout<<mod<<" "<<cnt<<" x\n";
        if(mod==0&&cnt==m)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(mem[pos][mod][cnt]!=-1)
    {
        return mem[pos][mod][cnt];
    }
    ll ans=dp(pos+1,mod,cnt);
    if(cnt<m)
    {
        ll val=(mod+V[pos]+(d*10000000000))%d;
        ans+=dp(pos+1,val,cnt+1);
    }

    return mem[pos][mod][cnt]=ans;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; ; test++)
    {
        cin>>n>>q;
        if(n==0&&q==0)
        {
            break;
        }
        V.clear();
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        cout<<"SET "<<test<<":\n";
        for(ll i=0; i<q; i++)
        {
            cin>>d>>m;
            for(ll x=0; x<=n; x++)
            {
                for(ll y=0; y<=d; y++)
                {
                    for(ll z=0; z<=m; z++)
                    {
                        mem[x][y][z]=-1;
                    }
                }
            }
            ll ans=dp(0,0,0);
            cout<<"QUERY "<<i+1<<": "<<ans<<"\n";
        }
    }
    return 0;
}




