class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>result;
        int n=nums.size();
        vector<int>bucket[n+1];
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto &it:mpp){
            bucket[it.second].push_back(it.first);
        }
        for(int i=n;i>=0 && result.size()<k;i--){
            for(auto num : bucket[i]){
                result.push_back(num);
                if(result.size()==k) break;
            }
        }
        return result;
    }
};
