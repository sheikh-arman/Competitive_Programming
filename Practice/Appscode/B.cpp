#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main(){ 
    //fast;
    string username;
    vector<pair< pair<int,int> ,pair<int,string> > > V;
    //int cnt=0;
    while(cin>>username){
        int follower;
        cin>>follower;
        cin.ignore();
        string content;
        getline(cin,content);
        int siz=content.size();
        //cout<<content<<" t\n";
        set<char>tm;
        int ck=0;
        for(int i=0;i<siz;i++){
            if(content[i]=='<'||content[i]=='>'||content[i]==' ')continue;
            if(content[i]=='#' && i==siz-1){
                ck=1;continue;
            }
            tm.insert(content[i]);
        }
        int siz_tm=tm.size();
        V.push_back({{-1*ck,-1*siz_tm},{-1*follower,username}});
        //cnt++;
        //if(cnt==3)break;
    }
    sort(V.begin(),V.end());
    for(auto i:V){
        cout<<i.second.second<<" "<<i.second.first*-1<<"\n";
    }
    return 0;
}