#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector< pair <string, string> >vect;
    string a,b;
    while(n--){
    cin>>a>>b;
    b+=';';
    vect.push_back(make_pair(a,b));
    }
    while(m--){
        cin>>a>>b;
        for(int i=0;i<vect.size();i++){
            if(b==vect[i].second)
                cout<<a<<" "<<b<<" #"<<vect[i].first<<endl;
        }
    }
    return 0;
}

