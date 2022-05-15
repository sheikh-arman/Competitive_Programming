class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int pivot=0;
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>=nums[0])
            {
                left=mid+1;
            }
            else
            {
                pivot=mid;
                right=mid-1;
            }
        }
        return nums[pivot];
    }
};
