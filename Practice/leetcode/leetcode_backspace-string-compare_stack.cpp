class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char>st;
        stack<char>tt;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        for(int i=0;t[i]!='\0';i++){
            if(t[i]=='#'){
                if(!tt.empty()){
                    tt.pop();
                }
            }
            else{
                tt.push(t[i]);
            }
        }
        if(st==tt)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
