class Solution {
private:
    void getuniquesubset(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>& allsubset){
        int n=nums.size();
        if(i==n){
            allsubset.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        getuniquesubset(nums,ans,i+1,allsubset);
        ans.pop_back();
        //exclude call
        int index=i+1;
        while(index<n && nums[index]==nums[index-1]){
            index++;
        }
        getuniquesubset(nums,ans,index,allsubset);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<vector<int>>allsubset;
        getuniquesubset(nums,ans,0,allsubset);
        return allsubset;
    }
};
