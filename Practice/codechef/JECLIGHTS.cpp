/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll ar_first[30];
ll ar_second[30];
ll mem[30][5];
ll n,m,mx;
ll dp(ll i,ll status)
{
    if(i<mx)
    {
        return 0;
    }
    if(mem[i][status]!=-1)
    {
        return mem[i][status];
    }
    ll ans=LONG_MAX;
    if(status==0)
    {
        if(ar_second[i]!=-1)
        {
            if(i==mx)
            {
                ans=ar_second[i];
            }
            else
            {
                ans=dp(i-1,1)+m;
                ans=min(ans,dp(i-1,0)+(ar_second[i]*2)+1);
            }
        }
        else if(ar_first[i]!=-1)
        {
            if(i==mx)
            {
                ans=ar_first[i];
            }
            else
            {
                ans=dp(i-1,1)+m;
                ans=min(ans,dp(i-1,0)+(ar_first[i]*2)+1);
            }
        }
        else
        {
            ans=dp(i-1,0)+1;
            ans=min(ans,dp(i-1,1)+m);
        }
    }
    else
    {
        if(ar_first[i]!=-1)
        {
            if(i==mx)
            {
                ans=(m-ar_first[i])-1;
            }
            else
            {
                ans=dp(i-1,0)+m;
                ans=min(ans,dp(i-1,1)+(((m-ar_first[i])-1)*2)+1);
            }
        }
        else if(ar_second[i]!=-1)
        {
            if(i==mx)
            {
                ans=(m-ar_second[i])-1;
            }
            else
            {
                ans=dp(i-1,0)+m;
                ans=min(ans,dp(i-1,1)+(((m-ar_second[i])-1)*2)+1);
            }
        }
        else
        {

            ans=dp(i-1,1)+1;
            ans=min(ans,dp(i-1,0)+m);

        }
    }
    return mem[i][status]=ans;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
        {
            ar_first[i]=-1;
            ar_second[i]=-1;
        }
        mx=100;
        m+=2;
        for(ll i=0; i<n; i++)
        {
            string s;
            cin>>s;
            ll ck=0;
            for(ll j=1; j<m-1; j++)
            {
                if(s[j]=='1')
                {
                    if(ck==0)
                    {
                        ar_first[i]=j;
                    }
                    else
                    {
                        ar_second[i]=j;
                    }
                    ck=1;
                }
            }
            if(ck&&mx==100)
            {
                mx=i;
            }
        }
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<4; j++)
            {
                mem[i][j]=-1;
            }
        }
        ll ans=dp(n-1,0);
        cout<<ans<<"\n";
    }
    return 0;
}




