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

ll test= 10;
ll ran=1674,ran2=14424,ran3=2651;
ll N=1e5;
void generate_case()
{
    ll n=N;
    cout<<n<<"\n";
    for(ll i=1; i<=n; i++)
    {
        ll tm=rand()+ran;
        tm%=(N+1);
        cout<<tm<<" ";
        ran*=331;
        ran%=103107;
    }
    cout<<"\n";
    cout<<n<<"\n";
    for(ll i=0; i<n; i++)
    {
        if(i%2==0)
        {
            cout<<"2 ";
            ll tm=rand()+ran2;
            ll tm2=rand()+ran3;
            tm%=(N+1);
            if(tm==0)tm++;
            tm2%=(N+1);
            cout<<tm<<" "<<tm2<<"\n";
            ran2*=323;
            ran2%=1247677;
            ran3*=333;
            ran3%=1437817;
        }
        else
        {
            cout<<"1 ";
            ll tm=rand()+ran2;
            tm%=(N+1);
            cout<<tm<<"\n";
            ran2*=381;
            ran2%=1121677;
        }

    }

}

int main()

{
    //string s2="C:/AllFile/code/Competitive_Programming/Competitive_Programming/Practice/Contest/TeamForming2022_1/data/input/input11.txt";
    //cout<<s2.size();
    char s[122] = "C:/AllFile/code/Competitive_Programming/Competitive_Programming/Practice/Contest/TeamForming2022_1/data/input/input21.txt";
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
