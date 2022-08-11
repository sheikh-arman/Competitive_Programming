// https://leetcode.com/problems/partition-equal-subset-sum

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
    ll dp[210][40000],sum=0,n;
    vector<ll>V;
    bool sub_sum(ll i,ll val)
    {
        if(i>=n)
        {
            if(val==sum/2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[i][val]!=-1)
        {
            return dp[i][val];
        }
        bool ans=0;
        if(val+V[i]>=sum/2)
        {
            ans=sub_sum(i+1,val+V[i]);
        }
        ans|=sub_sum(i+1,val);
        return dp[i][val]=ans;
    }
    bool canPartition(vector<int>& nums)
    {
        sum=0;
        n=nums.size();
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=(n*100)/2; j++)
            {
                dp[i][j]=-1;
            }
        }
        for(ll i=0; i<n; i++)
        {
            V.push_back(nums[i]);
            sum+=nums[i];
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
