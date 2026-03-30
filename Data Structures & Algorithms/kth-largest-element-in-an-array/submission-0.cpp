class Solution {
public:
    priority_queue<int,vector<int>,greater<int>>heap;
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            heap.push(nums[i]);
            if(heap.size()>k){
                heap.pop();
                continue;
            }
        }
        return heap.top();
    }
};
