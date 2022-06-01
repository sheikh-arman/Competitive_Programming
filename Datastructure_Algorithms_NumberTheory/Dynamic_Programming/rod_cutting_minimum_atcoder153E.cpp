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
//ll big_mod(ll base,ll power,ll Mod){if(power==0){return 1;}else if(power%2==1){ll p1=base%Mod;ll p2=(big_mod(base,power-1,Mod))%Mod;return (p1*p2)%Mod;}else if(power%2==0){ll p1=(big_mod(base,power/2,Mod))%mod;return (p1*p1)%Mod;}}
class PAIR
{
public:
    ll first;
    ll second;
    ll third;
};



//vector<ll>prime_list;
//bool prime_ck[10000001];
//void seive()
//{
//    prime_ck[0]=prime_ck[1]=1;
//    prime_list.push_back(2);
//    for(int i=4; i<=100000; i+=2)
//    {
//        prime_ck[i]=1;
//    }
//    for(int i=3; i<=100000; i+=2)
//    {
//        if(prime_ck[i]==0)
//        {
//            prime_list.push_back(i);
//            for(int j=i+i; j<=100000; j+=i+i)
//            {
//                prime_ck[j]=1;
//            }
//        }
//    }
//}


//bool operator<(const nod& t1, const nod& t2)
//{
//    return (t1.x1 < t2.x1||t1.y1<t2.y1);
//}


/*
int rep[200010];
void initial(int n){
    for(int i=1;i<=n;i++){
        rep[i]=i;
    }
}
int find_representative(int node){
    if(rep[node]==node){
        return node;
    }
    else{
        rep[node]=find_representative(rep[node]);
        return rep[node];
    }
}
void joint_node(int nodex,int nodey){
    int u=find_representative(nodex);
    int v=find_representative(nodey);
    if(u!=v){
        rep[u]=v;
    }
}
*/
/*
vector<ll>nod[200100],V3;
ll label[200100]={-1};
void dfs(ll node){
    for(ll i=0;i<nod[node].size();i++){
        ll x=nod[node][i];
        if(label[x]==-1){
            label[x]=label[node]+1;
            dfs(x);
        }
    }
}
*/
/*
vector<ll>nod[200100],v3;
ll label[200100]={-1};
void bfs(ll node){
    memset(label,-1,sizeof(label));
    queue<ll>q;
    q.push(node);
    while(!q.empty()){
        ll x;
        x=q.front();
        q.pop();
        ll siz=nod[x].size();
        for(ll i=0;i<siz;i++){
            ll tmp=nod[x][i];
            if(label[tmp]==-1){
                label[tmp]=label[x]+1;
                q.push(tmp);
            }
        }
    }
}

void graph_input(ll edge){
    for(ll i=0;i<edge;i++){
        ll a,b;
        scanf("%lld %lld",&a,&b);
        nod[a].push_back(b);
        nod[b].push_back(a);
    }
}*/
//
//bool cmp(ll a,ll b){
//    return a<b;
//}
//
vector<ll>V,V2,V3;
//int max(int a, int b) { return (a > b)? a : b;}
ll dp[1000000];
ll unit[100000];
ll price[100000];
ll k;
ll cutRod(ll n)
{

    if (n <= 0){
        return 0;
    }
    else if(dp[n]!=-1)
    {
        return dp[n];
    }
    else
    {
        ll  min_val = LONG_MAX;
        for (ll i = 0; i<k; i++)
        {

                min_val = min(min_val, price[i] + cutRod(n-unit[i]));

          //  printf("%lld %lld\n",n,min_val);
        }
        dp[n]=min_val;
        return dp[n];
    }

}

/* Driver program to test above functions */
int main()
{
    //freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        sf2(n,k);
        for(ll i=0;i<k;i++){
            ll a,b;
            sf2(a,b);
            unit[i]=a;
            price[i]=b;
        }
        for(ll i=0; i<=n; i++)
        {
            dp[i]=-1;
        }
        printf("%lld\n", cutRod(n));
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}



