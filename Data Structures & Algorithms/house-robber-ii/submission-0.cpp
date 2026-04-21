class Solution {
private:
    int findmaxamount(int i, int end, vector<int>& nums, vector<int>& dp){
        if(i>end) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+findmaxamount(i+2,end,nums,dp),findmaxamount(i + 1,end,nums,dp));
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        //skip house n-1 and take house 0
        vector<int>dp1(n,-1);
        int case1 = findmaxamount(0, n - 2, nums, dp1);
        //skip house 0 and take house n-1
        vector<int> dp2(n, -1);
        int case2 = findmaxamount(1, n - 1, nums, dp2);
        int ans=max(case1,case2);
        return ans;
    }
};