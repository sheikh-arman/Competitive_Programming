// https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value

class Solution {
public:
    bool digitCount(string num) {
        int ck=1;
        int siz=num.size();
        for(int i=0;i<siz;i++){
            char ch=(char)(i+'0');
            int cnt=0;
            for(int j=0;j<siz;j++){
                if(num[j]==ch)cnt++;
            }
            if(num[i]-'0'!=cnt){
                ck=0;break;
            }
        }
        return ck;
    }
};