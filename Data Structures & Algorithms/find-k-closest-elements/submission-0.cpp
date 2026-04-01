class Solution {
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>result;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int ans=abs(arr[i]-x);
            heap.push({ans,arr[i]});
        }
        while(result.size()!=k){
            int val=heap.top().second;
            heap.pop();
            result.push_back(val);
        }
        sort(result.begin(),result.end());  
        return result;
    }
};