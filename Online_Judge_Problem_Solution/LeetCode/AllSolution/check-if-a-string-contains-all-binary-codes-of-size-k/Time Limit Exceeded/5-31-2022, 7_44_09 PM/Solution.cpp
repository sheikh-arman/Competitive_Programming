// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<int,int>mp;
        int n=s.size();
        for(int i=0;i<=n-k;i++){
            int num=0,cnt=0;
            for(int j=i+k-1;j>=i;j--){
                if(s[j]=='1'){
                    num+=pow(2,cnt);
                }
                cnt++;
            }
            cout<<i<<" "<<num<<" x\n";
            mp[num]=0;
        }
        int ma=pow(2,k);
        int ck=1;
        for(int i=0;i<ma;i++){
            if(mp.count(i)==0){
                cout<<i<<""; 
                ck=0;break;
            }
        }
        return ck;
    }
};