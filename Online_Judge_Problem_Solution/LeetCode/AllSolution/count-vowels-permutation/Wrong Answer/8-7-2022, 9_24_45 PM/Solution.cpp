// https://leetcode.com/problems/count-vowels-permutation

typedef long long int ll;
class Solution {
public:
    ll mem[20010][7];
    ll mod=1e9+7;
    ll num;
    ll dp(int i, int cnt){
        if(i>=num){
            return 1;
        }
        if(mem[i][cnt]!=-1){
            return mem[i][cnt];
        }
        ll ans=0;
        if(cnt==5){
            for(int j=0;j<5;j++){
                 ans+=dp(i+1,j);
            }
        }
        else{
            if(cnt==0){
                ans+=dp(i+1,1);
            }
            if(cnt==1){
                ans+=dp(i+1,0);
                if(ans>=mod)ans%=mod;
                ans+=dp(i+1,2);
            }
            if(cnt==2){
                for(int j=0;j<5;j++){
                    if(i!=j)
                    ans+=dp(i+1,j);
                    if(ans>=mod)ans%=mod;
                }
                
            }
            if(cnt==3){
                ans+=dp(i+1,2);
                if(ans>=mod)ans%=mod;
                ans+=dp(i+1,4);
            }
            if(cnt==4){
                ans+=dp(i+1,0);
            }
        }
        if(ans>=mod)ans%=mod;
        return mem[i][cnt]=ans;
        
    }
    int countVowelPermutation(int n) {
        num=n;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=5;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(0,5);
        return ans;
    }
};