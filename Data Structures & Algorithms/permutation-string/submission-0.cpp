class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int left=0;
        int counts1[26]={0};
        for(int i=0;i<n;i++){
            counts1[s1[i]-'a']++;
        }
        int counts2[26]={0};
        for(int right=0;right<m;right++){
            counts2[s2[right]-'a']++;
            int window_size=right-left+1;
            if(window_size>n){
                counts2[s2[left]-'a']--;
                left++;
                window_size=right-left+1;
            }
            if(window_size==n){
                bool match=true;
                for(int i=0;i<26;i++){
                    if(counts1[i]!=counts2[i]){
                        match=false;
                        break;
                    }
                }
                if(match==true) return true;
            }
        }
        return false;
    }
};
