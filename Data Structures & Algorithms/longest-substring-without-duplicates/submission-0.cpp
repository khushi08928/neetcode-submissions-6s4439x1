class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int left=0;
        int maxlen=0;
        unordered_map<char,int>mpp;
        for(int right=0;right<n;right++){
            while(mpp.find(s[right])!=mpp.end() && (left<n)){
                mpp.erase(s[left]);
                left++;
                int len=right-left+1;
                maxlen=max(len,maxlen);
            }
            mpp[s[right]]++;
            int len=right-left+1;
            maxlen=max(len,maxlen);
        }
        return maxlen;
    }
};
