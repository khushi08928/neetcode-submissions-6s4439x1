class Solution {
public:
    bool isMonotonic(vector<int>& nums){
        int n=nums.size();
        bool monotoneInc=true;
        bool monotoneDec=true;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                monotoneDec=false;
            }
            if(nums[i]<nums[i-1]){
                monotoneInc=false;
            }
        }
        return monotoneInc || monotoneDec;
    }
};