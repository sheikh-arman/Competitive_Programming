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
vector<int>prime;
vector<int> :: iterator it1,it2;
int totient(int n){
    int ans=n;
    int sq=sqrt(n)+1;
    for(int i=2;i<=sq;i++){
        if(n%i==0){
            while(n%i==0)
                n/=i;
            ans-=ans/i;
        }
    }
    if(n>1)
        ans-=ans/n;
    return ans;
}
int main()
{
    ///freopen("input.txt","r",stdin);

        int n,ans=0,cnt=0,a;
        while(sf(n)&&n){
        ans=totient(n);
        printf("%d\n",ans);
        }
///*****************************  ALHAMDULILLAH  *****************************/
}

