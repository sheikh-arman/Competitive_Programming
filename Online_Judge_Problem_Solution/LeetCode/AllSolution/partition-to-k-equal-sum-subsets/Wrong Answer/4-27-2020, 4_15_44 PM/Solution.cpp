// https://leetcode.com/problems/partition-to-k-equal-sum-subsets


class Solution
{

public:
    typedef long long int ll;
    ll cnt;
    ll n,sum=0,c,bit;
    vector<ll>V;
    ll Set(ll n,ll pos)
    {
        return n|1<<pos;
    }
    bool view(ll n,ll pos)
    {
        return n&(1<<pos);
    }
    void sub_sum(ll i,ll val,ll bitmask,ll kk)
    {
        if(i>=n)
        {
            if(val==sum/kk)
            {

                cnt++;
                bit=bit|bitmask;
            }
            return;
        }
        sub_sum(i+1,val,bitmask,kk);
        if(val+V[i]<=sum/kk)
            sub_sum(i+1,val+V[i],bitmask=Set(bitmask,i),kk);
    }

    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        n=nums.size();
        ll kk=(ll)k;
        sum=bit=0;
        V.clear();
        for(ll i=0; i<n; i++)
        {
            V.push_back(nums[i]);
            sum+=nums[i];
        }
        sort(V.begin(),V.end());
        if(sum%kk!=0)
        {
            return 0;
        }
        cnt=0;
        sub_sum(0,0,0,kk);
        if(cnt>=kk&&(pow(2,n)-1)==bit)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
};

