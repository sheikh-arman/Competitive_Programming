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
const int N1=1000011;
vector<int>prime_list;
int prime_ck[N1+1];
void sieve(){
    prime_list.push_back(2);
    for(int i=3;i<N1;i+=2){
        if(prime_ck[i]==0){
            prime_list.push_back(i);
            for(int j=3*i;j<N1;j+=i*2){
                prime_ck[j]=1;
            }
        }
    }
}
int ck(ll n){
    int sq=sqrt(n)+1,cnt=0;
    int ans=1;
    for(int i=0;prime_list[i]<=sq&&prime_list[i]<=n;i++){
            int c=0;
            if(n%prime_list[i]==0){               while(n%prime_list[i]==0){
            n/=prime_list[i];c++;
        }
      sq=sqrt(n);
    if(c){
        ans*=c+1;
}
    }
    }
    if(n>1)ans*=2;
    return ans;
}
 
int main()
{
    ///freopen("input.txt","r",stdin);
    sieve();
    int t,cnt=0;
    sf(t);
    while(t--){
        ll n;
        sfl(n);
        if(n==1){printf("Case %d: 0\n",++cnt);continue;}
        int ans=ck(n);
        printf("Case %d: %d\n",++cnt,ans-1);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
