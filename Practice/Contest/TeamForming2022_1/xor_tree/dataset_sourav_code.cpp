#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;



#define ll long long int

#define pb push_back

#define mp make_pair

#define all(x) x.begin(),x.end()

#define min_heap priority_queue <ll, vector<ll>, greater<ll> >



template <typename T>

using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;



ll randval(ll beg,ll len)
{

    unsigned seed1 = chrono::system_clock::now().time_since_epoch().count();

    mt19937 generator(seed1);

    uniform_int_distribution<int> distribution(beg, len);



    return distribution(generator);

}



mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rep[100010];
ll Find(ll n)
{
    return (rep[n]==n?n:rep[n]=Find(rep[n]));
}

ll test= 10;

void generate_case()
{

    ll n=100000,ran=10,ran2=120,ran3=130;
    ran*=(test+40);
    ran2*=(test+40);
    ran3*=(test+40);
    for(ll i=0; i<=n; i++)
    {
        rep[i]=i;
    }
    cout<<n<<"\n";
    for(ll i=0; i<n; i++)
    {
        ll val=rand()+ran;
        val%=1000000000;
        cout<<val<<" ";
        ran*=1927;
        ran%=10000000;
    }
    cout<<"\n";
    ll cnt=1;
    while(cnt<n)
    {
        ll u=rand()+ran2;
        ll v=rand()+ran3;
        u%=n+1;
        v%=n+1;
        if(u==0)u++;
        if(v==0)v++;
        if(u!=v)
        {
            if(Find(u)!=Find(v))
            {
                cnt++;
                cout<<u<<" "<<v<<"\n";
                rep[Find(u)]=Find(v);
            }
        }
        ran2*=1917;
        ran3*=1927;
        ran2%=100000000;
        ran3%=100000000;
    }
}

int main()

{
    //string s2="C:/AllFile/code/Competitive_Programming/Competitive_Programming/Practice/Contest/TeamForming2022_1/data/input/input11.txt";
    //cout<<s2.size();
    char s[122] = "C:/AllFile/code/Competitive_Programming/Competitive_Programming/Practice/Contest/TeamForming2022_1/data/input/input31.txt";
    //char s[66]="input/input13.txt";
   // cout<<s<<" "<<s[116]<<" x\n";
    while(test--)
    {

        freopen(s,"w",stdout);
        generate_case();
        fclose(stdout);

        if(s[116]=='9')
        {
            s[115]++;
            s[116]='0';
        }
        else s[116]++;
        //if(test==0)break;
    }



    return 0;

}
