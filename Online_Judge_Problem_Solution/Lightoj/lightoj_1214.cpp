
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
bool ck(string a,ll b){
    ll extra=0;
    for(ll i=0;a[i]!='\0';i++){
        ll digit=a[i]-'0';
        extra*=10;
        extra+=digit;
        extra%=b;
    }
    if(extra)
        return false;
    else
        return true;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string a;
        ll b;
        cin>>a>>b;
        b=abs(b);
        if(a[0]=='-'){
            reverse(a.begin(),a.end());
            a.pop_back();
            reverse(a.begin(),a.end());
        }
        bool ans=ck(a,b);
        if(ans){
            cout<<"Case "<<test<<": divisible"<<endl;
        }
        else{
            cout<<"Case "<<test<<": not divisible"<<endl;
        }
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}


