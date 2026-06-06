class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        string op;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                op=tokens[i];
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(op=="+"){
                    int ans=a+b;
                    st.push(ans);
                }else if(op=="-"){
                    int ans=b-a;
                    st.push(ans);
                }else if(op=="*"){
                    int ans=a*b;
                    st.push(ans);
                }else if(op=="/"){
                    int ans=b/a;
                    st.push(ans);
                }
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
