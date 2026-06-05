class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int remaining_El=target-nums[i];
            if(mpp.find(remaining_El)!=mpp.end()){
                return {mpp[remaining_El],i};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};
