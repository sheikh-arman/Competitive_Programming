/*
    Sk arman Hossain
    University of Barisal

    Problem : Codeforces 1399D. Binary String To Subsequences
    Solution : queue
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
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<ll>V,V2;
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll ans=1,cnt=1,pre=-1;
        for(ll i=0; i<n; i++)
        {
            V2.PB((s[i]=='0'?0:1));
        }
        //priority_queue<ll, vector<ll>, greater<ll> > pqzero,pqone;
        queue<ll> pqzero,pqone;
        for(ll i=0; i<n; i++)
        {
            if(pre==V2[i])
            {
                if(V2[i]==0)
                {
                    if((ll)pqone.size()>0)
                    {
                        V.PB(pqone.front());
                        pqzero.push(pqone.front());
                        pqone.pop();
                    }
                    else
                    {
                        ll siz=pqzero.size();
                        pqzero.push(siz+2);
                        V.PB(siz+2);
                    }
                    //cout<<i<<" "<<
                }
                else
                {
                    if((ll)pqzero.size()>0)
                    {
                        V.PB(pqzero.front());
                        pqone.push(pqzero.front());
                        pqzero.pop();
                    }
                    else
                    {
                        ll siz=pqone.size();
                        pqone.push(siz+2);
                        V.PB(siz+2);
                    }
                }
            }
            else
            {
                V.PB(1);
            }
            pre=V2[i];
        }
        ans=pqzero.size()+pqone.size()+1;
        cout<<ans<<"\n";
        for(ll i=0; i<n; i++)
        {
            cout<<V[i]<<" ";
        }
        cout<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
/*
wa test
7
1001001
ans
3
1 1 2 1 1 3 1

time limit test

0000000000100100100100


*/



