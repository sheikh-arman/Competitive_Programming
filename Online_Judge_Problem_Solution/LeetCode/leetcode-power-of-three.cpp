// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>1){
            if(n%3)return 0;
            n/=3;
        }
        return (n>0);
    }
};