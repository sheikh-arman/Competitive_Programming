#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node
{
    vector<int>V;
    node* next[300];
    node()
    {
        for (int i=0; i<290; i++)
            next[i] = NULL;
    }
}*root;

void insert(string str, int len, int version)
{
    node* curr = root;
    for (int i=0; i<len; i++)
    {
        ll id = str[i];
        if (curr->next[id] == NULL)
        {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
    }
    curr->V.push_back(version);
}

bool search(string str, int len,ll version)
{
    node* curr = root;
    for (int i=0; i<len; i++)
    {
        int id = str[i];
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    if(curr->V.size()==0)return 0;
    ll pos=lower_bound(curr->V.begin(),curr->V.end(),version)-curr->V.begin();
    ll siz=curr->V.size();
    if(pos>=siz){
        return siz%2;
    }
    else if(curr->V[pos]==version){
        return 1;
    }
    else if(pos%2){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
   // fast;
    root = new node();
    vector<string>V;
    string task;
    getline(cin,task);
    string s;
    int siz=task.size();
    for(int i=1;i<siz;i++){
        if(task[i]==' ')continue;
        if(task[i]==','||task[i]==']'){
            V.push_back(s);
            s.clear();
        }
        else s+=task[i];
    }
    int version=1;
    for(auto i:V){
        insert(i,(int)i.size(),version);
    }
    string command;
    while(cin>>command){
        if(command=="Check"){
            string ver,feature;
            cin>>ver;
            int tm_version=0;
            for(int i=8;i<ver.size();i++){
                tm_version*=10;
                tm_version+=(ver[i]-'0');
            }
            cin>>feature;
            bool ck=search(feature,feature.size(),tm_version);
            if(ck){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
            continue;
        }
        version++;
        if(command=="Add"){
            string feature;
            cin>>feature;
            insert(feature,feature.size(),version);
        }
        else{
            string feature_previous, feature_new;
            cin>>feature_previous;
            cin>>feature_new;
            insert(feature_previous,feature_previous.size(),version-1);
            insert(feature_new,feature_new.size(),version);
        }
    }
    return 0;
}
