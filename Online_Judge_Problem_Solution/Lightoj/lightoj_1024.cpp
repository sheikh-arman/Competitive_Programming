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
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<ll>prime;
ll ar[10010];
void seive(){
    bitset<10020>ck;
    prime.PB(2);
    for(ll i=3;i<=10000;i+=2){
        if(ck[i]==false){
            prime.PB(i);
            for(ll j=i*i;j<=10000;j+=(i+i)){
                ck[j]=true;
            }
        }
    }
}
void fac(ll n){
    ll sq=sqrt(n+1);
    ll siz=prime.size();
    for(ll j=0;j<siz&&prime[j]<=sq;j++){
        ll cnt=0;
        while(n%prime[j]==0){
            n/=prime[j];
            cnt++;
        }
        ar[prime[j]]=max(ar[prime[j]],cnt);
        sq=sqrt(n);
    }
    if(n>1){
        ar[n]=max(ar[n],1ll);
    }
}
string cal(){
    ll siz=prime.size();
    string s="1";
    for(ll i=0;i<siz;i++){
        if(ar[prime[i]]){
            ll num=pow(prime[i],ar[prime[i]]);
            ll str_siz=s.size();
            ll baki=0;
            string temp;
            for(ll j=0;j<str_siz;j++){
                ll val=(s[j]-'0')*num;
                val+=baki;
                temp+=(val%10)+'0';
                val/=10;
                baki=val;
            }
            while(baki){
                temp+=(baki%10)+'0';
                baki/=10;
            }
            s=temp;
        }
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    seive();
    //ios_base::sync_with_stdio(false);cin.tie(0);
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        for(ll i:prime){
            ar[i]=0;
        }
        vector<ll>V;
        ll n,a;
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>a;
            fac(a);
        }
        string s=cal();
        cout<<"Case "<<test<<": "<<s<<endl;
       // printf("Case %lld: %lld\n",test,mul);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



