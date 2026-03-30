class Solution {
private:
    void validparanthesis(int open,int close,int n,string &s,vector<string>& ans){
        int len=s.length();
        if(len==2*n){
            ans.push_back({s});
            return;
        }
        if(open<n){
            s.push_back('(');
            validparanthesis(open+1,close,n,s,ans);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            validparanthesis(open,close+1,n,s,ans);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        validparanthesis(0,0,n,s,ans);
        return ans;
    }
};
