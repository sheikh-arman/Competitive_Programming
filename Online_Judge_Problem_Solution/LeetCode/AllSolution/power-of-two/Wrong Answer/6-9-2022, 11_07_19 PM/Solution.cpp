// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>1){
            if(n%2)return 0;
            n/=2;
        }
        return (n!=0);
    }
};