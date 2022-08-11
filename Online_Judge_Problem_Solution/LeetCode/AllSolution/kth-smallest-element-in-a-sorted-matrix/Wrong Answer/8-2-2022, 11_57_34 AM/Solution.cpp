// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=k/m-(k%m==0);
        k=k%m;
        if(k==0)k=m;
        return matrix[row][k-1];
    }
};