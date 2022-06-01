#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
ll rep[20000],ck;
map<string,ll>m;
ll representative(ll node)
{
    if(rep[node]==node)
    {
        return node;
    }
    else
    {
        return rep[node]=representative(rep[node]);
    }
}
void joint (ll u,ll v)
{
    ll ru=representative(u);
    ll rv=representative(v);
    if(ru!=rv)
    {
        rep[ru]=rv;
    }
    else
    {
        ck=1;
       // printf("test %lld\n");
    }
}
int main()
{
    ll TCASE=1;
    scanf("%lld",&TCASE);
    for(ll TEST=1; TEST<=TCASE; TEST++)
    {
        m.clear();
        ll n,cnt=1;
        ck=0;
        scanf("%lld",&n);
        for(ll i=1; i<=n*2; i++)
        {
            rep[i]=i;
        }
        for(ll i=0; i<n; i++)
        {

            char ch1[20],ch2[20];
            scanf("%s%s",ch1,ch2);
            if(m[ch1]==0)
            {
                m[ch1]=cnt++;
            }
            if(m[ch2]==0)
            {
                m[ch2]=cnt++;
            }
            joint(m[ch1],m[ch2]);
        }
        if(ck==0)
        {
            printf("Case %lld: Yes\n",TEST);
        }
        else
        {
            printf("Case %lld: No\n",TEST);
        }

    }
}
