class Solution {
public:
    priority_queue<pair<int,int>>heap;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        vector<int>result;
        for(int right=0;right<n;right++){
           heap.push({nums[right],right});

           while(!heap.empty() && heap.top().second<=right-k){
            heap.pop();
           }
           if(right>=k-1){
            result.push_back(heap.top().first);
           }
        }
        return result;
    }
};
