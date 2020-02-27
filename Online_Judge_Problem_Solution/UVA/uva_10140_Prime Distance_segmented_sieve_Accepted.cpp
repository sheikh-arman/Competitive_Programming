/*** Bismillahir Rahmanir Rahim ***/

#include<bits/stdc++.h>
using namespace std;

/*** Team_Excalibur ***/
/*** Sk arman Hossain ***/

#define     ins              insert
#define     pub              push_back
#define     pob              pop_back
#define     ll               long long int
#define     ull              unsigned long long int
#define     max3(a,b,c)      max(a,max(b,c))
#define     max4(a,b,c,d)    max(max3(a,b,c),d)
#define     min3(a,b,c)      min(a,min(b,c))
#define     min4(a,b,c,d)    min(a,min3(b,c,d))
#define     MOD              1000000007
#define     MAX              1000000000000014
#define     MIN              -100000000000014
#define     INF              1e5 //1e5==10000
#define     EPS              1e-8
#define     PI               (2*acos(0.0))
#define     all(v)           v.begin(),v.end()
#define     mii              map<int,int>
#define     mll              map<ll,ll>
#define     pii              pair<int,int>
#define     pll              pair<ll,ll>
#define     mpii             map<pii,int>
#define     mpll             map<pll,ll>
#define     vi               vector<int>
#define     vl               vector<ll>
#define     vpi              vector<pii>
#define     vpl              vector<pll>
#define     si               set<int>
#define     sl               set<ll>
#define     siit             set<int>::iterator
#define     slit             set<long long>::iterator
#define     msi              multiset<int>
#define     msl              multiset<ll>
#define     msiit            multiset<int>::iterator
#define     mslit            multiset<long long>::iterator
#define     frsit(it,myset)  for (it=myset.begin(); it!=myset.end(); ++it)
///         use *it as the loop variable for set iteration..
#define     fast             ios_base::sync_with_stdio(0);cin.tie(0)
#define     F                first
#define     S                second
#define     mem(a,v)         memset(a,v,sizeof(a))
#define     mp               make_pair
#define     sq(x)           (x)*(x)
#define     dis(x1, y1, x2, y2) sqrt(sq(x1-x2)+sq(y1-y2))
#define     foi              freopen("input.txt","r",stdin);
#define     foo              freopen("output.txt","w",stdout);
#define     check            printf("check")
#define     nl               printf("\n")
#define     left(x)          ((x) << 1)
#define     right(x)         (((x) << 1) + 1)
#define     dbg(x)           cout << #x << " = " << x << endl
#define     gcd(a,b)         __gcd(a,b)
#define     lcm(a,b)         (a/gcd(a,b))*b
#define     fri(i,n)         for(int i=0;i<n;i++)
#define     frl(i,n)         for(ll i=0;i<n;i++)
#define     frir(i,n)        for(int i=n-1;i>=0;i--)
#define     frlr(i,n)        for(ll i=n-1;i>=0;i--)
#define     wh(n)            while(n--)
#define     fxd(i,x)         std::fixed <<std::setprecision(i)<<(x)
#define     onesi(n)         __builtin_popcount(n)
#define     onesll(n)        __builtin_popcountll(n)

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
///in 10^7, there are 22 pprimes and in 10^20, there are one more.
ll pprime[] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991, 1111111111111111111};

#define bug printf("debug\n");
#define br puts("");

template<typename t>
t abs(t a)
{
    if(a>=0)
        return a;
    return -a;
}
template<typename t>
t dgtsum(t n)
{
    return n? dgtsum(n/10) + n%10 : 0;
}

/*** End Of Template ***/

/*** Start of Math Functions ***/

///sieve method to generate primes

bitset<1000010>bs;
vl primes;
void sieve(ll ub)
{
    ll ss=ub+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2; i<=ss; i++)
    {
        if(bs[i])
        {
            for(ll j=i*i; j<=ss; j+=i)
            {
                bs[j]=0;
            }
            primes.pub(i);
        }
    }
    //cout<<primes[primes.size()-1]<<endl;
}

bitset<1000010>segp;
vl segprimes;
void segmentsieve(ll l, ll u)
{
    segp.set();
    //printf("%lld di\n",u-l);
    if(l==1)segp[0]=0;
    ll sq=sqrt(u)+1;
    ll len=primes.size();
    for(ll i=0; i<len&&primes[i]<=sq; i++)
    {
        ll p=primes[i];
        ll base=(l/p)*p;
        if(base<l)base+=p;
        for(ll j=base; j<=u; j+=p)
        {
            segp[j-l]=0;
        }
        if(base==p)segp[base-l]=1;
    }
    for(ll i=0; i<=u-l; i++)
    {
        if(segp[i])
        {
            //printf("%lld %lld se\n",i,i+l);
            segprimes.pub(i+l);
        }
    }
}
ll posmin,posmax;
void segdiff()
{
    ll ma=0,mi=999999999999;
    ll l=segprimes.size();
    for(ll i=l-1; i>0; i--)
    {
        ll dif=segprimes[i]-segprimes[i-1];
        if(dif<=mi){
            mi=dif;
            posmin=i;
        }
        if(dif>=ma){
            ma=dif;
            posmax=i;
        }
    }
}
int main()
{
    //fast;
    sieve(46345);
    ll l, u;
    while(scanf("%lld %lld",&l,&u)!=EOF)
    {
        segprimes.clear();
        posmin=-1;
        segmentsieve(l,u);
        segdiff();
        if(posmin!=-1)
        {
            cout<<segprimes[posmin-1]<<","<<segprimes[posmin]<<" are closest, "<<segprimes[posmax-1]<<","<<segprimes[posmax]<<" are most distant."<<endl;
        }
        else
        {
            cout<<"There are no adjacent primes."<<endl;
        }
    }
    return 0;
}

/*** Alhamdulillah ***/
/*** Team_Excalibur ***/
/*** University of Barisal, Bangladesh ***/
