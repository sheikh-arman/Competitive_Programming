#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define mp pair<ll,ll>
#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d %d",&n,&m)
#define sfl(n) scanf("%lld", &n)
#define sfu(n) scanf("%llu", &n)
#define sffl(n, m) scanf("%lld %lld",&n,&m)
#define pfn(n) printf("%d\n",n)
#define pf(n) printf("%d ",n)
#define pfl(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define pb push_back
#define pi 3.1415926536
#define vst(v) sort(v.begin(),v.end())
#define fori(n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
int dx[]= {0,0,1,1};
int dy[]= {1,1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int>v,v2,v3;
vector<int> :: iterator it1,it2;
const int N1=46345;
vector<int>prime_list;
int prime_ck[46345];
void sieve(){
    prime_list.push_back(2);
    //int sq=sqrt(N1)+1;
    for(int i=3;i<=46345;i+=2){
        if(prime_ck[i]==0){
            prime_list.push_back(i);
            for(int j=i+i+i;j<46345;j+=i*2){
                prime_ck[j]=1;
            }
        }
    }
}
ll segment(ll n,ll m){
    int seg[m-n+1]={0};
    if(n==1)
        seg[0]=1;
        int sq=sqrt(m)+1;
        for(int i=0;prime_list[i]<=sq;i++){
            ll p=prime_list[i];
            ll base=(n/p)*p;
            if(base<n)base+=p;
            for(ll j=base;j<=m;j+=p){
                seg[j-n]=1;
            }
            if(base==p)seg[base-n]=0;
        }
        int cnt=0;
        for(int i=0;i<=m-n;i++)
            if(!seg[i]){
                 cnt++;
            }
        return cnt;
}
int main()
{
    ///freopen("input.txt","r",stdin);
    sieve();
    int t,cnt=0;
    sf(t);
    while(t--)
    {
        ll n,ans=0,m;
        sffl(n,m);
        ans=segment(n,m);
        printf("Case %d: %lld\n",++cnt,ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
