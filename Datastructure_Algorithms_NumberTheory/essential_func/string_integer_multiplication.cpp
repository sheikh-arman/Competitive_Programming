#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
string product(string s,int num)
{
    reverse(s.begin(),s.end());
    ll str_siz=s.size();
    ll baki=0;
    string temp;
    for(ll j=0; j<str_siz; j++)
    {
        ll val=(s[j]-'0')*num;
        val+=baki;
        temp+=(val%10)+'0';
        val/=10;
        baki=val;
    }
    while(baki)
    {
        temp+=(baki%10)+'0';
        baki/=10;
    }
    s=temp;
    reverse(s.begin(),s.end());
    return s;
}
int main()
{

    int tcase=1050;
    //cin>>tcase;
    string s="1";
    int n;
    ll pre=0;
    for(ll test=1;test<=tcase;test++){

        //cin>>n;
        //cin>>s;
        s=product(s,test);
        ll siz=s.size();
        ll ans=0;
        for(ll i=siz-1;i>=0;i--){
            if(s[i]=='0')ans++;
            else break;
        }
        if(ans>pre){
          cout<<test<<" : "<<ans<<" "<<ans-pre<<" \n";
          pre=ans;
        }

    }
    return 0;
}
