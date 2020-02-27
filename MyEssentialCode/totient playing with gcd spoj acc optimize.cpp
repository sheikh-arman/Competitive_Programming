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
const int N1=100010;
ll toten[N1];
ll ans[N1];
int ckprime[N1];
void totient()
{
    toten[1]=1;
    ans[1]=0;
    for(int i=2; i<N1; i++)
    {
        if(!ckprime[i])
        {
            ckprime[i]=1;
            //toten[i]=i-1;
            for(int j=i; j<N1; j+=i)
            {
                ckprime[j]=1;
                if(toten[j])
                    toten[j]=(toten[j]/i)*(i-1);
                else
                    toten[j]=(j/i)*(i-1);
            }

        }
        ans[i]+=ans[i-1]+(i-toten[i]);
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);
    //seive();
    totient();
    int t,cnt=0;
    sf(t);
    while(t--)
    {
        int n;
        sf(n);
        printf("Case %d: %lld\n",++cnt,ans[n]);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


