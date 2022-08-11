// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=matrix[0][0],right=matrix[n-1][m-1];
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                int pos=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
                sum+=pos;
            }
            if(sum>=k){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};