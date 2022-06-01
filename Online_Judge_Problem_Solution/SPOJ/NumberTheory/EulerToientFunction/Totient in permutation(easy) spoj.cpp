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
const int NN=10000100;
ll toten[NN+5];
int ckprime[NN+5];
int dp[NN+5];
void totient()
{
    toten[1]=1;
    for(int i=2; i<NN; i+=2)
    {
        toten[i]=i/2;
        ckprime[i]=1;
    }
    for(int i = 2; i < me; i ++)
    {
        int j = i / p[i];
        if(j % p[i] == 0)
        {
            phi[i] = phi[j] * p[i];
        }
        else
        {
            phi[i] = phi[j] * (p[i] - 1);
        }
    }
}
int ck(int i)
{
    int a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;
    int b0,b1,b2,b3,b4,b5,b6,b7,b8,b9;
    a0=a1=a2=a3=a4=a5=a6=a7=a8=a9=b0=b1=b2=b3=b4=b5=b6=b7=b8=b9=0;
    int n1=i,n2=toten[i];
    while(n1)
    {   int x=n1%10;
        if(x==0)
            a0++;
        else if(x==1)
            a1++;
        else if(x==2)
            a2++;
        else if(x==3)
            a3++;
        else if(x==4)
            a4++;
        else if(x==5)
            a5++;
        else if(x==6)
            a6++;
        else if(x==7)
            a7++;
        else if(x==8)
            a8++;
        else
            a9++;
        n1/=10;
    }
    while(n2)
    {
        int x=n2%10;
        if(x==0)
            b0++;
        else if(x==1)
            b1++;
        else if(x==2)
            b2++;
        else if(x==3)
            b3++;
        else if(x==4)
            b4++;
        else if(x==5)
            b5++;
        else if(x==6)
            b6++;
        else if(x==7)
            b7++;
        else if(x==8)
            b8++;
        else
            b9++;
        n2/=10;
    }
    if(a0==b0&&a1==b1&&a2==b2&&a3==b3&&a4==b4&&a5==b5&&a6==b6&&a7==b7&&a8==b8&&a9==b9)
        return 1;
    else
        return 0;
}
void DP()
{
    double dif=21.0/12;
    int tot=21;
    for(int i=22; i<NN; i++)
    {
        if(toten[i]!=i-1)
        {
            if(ck(i))
            {
                double a=(double)i/toten[i];
                if(a<=dif)
                {
                    dif=a;
                    tot=i;
                }
                dp[i]=tot;
            }
            else
            {
                dp[i]=tot;
            }
        }
        else
        {
            dp[i]=tot;
        }
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);
    totient();
    for(int i=0;i<=1000;i++){
        printf("%d %lld\n",i,toten[i]);
    }
    DP();
    int t;
    sf(t);
    while(t--)
    {
        int n,ans=0,cnt=0,a;
        sf(n);
        if(n<22)
        {
            printf("No solution\n");
            continue;
        }
        printf("%d\n",dp[n]);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

