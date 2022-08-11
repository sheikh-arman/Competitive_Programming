// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        vector<int>V;
        while(x){
            V.push_back(x%10);x/=10;
        }
        int left=0,right=V.size()-1;
        while(left<right){
            if(V[left]!=V[right])return false;
            left++;right--;
        }
        return true;
    }
};