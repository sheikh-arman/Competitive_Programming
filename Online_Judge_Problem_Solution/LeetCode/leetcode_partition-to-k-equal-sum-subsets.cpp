class Solution
{

public:
    typedef long long int ll;
#define N 17
    ll dp[N+2][(1<<N)+10];
    ll n,kk,sum=0;
    vector<ll>V;
    ll Set(ll m,ll pos)
    {
        return m|1<<pos;
    }
    bool view(ll m,ll pos)
    {
        return m&(1<<pos);
    }
    bool sub_sum(ll i,ll val,ll bitmask)
    {
        if(i>=n)
        {
            //cout<<val<<" "<<bitmask<<" test\n";
//        for(ll k=0;k<n;k++){
//            cout<<view(bitmask,k)<< " ";
//        }
            //cout<<" t\n";
            if(bitmask==pow(2,n)-1)
            {
                return dp[i][bitmask]=1;
            }
            else if(val==sum/kk)
            {
                dp[i][bitmask]=sub_sum(0,0,bitmask);
                return dp[i][bitmask];
            }
            else
                return dp[i][bitmask]=0;
        }
        if(dp[i][bitmask]!=-1)
        {
            return dp[i][bitmask];
        }
        ll ans1=0,ans2=0;
        ans1=sub_sum(i+1,val,bitmask);
        if(V[i]+val<=sum/kk)
        {
            if(view(bitmask,i)==0)
            {
                ans2=sub_sum(i+1,val+V[i],Set(bitmask,i));
            }
        }
        dp[i][bitmask]=ans1|ans2;
        return dp[i][bitmask];
    }

    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        n=nums.size();
        kk=(ll)k;
        sum=0;
        V.clear();
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=(1<<N); j++)
            {
                dp[i][j]=-1;
            }
        }
        for(ll i=0; i<n; i++)
        {
            V.push_back(nums[i]);
            sum+=nums[i];
        }
        if(sum%kk!=0)
        {
            return 0;
        }
        bool ans=sub_sum(0,0,0);
        return ans;
    }
};