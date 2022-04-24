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
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
char str[440][440];
ll status;
ll r,c;
ll checking(ll x,ll y,ll ck)
{
    if(x+dx[ck]>=0&&x+dx[ck]<r&&dy[ck]+y>=0&&dy[ck]+y<c)
    {
        cout<<x<<" "<<y<<" "<<ck<<" c\n";
        if(str[x+dx[ck]][y+dy[ck]]=='.')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
string ans;
void dfs(ll x,ll y, ll prev)
{
    if(prev==0)
    {
        T(prev)
        ll st;
        st=checking(x,y,3);
        if(st)
        {
            ans+='W';
            str[x-1][y]='#';
            dfs(x-1,y,3);
            T(3);
            return;
        }
        st=checking(x,y,0);
        cout<<st<<" hi\n";
        if(st)
        {
            ans+='S';
            str[x+1][y]='#';
            dfs(x+1,y,0);
            return;
        }

        st=checking(x,y,2);
        if(st)
        {
            ans+='E';
            str[x][y+1]='#';
            dfs(x,y+1,2);
            return;
        }
    }
    else if(prev==1)
    {
        ll st=checking(x,y,1);
        st=checking(x,y,3);
        if(st)
        {
            ans+='W';
            str[x-1][y]='#';
            dfs(x-1,y,3);
            return;
        }
        st=checking(x,y,1);
        if(st)
        {
            ans+='N';
            str[x][y-1]='#';
            dfs(x,y-1,1);
            return;
        }
        st=checking(x,y,2);
        if(st)
        {
            ans+='S';
            str[x+1][y]='#';
            dfs(x+1,y,2);
            return;
        }
    }
    else if(prev==2)
    {
        ll st;
        st=checking(x,y,0);
        if(st)
        {
            ans+='S';
            str[x+1][y]='#';
            dfs(x+1,y,0);
            return;
        }
        st=checking(x,y,2);
        if(st)
        {
            ans+='S';
            str[x+1][y]='#';
            dfs(x+1,y,2);
            return;
        }
        st=checking(x,y,1);
        if(st)
        {
            ans+='N';
            str[x][y-1]='#';
            dfs(x,y-1,1);
            return;
        }
    }
    else
    {
        ll st;
        st=checking(x,y,0);
        if(st)
        {
            ans+='S';
            str[x+1][y]='#';
            dfs(x+1,y,0);
            return;
        }
        st=checking(x,y,1);
        if(st)
        {
            ans+='N';
            str[x][y-1]='#';
            dfs(x,y-1,1);
            return;
        }
        st=checking(x,y,3);
        if(st)
        {
            ans+='W';
            str[x-1][y]='#';
            dfs(x-1,y,3);
            return;
        }
    }
}

int main()
{
    freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ans.clear();
        status=1;
        cin>>r>>c;
        string s;
        ll cnt=0;
        r*=2;
        c*=2;
        for(ll i=0; i<r; i+=2)
        {
            cin>>s;
            cnt=0;
            for(ll j=0; j<c; j+=2)
            {
                if(s[cnt++]=='.')
                {
                    str[i][j]='.';
                    str[i+1][j]='.';
                    str[i][j+1]='.';
                    str[i+1][j+1]='.';
                }
                else
                {
                    str[i][j]='#';
                    str[i+1][j]='#';
                    str[i][j+1]='#';
                    str[i+1][j+1]='#';
                }
            }
        }
        dfs(0,0,0);
        if(status)
        {
            cout<<"Case #"<<test<<": "<<ans<<"\n";
        }
        else
        {
            cout<<"Case #"<<test<<": IMPOSSIBLE\n";
        }
    }
    return 0;
}




