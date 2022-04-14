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
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,sum=0;
        string s1,s2,tm;
        while(getline(cin,s1)){
            if((ll)s1.size()>0)break;
        }
        getline(cin,s2);
        ll siz=s1.size();
        for(ll i=0; i<siz; i++)
        {
            if(s1[i]==32)
            {

            }
            else
            {
                if(s1[i]<97)
                {
                    tm+=s1[i]+32;
                }
                else
                {
                    tm+=s1[i];
                }
            }
        }
        s1=tm;
        siz=s2.size();
        tm.clear();
        for(ll i=0; i<siz; i++)
        {
            if(s2[i]==32)
            {

            }
            else
            {
                if(s2[i]<97)
                {
                    tm+=s2[i]+32;
                }
                else
                {
                    tm+=s2[i];
                }
            }
        }
        s2=tm;
        if((ll)s1.size()>(ll)s2.size())
        {
            tm=s1;
            s1=s2;
            s2=tm;
        }
        //string pn=s1;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        ll siz1=s1.size();
        siz1--;
        ll siz2=s2.size();
        ll ck=1;
        for(ll i=siz2-1; i>=0&&siz1>=0; i--)
        {
            if(s1[siz1]==s2[i])
            {
                siz1--;
            }
        }
        if(ck&&siz1<0)
        {
            cout<<"Case "<<test<<": Yes\n";
        }
        else
        {
            cout<<"Case "<<test<<": No\n";
        }
    }
    return 0;
}




