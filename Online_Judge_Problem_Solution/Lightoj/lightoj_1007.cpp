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
const int N1=5000010;
ull toten[N1+5];
void totient(){
    for(int i=1;i<N1;i++){
        toten[i]=i;
    }
    for(int i=2;i<N1;i+=1){
        if(toten[i]==i){
            toten[i]=i-1;
            for(int j=i+i;j<N1;j+=i){
                toten[j]-=toten[j]/i;
            }
        }
        toten[i]=toten[i-1]+(toten[i]*toten[i]);
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);
    totient();
    int t,cnt=0;
    sf(t);
    while(t--)
    {
        int a,b;
        sff(a,b);
        ull ans=toten[b]-toten[a-1];
        printf("Case %d: %llu\n",++cnt,ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
