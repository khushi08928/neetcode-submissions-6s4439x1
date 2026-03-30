class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>heap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            heap.push(nums[i]);
        }
        int i=0;
        while(!heap.empty()){
            nums[i++]=heap.top();
            heap.pop();
        }
    }
};