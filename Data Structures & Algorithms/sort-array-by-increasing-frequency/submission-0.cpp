class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        vector<int> result;
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        for(auto& it:mpp){
            heap.push({it.second, -it.first}); 
        }
        while(!heap.empty()){
            auto top=heap.top();
            heap.pop();
            int freq=top.first;
            int val=-top.second;
            for(int i=0;i<freq;i++){
                result.push_back(val);
            }
        }
        return result;
    }
};