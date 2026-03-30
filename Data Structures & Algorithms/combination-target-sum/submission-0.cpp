class Solution {
private:
    void getallcombinations(vector<int>& nums,int i,vector<int>& combination,int target,vector<vector<int>>& allcombinations){
        int n=nums.size();
        if(i==n || target<0){
            return;
        }
        if(target==0){
            if(st.find(combination)==st.end()){
                allcombinations.push_back(combination);
                st.insert(combination);
            }
            return;
        }
        combination.push_back(nums[i]);
        //single include
        getallcombinations(nums,i+1,combination,target-nums[i],allcombinations);
        //multiple include
        getallcombinations(nums,i,combination,target-nums[i],allcombinations);
        //backtracking step
        combination.pop_back();
        //exclude
        getallcombinations(nums,i+1,combination,target,allcombinations);
    }
public:
    set<vector<int>>st;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>combination;
        vector<vector<int>>allcombinations;
        getallcombinations(nums,0,combination,target,allcombinations);
        return allcombinations;
    }
};
