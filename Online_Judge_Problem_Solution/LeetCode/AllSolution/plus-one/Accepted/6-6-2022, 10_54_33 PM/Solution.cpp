// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int n=digits.size();
        vector<int>V;
        for(int i=n-1;i>=0;i--){
            int number=digits[i];
            number+=carry;carry=0;
            V.push_back(number%10);
            carry=number/10;
        }
        while(carry){
            V.push_back(carry%10);
            carry/=10;
        }
        reverse(V.begin(),V.end());
        return V;
    }
};