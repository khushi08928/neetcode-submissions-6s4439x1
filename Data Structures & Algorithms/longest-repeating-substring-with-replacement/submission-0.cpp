class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int n=s.length();
        int maxfreq=0;
        int ans=0;
        unordered_map<char,int>mpp;
        for(int right=0;right<n;right++){
            mpp[s[right]]++;
            maxfreq=max(maxfreq,mpp[s[right]]);
            int window_size=right-left+1;
            while(window_size-maxfreq>k){
                mpp[s[left]]--;
                left++;
                window_size=right-left+1;
            }
            ans=max(ans,window_size);
        }
        return ans;
    }
};
