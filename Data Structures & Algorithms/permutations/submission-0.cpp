class Solution {
private:
    void getpermutation(vector<int>& nums,int index,vector<vector<int>>& ans){
        int n=nums.size();
        if(index==n){
            ans.push_back({nums});
            return;
        }
        for(int i=index;i<n;i++){
            swap(nums[index],nums[i]);
            getpermutation(nums,index+1,ans);
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        getpermutation(nums,0,ans);
        return ans;
    }
};
