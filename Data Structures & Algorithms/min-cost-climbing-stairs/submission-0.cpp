class Solution {
private:
    int findmincost(int i,vector<int>&cost,vector<int>&dp,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(findmincost(i+1,cost,dp,n),findmincost(i+2,cost,dp,n));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        int ans=min(findmincost(0,cost,dp,n),findmincost(1,cost,dp,n));
        return ans;
    }
};
