class Solution {
public:
    priority_queue<int,vector<int>,greater<int>>heap;
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            heap.push(nums[i]);
        }
        vector<int>ans;
        while(!heap.empty()){
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans;
    }
};