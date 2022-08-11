// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0,current=0,prev=0;
        stack<char>stk;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='('){
                stk.push(s[i]);
            }
            else{
                if(stk.size()>0){
                    stk.pop();
                    if(stk.empty()){
                        current=prev;
                    }
                    else{
                        current=0;
                    }
                    current+=2;
                    ans=max(current,ans);
                    prev=current;
                }
                else{
                    prev=0;
                    ans=max(current,ans);current=0;
                    while(!stk.empty()){
                        stk.pop();
                    }
                }
            }
        }
        return ans;
    }
};