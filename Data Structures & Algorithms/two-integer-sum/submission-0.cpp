class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int remainingEl=target-nums[i];
            if(mpp.find(remainingEl)!=mpp.end()){
                return {mpp[remainingEl],i};
        }
            mpp[nums[i]]=i;
        }
        return {};
    }
};
