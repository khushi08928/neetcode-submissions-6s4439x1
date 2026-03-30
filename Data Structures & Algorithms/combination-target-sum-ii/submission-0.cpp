class Solution {
private:
    void getallcombinations(vector<int>& nums,int start,vector<int>& combination,int target,vector<vector<int>>& allcombinations){
        int n=nums.size();
        if(target==0){
            allcombinations.push_back({combination});
            return;
        }
        for(int i=start;i<n;i++){
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>target){
                break;
            }
            combination.push_back(nums[i]);
            getallcombinations(nums,i+1,combination,target-nums[i],allcombinations);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>combination;
        vector<vector<int>>allcombinations;
        getallcombinations(nums,0,combination,target,allcombinations);
        return allcombinations;
    }
};
