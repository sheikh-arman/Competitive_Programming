#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
    bool endmark;
    node* next[10+1];
    node()
    {
        endmark = false;
        for (ll i=0; i<10; i++)
            next[i] = NULL;
    }
}*root;

bool insert(string str, ll len)
{
    bool ck=0;
    node* curr = root;
    for (int i=0; i<len; i++)
    {
        ll id = str[i] - '0';
        if (curr->next[id] == NULL)
        {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
        if(curr->endmark==true)ck=1;
    }
    curr->endmark = true;
    return ck;
}

bool search(char* str, int len)
{
    node* curr = root;
    for (int i=0; i<len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur)
{
    for (int i=0; i<10; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}


int main()
{
    /***********************************
    	Site Name: lightoj
    	Problem No/ID: 1129 (Consistency Checker)
    ***********************************/
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase;
    cin>>tcase;
   for(ll test=1;test<=tcase;test++)
    {
        vector<string>V;
        root = new node();
        ll n,ans=0;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            string s;
            cin>>s;
            V.push_back(s);
        }
        sort(V.begin(),V.end());
        for(ll i=0; i<n; i++)
        {
            string s=V[i];
            ll len=s.size();
            bool tm= insert(s, len);
            ans|=tm;
        }
        if(ans)
        {
            cout<<"Case "<<test<<": NO\n";
        }
        else
        {
            cout<<"Case "<<test<<": YES\n";
        }
        del(root);
    }
    return 0;
}

