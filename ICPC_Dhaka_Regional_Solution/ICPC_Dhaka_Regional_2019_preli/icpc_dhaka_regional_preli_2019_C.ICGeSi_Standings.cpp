#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>V[55];
int main()
{
    //freopen("1input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll tcase=1;

    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<=n; i++)V[i].clear();
        for(ll i=1; i<=n; i++)
        {
            ll id,s,tp,m;
            cin>>id>>s>>tp>>m;
            V[id].push_back(s);
            V[id].push_back(tp);
            V[id].push_back(m);
            for(ll j=0; j<m; j++)
            {
                ll a;
                cin>>a;
                V[id].push_back(a);
            }
        }
        n-=1;
        ll a;
        cin>>a;
        ll ck=0;
        ll sol=V[a][0]+V[a][2];
        ll penalty=V[a][1];
        ll siz=V[a].size();
        for(ll i=3; i<siz; i++)penalty+=V[a][i];
        for(ll i=0; i<n; i++)
        {
            cin>>a;
            ll new_sol=V[a][0];
            ll new_penalty=V[a][1];
            //cout<<sol<<" "<<penalty<<" "<<new_sol<<" "<<new_penalty<<" \n";
            if(new_sol>sol)
            {
                ck=1;
                //break;
            }
            if(new_sol==sol)
            {
                if(penalty>new_penalty)
                {
                    ck=1;
                    //break;
                }
            }
            siz=V[a].size();
            for(ll j=3; j<siz; j++)
            {
                if(new_sol<=sol)
                {
                    if(new_sol<sol)
                    {
                        new_sol+=1;
                        if(new_sol==sol)
                        {
                            if(penalty<=new_penalty+V[a][j])
                            {
                                new_penalty+=V[a][j];
                            }
                            else
                            {
                                new_sol-=1;
                                break;
                            }
                        }
                        else
                        {
                            new_penalty+=V[a][j];
                        }
                    }
                    else
                    {
                        //cout<<"hi\n";
                        if(penalty>new_penalty)
                        {
                            ck=1;
                           // break;
                        }
                    }

                }
                else
                {
                    ck=1;
                   // break;
                }
            }
            //cout<<sol<<" "<<penalty<<" \n";
            penalty=new_penalty;
            sol=new_sol;

        }
        //cout<<sol<<" "<<penalty<<" \n";
        if(ck==0)
        {
            cout<<"Case "<<test<<": We respect our judges :)\n";
        }
        else
        {
            cout<<"Case "<<test<<": Say no to rumour >:\n";
        }
    }
    return 0;
}
