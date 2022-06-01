/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
vector<ll>V;
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll a1,a2,a3,a4,a5,a6,a7,a8,a9;
    while(scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9)!=EOF)
    {
        char ch[5];
        ll ans=0,tm;
        tm=a2+a3+a4+a5+a7+a9;
        ans=tm;
        ch[0]='B';ch[1]='C';ch[2]='G';
        tm=a2+a3+a4+a6+a7+a8;
        if(tm<ans){
            ans=tm;
            ch[0]='B';ch[1]='G';ch[2]='C';
        }
        tm=a1+a2+a5+a6+a7+a9;
        if(tm<ans){
            ans=tm;
            ch[0]='C';ch[1]='B';ch[2]='G';
        }
        tm=a2+a3+a4+a6+a8+a9;
        if(tm<ans){
            ans=tm;
            ch[0]='C';ch[1]='G';ch[2]='B';
        }
        tm=a1+a3+a5+a6+a7+a8;
        if(tm<ans){
            ans=tm;
            ch[0]='G';ch[1]='B';ch[2]='C';
        }
        tm=a1+a3+a4+a5+a8+a9;
        if(tm<ans){
            ans=tm;
            ch[0]='G';ch[1]='C';ch[2]='B';
        }
        printf("%s %lld\n",ch,ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
