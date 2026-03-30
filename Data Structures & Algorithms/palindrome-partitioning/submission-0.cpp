class Solution {
private:
    bool ispalindrome(string part){
        string reversepart=part;
        reverse(reversepart.begin(),reversepart.end());
        return reversepart==part;
    }
    void getallpalindrome(string s, vector<string>& partitions,vector<vector<string>>& ans){
        int n=s.length();
        if(n==0){
            ans.push_back({partitions});
            return;
        }
        for(int i=0;i<n;i++){
            string part=s.substr(0,i+1);
            if(ispalindrome(part)){
                partitions.push_back(part);
                getallpalindrome(s.substr(i+1),partitions,ans);
                //backtrak step
                partitions.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partitions;
        getallpalindrome(s,partitions,ans);
        return ans;
    }
};
