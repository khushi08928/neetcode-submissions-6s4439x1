class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int len=0;
        int n=s.length();
        unordered_set<char>subStr;
        for(int right=0;right<n;right++){
            while(subStr.find(s[right])!=subStr.end() && (left<n)){
                subStr.erase(s[left]);
                left++;
                len=max(len,right-left+1);
            }
            subStr.insert(s[right]);
            len=max(len,right-left+1);
        }
        return len;
    }
};
