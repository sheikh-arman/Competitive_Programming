// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int ans=0,pos=0;
        for(int i=0;i<n;i++){
            int tm=1;
            int left=i-1,right=i+1;
            while((left>=0&&right<n)&&s[left]==s[right]){
                tm+=2;
                left--;right++;
            }
            if(tm>ans){
                ans=tm;pos=i;
            }
            if(i>0&&s[i-1]==s[i]){
                tm=2;
                left=i-2;right=i+1;
                 while(left>=0&&right<n&&s[left]==s[right]){
                   tm+=2;
                    left--;right++;
                 }
                if(ans<tm){
                    ans=tm;pos=i;
                }
            }
        }
        string res;
        if(ans%2==0){
            int start=pos-(ans/2);
            for(int i=start;i<start+ans;i++)res+=s[i];
        }
        else{
            int start=(pos-(ans/2))+1;
            for(int i=start;i<start+ans;i++)res+=s[i];
        }
        return res;
    }
};