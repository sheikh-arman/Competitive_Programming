//status accepted
// solution : Trie
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef int ll;
int trie[100005][53];
int idx;
int value(char ch)
{
    if(isupper(ch)) return ch-'A';
    return ch-'a'+26;
}
void insert(string str,ll len)
{
    int cur=0,i;
    for(i=0; i<len; i++)
    {
        int j=value(str[i]);
        if(trie[cur][j]==-1)
        {
            trie[cur][j]=++idx;
            memset(trie[idx],-1,sizeof(trie[idx]));
            trie[idx][52]=0;

        }
        cur= trie[cur][j];
    }
    trie[cur][52]+=1;
}
int search(string str,ll len)
{
    int cur=0,i;
    for(i=0; i<len; i++)
    {
        int j=value(str[i]);
        if(trie[cur][j]==-1)
        {
            return 0;
        }
        cur= trie[cur][j];
    }
    return trie[cur][52];

}
int main()
{
    /***********************************
        Site Name: Lightoj
        Problem No/ID: 1114 (Easily Readable)
    ***********************************/
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
    ll tcase;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {

        idx=0;
        memset(trie[0],-1,sizeof(trie[0]));
        trie[0][52]=0;
        ll n,ans=1;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            string s;
            cin>>s;
            ll len=s.size();
            if(len>2)
            {
                sort(s.begin()+1,s.end()-1);
            }
            insert(s,len);
        }
        ll m;
        cin>>m;
        cout<<"Case "<<test<<":\n";
        for(ll i=0; i<m; i++)
        {
            ans=1;
            string s;
            getline(cin,s);
            while((ll)s.size()==0)
            {
                getline(cin,s);
            }
            ll len=s.size();
            string tm;
            for(ll j=0; j<len; j++)
            {
                if(s[j]==' ')
                {
                    ll le=tm.size();
                    if(le>2)
                    {
                        sort(tm.begin()+1,tm.end()-1);
                    }
                    if(le>0)
                    {
                        ll x=search(tm,le);
                        ans*=x;
                    }
                    tm.clear();
                }
                else
                {
                    tm+=s[j];
                }
            }
            ll le=tm.size();
            if(le>2)
            {
                sort(tm.begin()+1,tm.end()-1);
            }
            if(le>0)
            {
                ll x=search(tm,le);
                ans*=x;
            }
            cout<<ans<<"\n";
        }

    }
    return 0;
}
