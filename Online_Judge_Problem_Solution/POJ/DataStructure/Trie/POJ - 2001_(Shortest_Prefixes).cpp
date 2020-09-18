#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct node
{
    int endmark;
    node* next[26+1];
    node()
    {
        endmark = 0;
        for (int i=0; i<26; i++)
            next[i] = NULL;
    }
}*root;
void insert(string str, int len)
{
    node* curr = root;
    for (int i=0; i<len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->endmark=curr->endmark+1;
    }
}
void search(string str, int len)
{
    node* curr = root;
    for (int i=0; i<len; i++)
    {
        int id = str[i] - 'a';
        curr = curr->next[id];
        cout<<str[i];
        if(curr->endmark==1)
        {
            break;
        }
    }
}
void del(node* cur)
{
    for (int i=0; i<26; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}

int main()
{
    /***********************************
    	Site Name: POJ
    	Problem No/ID: 2001 Shortest Prefixes
    ***********************************/
    vector<string>V;
    root = new node();
    string s;
    while(getline(cin,s))
    {
        if((int)s.size()==0)break;
        int len=s.size();
        insert(s,len);
        V.push_back(s);
    }
    int n=V.size();
    for(int i=0; i<n; i++)
    {
        cout<<V[i]<<" ";
        search(V[i],(int)V[i].size());
        cout<<endl;
    }
    del(root);

    return 0;
}

