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
ll mod=1e9+7;
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    //scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        map<string,ll>mp,mp2;
        cin>>n>>m;
        //scanf("%lld%lld",&n,&m);
        for(ll i=0; i<n; i++)
        {
            //char s;
            string s;
            cin>>s;
            //cin>>s;
            //scanf("%s",&s);
            mp[s]++;
        }
        set<string>st;
        for(ll j=0; j<m; j++)
        {
            string s;
            cin>>s;
            //scanf("%s",&s);
            mp2[s]++;
            st.insert(s);
        }
        ll ans=0;
        for(auto i:st)
        {
            ans+=(mp[i]*mp2[i]);
            ans%=mod;
        }
        //printf("%lld\n",ans);
        cout<<ans<<"\n";
    }
    return 0;
}




