// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int siz=s.size();
        int ans=0;int left=0,right=0;
        int ar[30];
        for(int i=0;i<27;i++)ar[i]=0;
        while(right<siz){
            int val=s[right]-'a';
            if(ar[val]==0){
                ar[val]=1;right++;
                ans=max(ans,right-left);
            }
            else{
                while(ar[val]==1){
                    ar[s[left]-'a']=0;left++;
                }
            }
        }
        return ans;
    }
};