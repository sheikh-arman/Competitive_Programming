// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=k;
        int n=num.size();
        vector<int>V;
        for(int i=n-1;i>=0;i--){
            int number=num[i];
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