#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
int main()
{
    fast;
    int n;
    cin>>n;
    int len=0;
    vector<pair<char,char>>V;
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
            cin>>ch2>>ch2;
            V.PB({ch,ch2});
        }
    }
    string s;
    for(int i=0;i<len;i++){
        s+='#';
    }
    int cnt=0;
    for(int i=n-1;i>=0&&len>0;i--){
        if(value[i]==1){
            if(cnt>0)cnt--;
            else{
                int val=rep(V[i].first-'a');
            }
        }
        else if(value[i]==2){
            cnt++;
        }
        else{

        }
    }

    return 0;
}





