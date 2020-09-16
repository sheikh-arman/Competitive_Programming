/*
    Sk arman Hossain
    University of Barisal

    Problem : UVA 11488(Hyper Prefix Sets)
    Solution : Trie
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
struct node
{
    ll cnt;
    node* next[2+1];
    node()
    {
        cnt = 0;
        for (int i=0; i<2; i++)
            next[i] = NULL;
    }
}*root;

void insert(string str, int len)
{
    node* curr = root;
    for (int i=0; i<len; i++)
    {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->cnt++;
        ans=max(ans,(i+1)*curr->cnt);
    }
}

ll search(char* str, int len)
{
    node* curr = root;
    for (int i=0; i<len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return 0;
        curr = curr->next[id];
    }
    return curr->cnt;
}

void del(node* cur)
{
    for (int i=0; i<2; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tcase;
    cin>>tcase;
    while(tcase--)
    {
        root = new node();
        ll n;
        ans=0;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            string s;
            cin>>s;
            ll len=s.size();
            insert(s, len);
        }
        cout<<ans<<"\n";
        del(root);
    }
    return 0;
}
