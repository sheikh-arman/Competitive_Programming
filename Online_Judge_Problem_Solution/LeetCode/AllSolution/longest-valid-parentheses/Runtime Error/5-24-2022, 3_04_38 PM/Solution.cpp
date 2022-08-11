// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0,current=0,prev=0;
        stack<char>stk;
        vector<int>siz,pos;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='('){
                stk.push(s[i]);
            }
            else{
                if(stk.size()>0){
                    stk.pop();
                    current+=2;
                    siz.push_back(current);
                    pos.push_back(i);
                    if(stk.empty()){
                        current=0;
                    }
                }
            }
        }
        
        int si=siz.size();
        
        int pre=pos[si-1]-siz[si-1];
        ans=siz[si-1];
        current=ans;
        for(int i=si-2;i>=0;i--){
            if(pos[i]>pre){
                continue;
            }
            if(pos[i]==pre){
                current+=siz[i];
                pre=pos[i]-siz[i];
                ans=max(ans,current);
            }
            else{
               pre=pos[i]-siz[i];
                current=siz[i];
                ans=max(ans,current);
            }
        }
        return ans;
    }
};