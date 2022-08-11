// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n>0){
            for(int i=(n+m-1),j=m-1;j>=0;i--,j--){
                nums1[i]=nums1[j];
            }
            int empty=(n+m)-m;
            int left=empty,right=0;
            for(int i=0;i<(n+m);i++){
                if(left<n+m&&right<n){
                    if(nums1[left]<=nums2[right]){
                        nums1[i]=nums1[left++];
                    }
                    else{
                        nums1[i]=nums2[right++];
                    }
                }
                else if(left<(n+m)){
                    nums1[i]=nums1[left++];
                }
               else if(right<n){
                   nums1[i]=nums2[right++];
               }
            }
        }
    }
};