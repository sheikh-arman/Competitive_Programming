// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int>left,right;
        int sum=0;
        for(int i:nums){
            sum+=i;
            left.push_back(sum);
        }
        int n=nums.size();
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            right.push_back(sum);
        }
        int ans=INT_MAX;
        int k=x;
        for(int i=0;i<n;i++){
            if(left[i]>k)break;
            if(k==left[i]){
                ans=min(i+1,ans);break;
            }
            int pos=lower_bound(right.begin(),right.end(),k-left[i])-right.begin();
            if(pos<n&&right[pos]==k-left[i]){ 
                if(i+pos+2<=n)
                ans=min(ans,pos+i+2);
            }
        }
        for(int i=0;i<n;i++){
            if(right[i]>k)break;
            if(k==right[i]){
                ans=min(i+1,ans);break;
            }
            int pos=lower_bound(left.begin(),left.end(),k-left[i])-left.begin();
            if(pos<n&&left[pos]==k-right[i]){
                if(i+pos+2<=n)
                ans=min(ans,pos+i+2);
            }
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};