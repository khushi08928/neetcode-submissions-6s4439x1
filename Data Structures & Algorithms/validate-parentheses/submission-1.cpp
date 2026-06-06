class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char>st;
        int i=0;
        while(i<n){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
                i++;
            }else{
                if(st.empty()) return false;
                if(s[i]==')' && st.top()=='('){
                    st.pop();
                    i++;
                }else if(s[i]==']' && st.top()=='['){
                    st.pop();
                    i++;
                }else if(s[i]=='}' && st.top()=='{'){
                    st.pop();
                    i++;
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
