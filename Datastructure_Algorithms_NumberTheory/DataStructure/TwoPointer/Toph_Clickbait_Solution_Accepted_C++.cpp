/*
    Sk arman Hossain
    University of Barisal

    Problem name : toph clickbait
    Algorithm :Two pointer
 */

#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
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
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}
//ll big_mod(ll base,ll power,ll Mod){if(power==0){return 1;}else if(power%2==1){ll p1=base%Mod;ll p2=(big_mod(base,power-1,Mod))%Mod;return (p1*p2)%Mod;}else if(power%2==0){ll p1=(big_mod(base,power/2,Mod))%mod;return (p1*p1)%Mod;}}


int main()
{
    //freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    fastIO();
    ll tcase=1;
    //sf1(tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        vector<string>V1,trend;
        for(ll i=0; i<n; i++)
        {
            string s3;
            cin>>s3;
            if(s3[0]=='#')
            {
                s3.erase(s3.begin());
                trend.PB(s3);
            }
            else
            {
                V1.PB(s3);
            }
        }
        VST(trend);
        VST(V1);
        if(V1.size()&&trend.size())
        {
            ll left=0,right=0,ck=1;
            ll lenv=V1.size(),lentrend=trend.size();
            if(lenv<lentrend)
                lentrend=lenv;
            while(left<lenv&&right<lentrend)
            {
                if(V1[left]==trend[right])
                {
                    cout<<V1[left]<<" "<<trend[right];
                    if(left+right<(lenv+lentrend)-1)
                    {
                        cout<<" ";
                    }
                    left++;
                    right++;
                }
                else if(V1[left]<trend[right])
                {
                    if(lenv-left>=lentrend-right)
                    {
                        cout<<V1[left];
                        ck=1;

                        cout<<" ";

                        left++;
                    }
                    else
                    {
                        cout<<trend[right];
                        ck=0;
                        cout<<" ";
                        right++;
                    }
                }
                else
                {
                    if(ck==1)
                    {
                        cout<<trend[right];
                        ck=0;
                        cout<<" ";
                        right++;
                    }
                    else
                    {
                        cout<<V1[left];
                        ck=1;
                        cout<<" ";
                        left++;
                    }
                }

            }
            while(left<lenv)
            {
                cout<<V1[left];
                if(left<lenv-1)
                    cout<<" ";
                left++;
            }
            if(right<lentrend)
            {
                cout<<trend[right];
            }
            cout<<endl;


        }
        else
        {
            if(V1.size()==0)
            {
                cout<<endl;
            }
            else
            {
                ll len=V1.size();
                for(ll i=0; i<len; i++)
                {
                    cout<<V1[i];
                    if(i<len-1)
                        cout<<" ";
                }
                cout<<endl;
            }
        }
        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
