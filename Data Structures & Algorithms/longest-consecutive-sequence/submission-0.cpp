class Solution {
private:
    bool linearSearch(vector<int>& nums,int num){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num){
                return true;
            }
        }
        return false;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int maxcount=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int count=1;
            while(linearSearch(nums,x+1)){
                x=x+1;
                count++;
            }
            maxcount=max(count,maxcount);
        }
        return maxcount;
    }
};
