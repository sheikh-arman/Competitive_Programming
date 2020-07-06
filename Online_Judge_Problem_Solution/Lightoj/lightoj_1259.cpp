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
const int N1=10000000;
vector<int>prime_list;
bool prime_ck[N1+5];
void sieve(){
    prime_list.push_back(2);
    for(int i=4;i<N1;i+=2){
        prime_ck[i]=true;
    }
    for(int i=3;i<N1;i+=2){
        if(prime_ck[i]==0){
            prime_list.push_back(i);
            for(int j=i+i+i;j<N1;j+=2*i){
                prime_ck[j]=true;
            }
        }
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);
    sieve();
    int t,cnt=0;
    sf(t);
    while(t--)
    {
        int n,ans=0;
        sf(n);
        for(int i=0;prime_list[i]<=n/2;i++){
            if(prime_ck[n-prime_list[i]]==false)
                ans++;
        }
        printf("Case %d: %d\n",++cnt,ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
