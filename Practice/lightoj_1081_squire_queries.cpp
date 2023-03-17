
/*
    Sk arman Hossain
    University of Barisal

    Problem name :
    Algorithm :
 */
#include<bits/stdc++.h>
#define nl printf("\n");
#define PR pair<ll,ll>
#define sf1(n) scanf("%lld", &n)
#define sf2(n, m) scanf("%lld %lld",&n,&m)
#define sf3(n, m,k ) scanf("%lld %lld %lld",&n,&m,&k)
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
#define minus1 printf("-1\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
typedef long long int ll;
typedef unsigned long long int ull;
ll dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
ll dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
using namespace std;
#define N 510
ll sparse[510][20][510];
ll lg[510];
ll ar[510][510];
ll n,m;
void sparse_pre_process(){
    lg[1] = 0;
    for (int i = 2; i <= n; i++){
        lg[i] = lg[i/2] + 1;
    }
        
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            sparse[i][0][j]=ar[i][j];
        }
    }
    for(ll k=2;k<=2;k++){
        for (int i = 1; (1<<i) <= n; i++){
            for (int j = 0; j + (1 << i) <= n; j++){
                sparse[k][i][j] = max(sparse[k][i - 1][j], sparse[k][i - 1][j + (1 << (i - 1))]);
                cout<<sparse[k][i][j]<<" ";
            }
            cout<<" tx\n";
        }
     }
}
ll query(ll row, ll L, ll R){
    ll i = lg[R - L + 1];
    ll maximum = max(sparse[row][i][L], sparse[row][i][R - (1 << i) + 1]);
    return maximum;
}
int main()
{
    // fast;
    //freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n>>m;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                cin>>ar[i][j];     
            }
        }
        sparse_pre_process();
        cout<<"Case "<<test<<":\n";
        for(ll i=0;i<m;i++){
            ll l,r,u;
            cin>>l>>r>>u;
            ll ma=0;
            for(ll j=l;j<l+u;j++){
                ma=max(ma,query(j,r,(r+u)-1));
                cout<<j<<" "<<ma<<" x\n";
            }
            cout<<ma<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

