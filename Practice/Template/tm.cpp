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
ll mem[(1<<18)+1000];
//ll s_tree[(1<<18)+1000];
ll num;
string s,s_tree[(1<<18)+100];
ll segmentTree(ll n,ll b,ll e,level=1)
{
    if(b==e)
    {
        s_tree[n]=s[n-1];
        return 0;
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    ll p=segmentTree(l,b,mid,leve+1);
    ll q=segmentTree(r,mid+1,e,level+1);
    s_tree[n]+=s[n-1];


}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>num;
        cin>>s;
        ll node=pow(2,num-1);
        ll ans=segmentTree(1,1,node);
        cout<<ans<<"\n";
    }
    return 0;
}





