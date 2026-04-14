class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalpoints=0;
        int n=cardPoints.size();
        for(int i=0;i<n;i++){
            totalpoints+=cardPoints[i];
        }
        if(k==n) return totalpoints;
        int left=0;
        int ans=0;
        int windowSize=n-k;
        int sum=0; 
        for(int right=0;right<n;right++){
            sum+=cardPoints[right];
            int window_size=right-left+1;
            while(window_size>windowSize){
                sum-=cardPoints[left];
                left++;
                window_size=right-left+1;
            }
            if(window_size==windowSize){
                ans=max(ans,totalpoints-sum);
                window_size=right-left+1;
            }
        }
        return ans;
    }
};