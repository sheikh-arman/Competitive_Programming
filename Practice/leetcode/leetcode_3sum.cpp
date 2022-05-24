class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        int siz=nums.size();
        for(int i=0; i<siz; i++)
        {
            if(i>0&&nums[i]==nums[i-1])continue;
            int left=i+1,right=siz-1;
            while(left<right)
            {
                int val1=nums[i]+nums[left];
                int val2=nums[right];
                if(val1+val2==0)
                {
                    vector<int>V;
                    V.push_back(nums[i]);
                    V.push_back(nums[left]);
                    V.push_back(nums[right]);
                    if((int)ans.size()>0)
                    {
                        int ss=ans.size();
                        vector<int>V2=ans[ss-1];

                        if(V2!=V)
                        {
                            ans.push_back(V);
                        }
                    }
                    else
                    {
                        ans.push_back(V);
                    }
                    left++;right--;
                }
                else
                {
                    if(val1+val2>0)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};
