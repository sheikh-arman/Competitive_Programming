// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    int mem[40][40];
    int dp(int n,int r){
        if(r>n){
           return 0;
        }
        if(r==n||r==0){
           return 1;
        }
        if(mem[n][r]!=-1){
            return mem[n][r];
        }
        return mem[n][r]=dp(n-1,r)+dp(n-1,r-1);
    }
    vector<int> getRow(int rowIndex) {
        vector<int>V;
        for(int i=0;i<35;i++){
            for(int j=0;j<35;j++){
                mem[i][j]=-1;
            }
        }
        for(int i=1;i<=rowIndex+1;i++){
            V.push_back(dp(rowIndex,i-1));
        }
        return V;
    }
};