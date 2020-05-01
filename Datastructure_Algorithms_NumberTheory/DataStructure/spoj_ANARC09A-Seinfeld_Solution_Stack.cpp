/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    string s;
    while(cin>>s)
    {
        if(s[0]=='-')
        {
            return 0;
        }
        stack<char>stk;
        ll cnt=0;
        for(ll i=0; s[i]!='\0'; i++)
        {
            if(s[i]=='}')
            {
                if(!stk.empty())
                {
                    if(stk.top()=='{')
                        stk.pop();
                    else stk.push(s[i]);
                }
                else
                {
                    stk.push(s[i]);
                }
            }
            else
            {
                while(!stk.empty())
                {
                    if(stk.top()=='{')break;
                    stk.pop();
                    cnt++;
                }
                stk.push(s[i]);
            }
        }
        ll ans=cnt/2;
        cnt%=2;
        ll tm=stk.size();
        ans+=tm/2;
        tm%=2;
        ans+=(cnt+tm);
        cout<<tcase++<<". ";
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
