/*
    Sk arman Hossain
    University of Barisal

    Problem name :
    Algorithm :
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
vector<ll>nod[500010],tree[500010];
ll ar[500010];
void merg(vector<ll>v1,vector<ll>v2,ll n){
    ll siz1=v1.size();
    ll siz2=v2.size();
    ll left=0,right=0;
    tree[n].clear();
    while(left<siz1&&right<siz2){
        if(v1[left]<=v2[right]){
            tree[n].PB(v1[left]);left++;
        }
        else{
            tree[n].PB(v2[right]);right++;
        }
    }
    while(left<siz1){
        tree[n].PB(v1[left]);left++;
    }
    while(right<siz2){
        tree[n].PB(v2[right]);right++;
    }
}
ll dfs(ll n)
{
    if(nod[n].size()==0){
        return 0;
    }
    ll siz=nod[n].size();
    for(ll i=0;i<siz;i++){
       ll xx= dfs(nod[n][i]);
       merg(tree[n],tree[nod[n][i]],n);
    }
    return 0;
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,q;
        sf2(n,q);
        for(ll i=2; i<=n; i++)
        {
            ll a;
            sf1(a);
            nod[a].PB(i);
        }
        for(ll i=1; i<=n; i++)
        {
            ll a;
            sf1(a);
            ar[i]=a;
            tree[i].PB(a);
        }
        ll zz=dfs(1);
        for(ll i=0;i<q;i++){
            ll a,x;
            sf2(a,x);
            ll pos=lower_bound(tree[a].begin(),tree[a].end(),x)-tree[a].begin();
            ll siz=tree[a].size();
            printf("%lld\n",siz-pos);

        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


