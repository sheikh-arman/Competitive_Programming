// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int siz=s.size();
        int ans=0;int left=0,right=0;
        int ar[30];
        for(int i=0;i<27;i++)ar[i]=0;
        //cout<<siz<<" x\n";
        set<char>st;
        while(right<siz){
            if(st.find(s[right])==st.end()){
                st.insert(s[right]);right++;
                ans=max(ans,(int)st.size());
            }
            else{
                while(st.find(s[right])!=st.end()){
                    st.erase(st.find(s[left]));left++;
                }
            }
        }
        return ans;
    }
};