#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
ll ar[200010];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,k;
        cin>>n>>k;

        string s;
        cin>>s;
        if(n==1)
        {
            cout<<s<<"\n";
            cout<<k<<"\n";
            continue;
        }
        for(ll i=0; i<=n; i++)
        {
            ar[i]=0;
        }
        ll sum=0;
        string ans=s;
        for(ll i=0; i<n-1; i++)
        {
            ll val=sum%2;
            val+=(s[i]-'0');
            val%=2;
            if(val==0)
            {
                ans[i]='0';
                if(k%2==0&&k>0)
                {
                    ans[i]='1';
                    k--;
                    sum+=1;
                    ar[i]=1;
                }
                else
                {
                    if(k>0)
                        ans[i]='1';
                    continue;
                }
            }
            else
            {
                ans[i]='1';
                if(k%2!=0)
                {
                    k--;
                    ar[i]=1;
                    sum+=1;
                }
                ans[i]='1';
            }
        }
        ll val_last=sum%2;
        val_last+=(s[n-1]-'0');
        val_last%=2;
        ans[n-1]=(char)(val_last+'0');
        ar[n-1]=k;
//        if(k%2==0){
//            ar[n-1]=k;
//            ans[n-1]=(char)(val_last+'0');
//        }
//        else{
//
//        }
        cout<<ans<<"\n";
        for(ll i=0; i<n; i++)
        {
            cout<<ar[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}





