/*
at each step(i) I have two choices , one is rob house i and another is 
skip house i
*/

class Solution {
private:
    int findmaxamount(int i,vector<int>&nums,vector<int>&dp,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+findmaxamount(i+2,nums,dp,n),findmaxamount(i+1,nums,dp,n));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=max(nums[0]+findmaxamount(0+2,nums,dp,n),findmaxamount(0+1,nums,dp,n));
        return ans;
    }
};
