// https://leetcode.com/problems/strong-password-checker-ii

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int small=0,capital=0,special=0,digit=0;
        int ck=1;
        int n=password.size();
        for(int i=0;i<n;i++){
            if(i>0){
                if(password[i]==password[i-1]){
                    ck=0;
                }
            }
            if(password[i]>='a'&&password[i]<='z'){
                small=1;
            }
            else if(password[i]>='A'&&password[i]<='Z'){
                capital=1;
            }
            else if(password[i]>='0'&&password[i]<='9'){
                digit=1;
            }
            else{
                special=1;
            }
        }
        return (digit&&small&capital&&special&&ck&&n>=8);
    }
};