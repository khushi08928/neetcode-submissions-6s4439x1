class Solution {
void getallsubset(vector<int>& nums,vector<int> &ans,int i,vector<vector<int>>& allsubset){
    int n=nums.size();
    if(i==n){
        allsubset.push_back({ans});
        return;
    }
    //include call
    ans.push_back(nums[i]);
    getallsubset(nums,ans,i+1,allsubset);
    ans.pop_back();
    //exclude call
    getallsubset(nums,ans,i+1,allsubset);
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>allsubset;
        getallsubset(nums,ans,0,allsubset);
        return allsubset;
    }
};
