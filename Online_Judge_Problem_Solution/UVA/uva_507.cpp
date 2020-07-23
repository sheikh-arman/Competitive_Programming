/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
//    /freopen("1input.txt","r",stdin);
    // freopen("1output.txt","w",stdout);
    ll tcase=1;
    while(scanf("%lld",&tcase)!=EOF)
    {
        //scanf("%lld",&tcase);
        for(ll test=1; test<=tcase; test++)
        {
            ll n,sum=0,l=-1,r=-1,x=1,ma=0;
            scanf("%lld",&n);
            for(ll i=1; i<n; i++)
            {
                ll a;
                scanf("%lld",&a);
                if(sum+a<0)
                {
                    sum=0;
                    x=i+1;
                }
                else
                {
                    sum+=a;
                    if(sum>ma)
                    {
                        ma=sum;
                        l=x;
                        r=i;
                    }
                    else if(sum==ma)
                    {
                        if((i-x)>(r-l))
                        {
                            l=x;
                            r=i;
                        }
                    }
                }
            }
            if(l==-1)
            {
                printf("Route %lld has no nice parts\n",test);
            }
            else
            {
                printf("The nicest part of route %lld is between stops %lld and %lld\n",test,l,r+1);
            }

        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

