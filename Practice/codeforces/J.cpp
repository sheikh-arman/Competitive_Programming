#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
int rep[30];
int Find(int node)
{
    return (rep[node]==node)?node:rep[node]=Find(rep[node]);
}
int main()
{
    freopen("1input.txt","r",stdin);
    for(int i=0; i<=26; i++)
    {
        rep[i]=i;
    }
    fast;
    int n;
    cin>>n;
    int len=0;
    vector< pair<char,char> >V;
    vector<int>value;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        value.PB(a);
        if(a==1)
        {
            char ch;
            cin>>ch;
            V.PB({ch,'#'});
            len++;
        }
        else if(a==2)
        {
            V.PB({'#','#'});
            if(len>0)len--;
        }
        else
        {
            char ch1,ch2;
            cin>>ch1>>ch2;
            V.PB({ch1,ch2});
            int val=Find(V[i].second-'a');
            rep[Find(V[i].first-'a')]=val;
        }
    }
    if(len==0)
    {
        cout<<"The final string is empty\n";
        return 0;
    }
    string s;
    for(int i=0; i<len; i++)
    {
        s+='#';
    }
    int cnt=0;
    int ar[n+10];
    for(int i=0; i<n; i++)
    {
        ar[i]=0;
    }
    for(int i=n-1; i>=0; i--)
    {
        if(value[i]==1)
        {
            if(cnt>0)cnt--;
            else
            {
                ar[i]=1;
            }
        }
        else if(value[i]==2)
        {
            cnt++;
        }
    }
    len=0;
    for(int i=0; i<n; i++)
    {
        if(ar[i]==1)
        {
            int val=Find(V[i].first-'a');
            s[len]=char(val+'a');
            len++;
        }
    }
    cout<<s<<"\n";
    return 0;
}
/*
Special Case:
6
1 a
1 d
1 b
3 d b
1 b
3 a d

Ans: dbbb

*/



