/*
    Sk arman Hossain
    University of Barisal

    Problem : Codeforces 1363 D Guess The Maximums
    Solution : Binary Search(Interactive)
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
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
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
vector<ll>V[1010];
int main()
{
    cout.flush();
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        cin>>n>>k;
        for(ll i=0; i<=k; i++)
        {
            V[i].clear();
        }
        for(ll i=0; i<k; i++)
        {
            ll a;
            cin>>a;
            for(ll j=0; j<a; j++)
            {
                ll b;
                cin>>b;
                V[i].PB(b);
            }
        }
        cout<<"? "<<n;
        for(ll i=1; i<=n; i++)cout<<" "<<i;
        cout<<"\n";
        ll ma;
        cin>>ma;
        ll l=0,r=k-1,mid=0,index;
        while(l<r)
        {
            mid=(l+r)/2;
            vector<ll>tm;
            ll siz,x=0;
            for(ll i=l; i<=mid; i++)
            {
                siz=V[i].size();
                for(ll j=0; j<siz; j++)
                {
                    tm.PB(V[i][j]);
                }
            }
            siz=tm.size();
            cout<<"? "<<siz;
            for(ll i=0; i<siz; i++)
            {
                cout<<" "<<tm[i];
            }
            cout<<"\n";
            cin>>x;
            if(x==ma)
            {
                r=mid;
            }
            else
            {
                mid++;
                l=mid;
            }
        }
        ll ma2=ma;
        if(n-V[l].size())
        {
            cout<<"? "<<n-V[l].size();
            for(int i=1; i<=n; i++)
            {
                if(!count(V[mid].begin(),V[mid].end(),i)) cout<<" "<<i;
            }
            cout<<endl;
            cin>>ma2;
        }
        cout<<"!";
        for(ll i=0; i<k; i++)
        {
            if(i==mid)
            {
                cout<<" "<<ma2;
            }
            else
            {
                cout<<" "<<ma;
            }
        }
        cout<<"\n";
        string s;
        cin>>s;

    }
///*****************************  ALHAMDULILLAH  *****************************/
}


