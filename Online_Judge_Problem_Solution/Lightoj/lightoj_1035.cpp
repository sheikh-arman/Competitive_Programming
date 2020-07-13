/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
using namespace std;
vector<int>V;
void seive()
{
    V.push_back(2);
    V.push_back(3);
    V.push_back(5);
    V.push_back(7);
    V.push_back(11);
    V.push_back(13);
    V.push_back(17);
    V.push_back(19);
    V.push_back(23);
}
int prime[110];
void factorize(int n)
{
    int sq=sqrt(n+1);
    for(int i=0; V[i]<=sq; i++)
    {
        while(n%V[i]==0)
        {
            prime[V[i]]++;
            n/=V[i];
        }
    }
    if(n>1)
    {
        prime[n]++;
    }
}
int main()
{
    //freopen("1in.txt","r",stdin);
    //freopen("2out.txt","w",stdout);

    seive();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tcase;
    cin>>tcase;
    for(int test=1; test<=tcase; test++)
    {
        int n;
        cin>>n;
        for(int i=2;i<=100;i++)prime[i]=0;
        for(int i=2;i<=n;i++)factorize(i);
        cout<<"Case "<<test<<": "<<n<<" = ";
        int i=2;
        for(;i<=100;i++){
            if(prime[i]>0){
                cout<<i<<" ("<<prime[i]<<")";
                i++;
                break;
            }
        }
        for(;i<=100;i++){
            if(prime[i]>0){
                cout<<" * "<<i<<" ("<<prime[i]<<")";
            }
        }
        cout<<endl;
    }
    return 0;
}

