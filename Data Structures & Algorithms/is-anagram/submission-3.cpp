class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
        for(auto& ch:s){
            mpp1[ch]++;
        }
        for(auto& ch:t){
            mpp2[ch]++;
        }
        for(auto& it:mpp1){
            if(mpp2.find(it.first)==mpp2.end()){
                return false;
            }else{
                if(it.second==mpp2[it.first]){
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
