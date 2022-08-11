// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n==0&&m==0){
            return 1;
        }
        bool ck=0;
        int left=0;
        for(int i=0;i<m;i++){
            if(left>=n){
                ck=1;break;
            }
            if(s[left]==t[i]){
                left++;
            }
            if(left>=n){
                ck=1;break;
            }
        }
        return ck;
    }
};