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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
ll mat[20][20];
ll out[20][20];
ll mem[(1<<13)][13];
ll SET(ll NUM,ll POS)
{
    return NUM | (1<<POS);
}
bool isOn(ll NUM,ll POS)
{
    return (bool)(NUM & (1<<POS));
}
ll n;
ll dp(ll mask,ll pre, ll nn)
{
    if(nn==n)
    {
        return 0;
    }
    if(mem[mask][pre]!=-1)
    {
        return mem[mask][pre];
    }
    ll ans=0;
    for(ll i=0; i<n; i++)
    {
        if(isOn(mask,i))continue;
        ll new_mask=SET(mask,i);
        ll tm=mat[pre][i];
        if(out[pre][i]==1)
        {
            tm+=dp(new_mask,pre,nn+1);
        }
        else
        {
            tm+=dp(new_mask,i,nn+1);
        }
        ans=max(ans,tm);

    }
    return mem[mask][pre]=ans;
}
ll stiConvert(string a, int base = 10)
{
    ll ans1 = 0;
    for (int i = 0; i < (int)a.size(); ++i)
    {
        ans1 *= base;
        ans1 += a[i]-'0';
    }
    return ans1;
}
int main()
{
    //cout<<(1<<2)-1;
    map<char,ll>mp;
    map<char,ll>mp2;
    mp2['T']=0;
    mp2['F']=1;
    for(ll i=0; i<10; i++)
    {
        char ch=(i+'0');
        mp[ch]=i;
    }
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n;
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=n; j++)
            {
                mat[i][j]=0;
                out[i][j]=0;
            }
        }
        for(ll i=0; i<=(1<<(n+1)); i++)
        {
            for(ll j=0; j<=n+1; j++)
            {
                mem[i][j]=-1;
            }
        }
        ll cntr=0;
        cin.ignore();
        for (int i = 0; i < n; ++i)
        {
            char ch;
            string s,s1;
            getline(cin, s);
            cntr = 0;
            for (int j = 0; j < n; ++j)
            {
                cntr++;
                s1 ="";
                while(s[cntr] != ',')
                {
                    s1 += s[cntr];
                    cntr++;
                }
                cntr++;
                cntr++;
                mat[i][j] = stiConvert(s1);
                if(s[cntr]== 'T') out[i][j]=1;
                else out[i][j] = 0;
                cntr++;
                cntr++;
                cntr++;
            }
        }
        ll ans=0;
        for(ll i=0; i<n; i++)
        {
            ll mask=(1<<i);
            // cout<<mask<<" t\n";
            ans=max(ans,dp(mask,i,0));
        }
        cout<<"Case "<<test<<": "<<ans<<"\n";
    }
    return 0;
}






