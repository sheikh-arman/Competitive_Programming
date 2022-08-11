// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        int n=s.size();
        bool ck=1;
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()){
                    ck=0;break;
                }
                if(s[i]==')'&&stk.top()=='('){
                    stk.pop();
                }
                else if(s[i]=='}'&&stk.top()=='{'){
                    stk.pop();
                }
                else if(s[i]==']'&&stk.top()=='['){
                    stk.pop();
                }
                else{
                    ck=0;break;
                }
            }
        }
        if(!stk.empty())ck=0;
        return ck;
    }
};