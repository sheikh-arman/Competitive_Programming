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
ll ans=0;
vector<ll>edj[40010];
ll white[40010];
ll black[40010];
bitset<40010>color;
void dfs(ll node){
    color[node]=true;
    for(ll i:edj[node]){
        if(color[i]==false){
            color[i]=true;
            dfs(i);
            white[node]+=white[i];
            black[node]+=black[i];
        }
    }
    if(black[node]==white[node]){
        ans++;
    }
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
        ll n;
        cin>>n;
        for(ll i=0;i<=n;i++){
            edj[i].clear();
            white[i]=0;
            black[i]=0;
            color[i]=false;
        }
        for(ll i=2;i<=n;i++){
            ll a;
            cin>>a;
            edj[a].PB(i);
        }
        string s;
        cin>>s;
        for(ll i=0;i<n;i++){
            if(s[i]=='B'){
                black[i+1]=1;
            }
            else{
                white[i+1]=1;
            }

        }
        ans=0;
        dfs(1);
        cout<<ans<<"\n";
    }
    return 0;
}




