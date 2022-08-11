// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans=false;
        int siz=matrix.size();
        int left=0,right=siz-1,pos=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[mid][0]>target){
                right=mid-1;
            }
            else{
                pos=mid;
                left=mid+1;
            }
        }
        left=0;right=matrix[pos].size();
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[pos][mid]==target){
                ans=true;break;
            }
            if(matrix[pos][mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};