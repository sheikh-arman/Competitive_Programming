
/*
    Sk arman Hossain
    University of Barisal

    Problem : Codeforces 1370D Odd-Even Subsequence
    Solution : Binary Search
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
vector<ll>V,V2;
ll n,k;
ll ck(ll status,ll mx){
    ll cnt=0,cc=status;
    for(ll i=0;i<n;i++){
        if(status){
            if(mx>=V[i]){
                cnt++;
                status^=1;
            }
        }
        else{
            status^=1;
            cnt++;
        }
    }
    return cnt>=k;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll tcase=1;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n>>k;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V.PB(a);
            V2.PB(a);
        }
        VST(V2);
        ll left=0,right=n-1,ans=LONG_MAX;
        while(left<right){
            ll mid=(left+right)/2;
            if(ck(0,V2[mid])||ck(1,V2[mid])){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        cout<<V2[left]<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


