class Solution {
public:
    int maximum69Number (int num) {
        int new_num=0;
        while(num){
            new_num=(10*new_num)+(num%10);
            num/=10;
        }
        int ck=1;
        while(new_num){
            int mod=new_num%10;
            new_num/=10;
            if(mod==6&&ck){
                mod=9;
                ck=0;
            }
            num=(num*10)+mod;
        }
        return num;
    }
};
