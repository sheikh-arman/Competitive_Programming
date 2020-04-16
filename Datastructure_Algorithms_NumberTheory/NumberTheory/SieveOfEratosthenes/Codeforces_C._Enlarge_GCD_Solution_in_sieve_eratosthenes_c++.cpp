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
int dx[]={0,0,1,1};
int dy[]={1,1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int>v,v2,v3;
vector<int> :: iterator it1,it2;
const int M=1.5e7+5;
int arck[M];
int ck[M],ans,cnt,ma;
void sieve(){
    for(int i=2;i<=ma;i+=2){
        ans+=arck[i];
    }
    for(int i=3;i<=ma;i+=2){
            cnt=0;
        if(!ck[i]){
            for(int j=i;j<=ma;j+=i){
                ck[j]=1;cnt+=arck[j];
            }
            if(cnt>ans)
                ans=cnt;
        }
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);
    ///while(1){
    int n,a,gc=0;
    sf(n);
    for(int i=0;i<n;i++){
        sf(a);v.pb(a);
        gc=__gcd(a,gc);
        if(ma<a)
            ma=a;
    }
    for(int i=0;i<n;i++)
        arck[v[i]/gc]++;
    sieve();
    cout<<(ans?n-ans:-1)<<endl;
///*****************************  ALHAMDULILLAH  *****************************/
}
