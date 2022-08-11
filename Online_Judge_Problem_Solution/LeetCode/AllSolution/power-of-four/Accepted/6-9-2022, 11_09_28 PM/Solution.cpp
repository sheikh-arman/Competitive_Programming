// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
         while(n>1){
            if(n%4)return 0;
            n/=4;
        }
        return (n>0);
    }
};