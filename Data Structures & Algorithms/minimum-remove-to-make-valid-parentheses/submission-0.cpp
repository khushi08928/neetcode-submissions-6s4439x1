class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_set<int>removeIdx;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            } 
            else if(s[i]==')') {
                if(!st.empty()) {
                    st.pop(); 
                }else{
                    removeIdx.insert(i); 
                }
            }
        }
        while(!st.empty()) {
            removeIdx.insert(st.top());
            st.pop();
        }
        string result="";
        for(int i=0;i<s.size();i++) {
            if(removeIdx.count(i)==0) {
                result+=s[i];
            }
        }
        return result;
    }
};