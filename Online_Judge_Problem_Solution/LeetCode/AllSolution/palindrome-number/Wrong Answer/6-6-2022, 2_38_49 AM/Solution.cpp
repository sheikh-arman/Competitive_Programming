// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        int num=0;
        int pre=x;
        while(x){
            num=(num*10)+x%10;x/=10;
        }
        return num==pre;
    }
};