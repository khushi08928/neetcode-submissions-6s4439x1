class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size();
        string operand;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                operand=tokens[i];
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(operand=="+"){
                    int result=a+b;
                    st.push(result);
                }
                else if(operand=="-"){
                    int result=b-a;
                    st.push(result);
                }
                else if(operand=="*"){
                    int result=a*b;
                    st.push(result);
                }
                else if(operand=="/"){
                    int result=b/a;
                    st.push(result);
                }
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
