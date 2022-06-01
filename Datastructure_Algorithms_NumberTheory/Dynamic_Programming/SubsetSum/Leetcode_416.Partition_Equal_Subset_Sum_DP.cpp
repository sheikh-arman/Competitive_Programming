/*
    Sk arman Hossain
    University of Barisal

    Problem: 416. Partition Equal Subset Sum
    Solution : dp
 */

class Solution
{
public:
    typedef long long int ll;
ll dp[20010],sum,n;
vector<ll>V;
bool sub_sum(ll i,ll val)
{
    if(i>=n)
    {
        //cout<<val<<" t\n";
        if(val==sum/2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[val]!=-1)
    {
        return dp[val];
    }
    bool ans=0;
    if(val+V[i]<=sum/2)
    {
        ans=sub_sum(i+1,val+V[i]);
    }
    ans|=sub_sum(i+1,val);
    return dp[val]=ans;
}
    bool canPartition(vector<int>& nums)
    {
        sum=0;
        n=nums.size();
        for(ll i=0; i<n; i++)
        {
            V.push_back(nums[i]);
            sum+=nums[i];
        }
        for(ll j=0; j<=sum/2; j++)
        {
            dp[j]=-1;
        }
        if(sum%2!=0)
        {
            return 0;
        }
        bool ans=sub_sum(0,0);
        //cout<<cnt<<" "<<sum/k<<"\n";
        return ans;
    }
};
