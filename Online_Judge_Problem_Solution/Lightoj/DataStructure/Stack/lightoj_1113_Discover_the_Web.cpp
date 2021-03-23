#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    //freopen("1input.txt","r",stdin);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string s;
        deque<string>dk;
        dk.push_back("http://www.lightoj.com/");
        ll cnt=0;
        cout<<"Case "<<test<<":\n";
        ll ck=0;
        while(1)
        {
            if(ck==1)
            {
                break;
            }
            cin>>s;
            if(s=="QUIT")
            {
                ck=1;
                break;
            }
            else if(s=="BACK")
            {
                cnt--;
                //cout<<cnt<<" x\n";
                if(cnt>=0)
                {
                    cout<<dk[cnt]<<"\n";
                }
                else
                {
                    cout<<"Ignored\n";
                    cnt=0;
                }
            }
            else if(s=="FORWARD")
            {
                cnt++;
                ll siz=dk.size();
                if(cnt>=siz)
                {
                    cnt=siz-1;
                    cout<<"Ignored\n";
                }
                else
                {
                    cout<<dk[cnt]<<"\n";
                }
            }
            else
            {
                string link;
                cin>>link;
                ll siz=dk.size();
                while((siz-1)>cnt)
                {
                    dk.pop_back();siz--;
                }
                dk.push_back(link);
                cnt++;
                cout<<link<<"\n";
            }
        }
    }
    return 0;
}

