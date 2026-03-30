class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>result;
        for(string s:strs){
            int count[26]={0};
            for(int i=0;i<s.length();i++){
                count[s[i]-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+="$";
                key+=to_string(count[i]);
           }
           mpp[key].push_back(s);
        }
        for(auto it:mpp){
            result.push_back(it.second);
        }
        return result;
    }
};
