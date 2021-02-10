/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) cin>>n
#define sf2(n, m) cin>>n>>m
#define sf3(n, m,k ) cin>>n>>m>>k
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define minus1 printf("-1\n");
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
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
int ar[2010][2010],pre[2010],sup[2010];
int main()
{
    fast;
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<ll>V;
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=m; j++)
            {
                ar[i][j]=0;
            }
        }
        string s;
        ll ans=0;
        for(ll i=0; i<n; i++)
        {
            cin>>s;
            for(ll j=0; j<m; j++)
            {
                if(s[j]=='0')
                {
                    ar[i][j]+=1;
                    if(i-1>=0)
                    {
                        ar[i][j]+=ar[i-1][j];
                    }
                }
                else
                {
                    ar[i][j]=0;
                }
                pre[j]=0;
                sup[j]=0;
            }
            stack<PR>stk;
            for(ll j=0; j<m; j++)
            {
                ll val=ar[i][j];
                if(stk.empty())
                {
                    stk.push({val,j});
                    pre[j]=1;
                }
                else
                {
                    PR tp=stk.top();
                    ll pos=j;
                    pre[j]=1;
                    while(1)
                    {
                        if(!stk.empty())
                        {
                            tp=stk.top();
                            if(tp.first>=val)
                            {
                                pos=tp.second;
                                stk.pop();
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }

                    }
                    pre[j]=pre[pos]+abs(pos-j);
                    stk.push({val,j});
                }
            }
            while(!stk.empty())stk.pop();
            for(ll j=m-1; j>=0; j--)
            {
                ll val=ar[i][j];
                if(stk.empty())
                {
                    stk.push({val,j});
                    sup[j]=1;
                }
                else
                {
                    PR tp=stk.top();
                    ll pos=j;
                    sup[pos]=1;
                    while(1)
                    {
                        if(!stk.empty())
                        {
                            tp=stk.top();
                            if(tp.first>=val)
                            {
                                pos=tp.second;
                                stk.pop();
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }

                    }
                    sup[j]=sup[pos]+abs(pos-j);
                    stk.push({val,j});
                }
            }
            ll ma=0;
            for(ll j=0; j<m; j++)
            {
                ll tm=((pre[j]+sup[j])-1)*(ar[i][j]);
                ma=max(tm,ma);
            }
            ans=max(ma,ans);
        }
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}




