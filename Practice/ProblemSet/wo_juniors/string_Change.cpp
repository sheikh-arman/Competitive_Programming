/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll t=1;
    for(ll i=0; i<t; i++)
    {
        string s;
        cin>>s;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='z'){
                s[i]='a';
            }
        }
        cout<<s<<"\n";
    }

    return 0;
}



