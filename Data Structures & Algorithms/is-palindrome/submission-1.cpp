class Solution {
private:
    string reverse(string s){
        string ans="";
        for(int i=s.length()-1;i>=0;i--){
            if(!isalnum(s[i])){
                continue;
            }else{
                ans+=tolower(s[i]);
            }
        }
        return ans;
    }
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string st="";
        for(int i=0;i<n;i++){
            if(!isalnum(s[i])){
                continue;
            }else{
                st+=tolower(s[i]);
            }
        }
        string revrsest=reverse(s);
        if(revrsest==st){
            return true;
        }
        return false;
    }
};
