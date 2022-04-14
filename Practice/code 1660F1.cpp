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
ll plu[3010];
ll minu[3010];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<=n; i++)
        {
            plu[i]=minu[i]=0;
        }
        string s;
        cin>>s;
        for(ll i=0; i<n; i++)
        {
            if(s[i]=='+')
            {
                plu[i]+=1;
            }
            else
            {
                minu[i]+=1;

            }
            if(i>0)
                plu[i]+=plu[i-1];
            if(i>0)
                minu[i]+=minu[i-1];
        }
        ll cnt=0;
        for(ll i=0; i<n-1; i++)
        {
            for(ll j=i+1; j<n; j++)
            {
                ll mi=minu[j];
                ll pos=i-1;
                if(i!=0)
                {
                    mi-=minu[pos];
                }

                ll pl=plu[j];
                pos=i-1;
                if(i!=0)
                {
                    pl-=plu[pos];
                }
                if(mi==pl)
                {
                    cnt+=1;
                }
                else
                {
                    ll di=mi-pl;
                    if(di>0)
                    {
                        if(di%3==0)
                        {
                            cnt+=1;
                        }
                    }
                }
            }
        }
        cout<<cnt<<"\n";

    }
    return 0;
}





