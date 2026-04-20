class Solution {
public:
    int findways(int n,vector<int>&dp){
        if(n==1) return 1;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int onestep=findways(n-1,dp);
        int twostep=findways(n-2,dp);
        return dp[n]=onestep+twostep;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=findways(n,dp);
        return ans;
    }
};
