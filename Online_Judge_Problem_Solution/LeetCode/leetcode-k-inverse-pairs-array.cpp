// https://leetcode.com/problems/k-inverse-pairs-array

class Solution {
public:
    int kInversePairs(int n, int k) {
        int M = 1000000007;
        int dp[1001] = {0};
        int tmp[1001];
        for (int i = 1; i <= n; i++) {
            tmp[0] = 1;
            for (int j = 1; j <= k; j++) {
                int val = (dp[j] + M - ((j-i) >= 0 ? dp[j-i] : 0)) % M;
                tmp[j] = (tmp[j-1] + val) % M;
            }
            swap(dp, tmp);
        }
        return ((dp[k] + M - (k > 0 ? dp[k-1] : 0)) % M);
    }
};